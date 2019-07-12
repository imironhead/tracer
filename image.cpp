#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "image.hpp"


inline uint8_t clamp_pixel(float value) {
  return static_cast<uint8_t>(std::clamp(value * 255.0f, 0.0f, 255.0f));
}

void Image::SaveAsBmp(const char* path) const {
  const auto stride = ((3 * this->width_ + 3) & 0xfffffffc);
  const auto size = this->height_ * stride;

  uint8_t header[54] = {0};

  header[0] = 'B';
  header[1] = 'M';

  *reinterpret_cast<uint32_t*>(header + 2) = 54 + size;
  *reinterpret_cast<uint32_t*>(header + 10) = 54;
  *reinterpret_cast<uint32_t*>(header + 14) = 40;
  *reinterpret_cast<uint32_t*>(header + 18) = this->width_;
  *reinterpret_cast<uint32_t*>(header + 22) = this->height_;
  *reinterpret_cast<uint16_t*>(header + 26) = 1;
  *reinterpret_cast<uint16_t*>(header + 28) = 24;

  std::vector<uint8_t> bitmap(this->height_ * stride);

  for (auto y = 0; y < this->height_; ++y) {
    auto iter_source_pixel = this->pixels_.begin() + y * this->width_;
    auto iter_result_pixel = bitmap.begin() + y * stride;

    for (auto x = 0; x < this->width_; ++x, ++iter_source_pixel) {
      *(iter_result_pixel++) = clamp_pixel(iter_source_pixel->b_);
      *(iter_result_pixel++) = clamp_pixel(iter_source_pixel->g_);
      *(iter_result_pixel++) = clamp_pixel(iter_source_pixel->r_);
    }
  }

  auto bmp_file = std::fstream(path, std::ios::out | std::ios::binary);

  bmp_file.write(reinterpret_cast<char*>(header), sizeof(header));
  bmp_file.write(reinterpret_cast<char*>(bitmap.data()), bitmap.size());
  bmp_file.close();
}
