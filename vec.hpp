#ifndef __TRACER_MATH_VEC_H__
#define __TRACER_MATH_VEC_H__

#include <cmath>

class Vec3 {
public:
    union { float x, r; };
    union { float y, g; };
    union { float z, b; };

public:
    Vec3() {}
    Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vec3(const Vec3& that) : x(that.x), y(that.y), z(that.z) {}

    Vec3 operator+() const { return *this; }
    Vec3 operator-() const { return Vec3(-this->x, -this->y, -this->z); }

    void operator+=(const Vec3& that) {
        this->x += that.x;
        this->y += that.y;
        this->z += that.z;
    }

    void operator-=(const Vec3& that) {
        this->x -= that.x;
        this->y -= that.y;
        this->z -= that.z;
    }

    void operator*=(const Vec3& that) {
        this->x *= that.x;
        this->y *= that.y;
        this->z *= that.z;
    }

    void operator/=(const Vec3& that) {
        this->x /= that.x;
        this->y /= that.y;
        this->z /= that.z;
    }

    void operator*=(float s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
    }

    void operator/=(float s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
    }

    void normalize() {
        (*this) /= this->length();
    }

    float length() const {
        return std::sqrt(
            this->x * this->x + this->y * this->y + this->z * this->z);
    }

    float length_squared() const {
        return this->x * this->x + this->y * this->y + this->z * this->z;
    }
};

inline Vec3 operator+(const Vec3& u, const Vec3& v) {
    return Vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline Vec3 operator-(const Vec3& u, const Vec3& v) {
    return Vec3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline Vec3 operator*(const Vec3& u, const Vec3& v) {
    return Vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline Vec3 operator/(const Vec3& u, const Vec3& v) {
    return Vec3(u.x / v.x, u.y / v.y, u.z / v.z);
}

inline Vec3 operator*(float s, const Vec3& v) {
    return Vec3(s * v.x, s * v.y, s * v.z);
}

inline Vec3 operator*(const Vec3& u, float s) {
    return Vec3(u.x * s, u.y * s, u.z * s);
}

inline Vec3 operator/(const Vec3& u, float s) {
    return Vec3(u.x / s, u.y / s, u.z / s);
}

inline float dot(const Vec3& u, const Vec3& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x);
}

inline Vec3 lerp(const Vec3& source, const Vec3& target, float f) {
    return (1.0f - f) * source + f * target;
}

#endif

