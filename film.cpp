#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <vector>

#include "film.hpp"


void Film::fill(const Vec3& color) {
    for (auto& row : this->pixels) {
        std::fill(row.begin(), row.end(), color);
    }
}

void Film::fill(
        const Vec3& co_upper_left,
        const Vec3& co_upper_right,
        const Vec3& co_lower_left,
        const Vec3& co_lower_right) {
    const auto w = this->width();
    const auto h = this->height();

    // NOTE: change rate of fraction over x & y axes
    auto dy = 1.0f / static_cast<float>(h - 1);
    auto dx = 1.0f / static_cast<float>(w - 1);

    // NOTE: fractions of x-th column & y-th row
    auto fy = dy;
    auto fx = dx;

    // NOTE: colors of the begin and end of each row
    Vec3 co_left;
    Vec3 co_right;

    for (auto y = 0; y < h; ++y) {
        fy = dy * static_cast<float>(y);

        co_left = fy * co_lower_left + (1.0f - fy) * co_upper_left;
        co_right = fy * co_lower_right + (1.0f - fy) * co_upper_right;

        for (auto x = 0; x < w; ++x) {
            fx = dx * static_cast<float>(x);

            // NOTE: blend colors from 4 corners
            this->pixels[y][x] = fx * co_right + (1.0 - fx) * co_left;
        }
    }
}

void Film::save_bmp(const char* path, float gamma) const {
    const auto w = this->width();
    const auto h = this->height();

    // NOTE: must be multiple of 4
    const auto stride = ((w * 3 + 3) & 0xfffffffc);

    // NOTE: basic bmp file & info header
    std::array<uint8_t, 54> header;

    // NOTE: type
    header[0] = 'B';
    header[1] = 'M';

    // NOTE: file size
    *reinterpret_cast<uint32_t*>(&header[2]) = 54 + h * stride;

    // NOTE: distance from the beginning of the bmp file to the pixels
    *reinterpret_cast<uint32_t*>(&header[10]) = 54;

    // NOTE: size of info header
    *reinterpret_cast<uint32_t*>(&header[14]) = 40;

    // NOTE: width of the bmp
    *reinterpret_cast<uint32_t*>(&header[18]) = w;

    // NOTE: height of the bmp
    *reinterpret_cast<uint32_t*>(&header[22]) = h;

    // NOTE: number of planes
    *reinterpret_cast<uint16_t*>(&header[26]) = 1;

    // NOTE: depth
    *reinterpret_cast<uint16_t*>(&header[28]) = 24;

    // NOTE: no compression
    *reinterpret_cast<uint32_t*>(&header[30]) = 0;

    // NOTE: size of image, can be 0 if not compressed
    *reinterpret_cast<uint32_t*>(&header[34]) = 0;

    // NOTE: output to file
    std::ofstream bmp(path, std::ios::out | std::ios::binary);

    bmp.write(reinterpret_cast<char*>(header.data()), header.size());

    // NOTE: write rows
    std::vector<uint8_t> buffer(stride);

    for (auto y = this->pixels.rbegin(); y != this->pixels.rend(); ++y) {
        auto& row = *y;

        for (int x = 0, j = 0; x < w; ++x, j += 3) {
            buffer[j + 0] = static_cast<uint8_t>(y->at(x).b * 255.99f);
            buffer[j + 1] = static_cast<uint8_t>(y->at(x).g * 255.99f);
            buffer[j + 2] = static_cast<uint8_t>(y->at(x).r * 255.99f);
        }

        bmp.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
    }
}

void Film::fill(uint32_t x, uint32_t y, const Vec3& color) {
    const auto w = this->width();
    const auto h = this->height();

    assert(x < this->width() && y < this->height());

    this->pixels[y][x] = color;
}
