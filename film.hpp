#ifndef __TRACER_FILM_H__
#define __TRACER_FILM_H__

#include <algorithm>
#include <cassert>
#include <vector>

#include "vec.hpp"


class Film {
    std::vector<std::vector<Vec3>>  pixels;

public:
    Film(uint32_t width, uint32_t height) :
            pixels(height, std::vector<Vec3>(width)) {
        assert(width > 0 && height > 0);
    }

    uint32_t width() const {
        return static_cast<uint32_t>(this->pixels[0].size());
    }

    uint32_t height() const {
        return static_cast<uint32_t>(this->pixels.size());
    }

    void fill(const Vec3& color);
    void fill(const Vec3& ul, const Vec3& ur, const Vec3& bl, const Vec3& br);
    void fill(uint32_t x, uint32_t y, const Vec3& color);

    void save_bmp(const char* path, float gamma) const;
};

#endif

