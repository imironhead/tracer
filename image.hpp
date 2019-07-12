#ifndef __TRACER_IMAGE_H__
#define __TRACER_IMAGE_H__

#include <algorithm>
#include <vector>
#include "vector_3d.hpp"


class Image {
  private:
    int32_t               height_;
    int32_t               width_;
    std::vector<Vector3D> pixels_;

  public:
    Image(int32_t height, int32_t width)
        : pixels_(height * width, Vector3D(0.0f, 0.0f, 0.0f)),
          height_(height),
          width_(width) {
    }

    int32_t Height() const { return this->height_; }
    int32_t Width() const { return this->width_; }
    void Fill(const Vector3D& color);
    void SaveAsBmp(const char* path) const;
};

inline void Image::Fill(const Vector3D& color) {
  std::fill(this->pixels_.begin(), this->pixels_.end(), color);
}

#endif

