#ifndef __TRACER_MATH_RAY_H__
#define __TRACER_MATH_RAY_H__

#include "vec.hpp"


class Ray {
public:
    Vec3    origin;
    Vec3    direction;

public:
    Ray() {}
    Ray(const Vec3& o, const Vec3& d) : origin(o), direction(d) {}

    Vec3 position_at_time(float t) const {
        return this->origin + t * this->direction;
    }
};

#endif

