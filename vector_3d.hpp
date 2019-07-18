#ifndef __TRACER_VECTOR_3D_H__
#define __TRACER_VECTOR_3D_H__

#include <cmath>


class Vector3D {
public:
    union { float x_, r_; };
    union { float y_, g_; };
    union { float z_, b_; };

public:
    Vector3D() : x_(0.0f), y_(0.0f), z_(0.0f) {}
    Vector3D(float x, float y, float z) : x_(x), y_(y), z_(z) {}

    bool operator==(const Vector3D& that) const;
    bool operator!=(const Vector3D& that) const;

    Vector3D operator+() const;
    Vector3D operator-() const;
    Vector3D operator+(const Vector3D& that) const;
    Vector3D operator-(const Vector3D& that) const;
    Vector3D operator*(const Vector3D& that) const;
    Vector3D operator/(const Vector3D& that) const;
    void operator+=(const Vector3D& that);
    void operator-=(const Vector3D& that);
    void operator*=(const Vector3D& that);
    void operator/=(const Vector3D& that);
    void operator+=(const float s);
    void operator-=(const float s);
    void operator*=(const float s);
    void operator/=(const float s);

    float operator[](int32_t index) const;
    float& operator[](int32_t index);

    Vector3D Cross(const Vector3D& that) const;
    float Dot(const Vector3D& that) const;
    float Length() const;
    float LengthSquare() const;

    Vector3D& Normalize();
    Vector3D Normalized() const;
};

typedef Vector3D Color3D;

inline bool Vector3D::operator==(const Vector3D& that) const {
  return this->x_ == that.x_ && this->y_ == that.y_ && this->z_ == that.z_;
}

inline bool Vector3D::operator!=(const Vector3D& that) const {
  return this->x_ != that.x_ || this->y_ != that.y_ || this->z_ != that.z_;
}

inline Vector3D Vector3D::operator+() const {
  return *this;
}

inline Vector3D Vector3D::operator-() const {
  return Vector3D(-this->x_, -this->y_, -this->z_);
}

inline Vector3D Vector3D::operator+(const Vector3D& that) const {
  return Vector3D(this->x_ + that.x_, this->y_ + that.y_, this->z_ + that.z_);
}

inline Vector3D Vector3D::operator-(const Vector3D& that) const {
  return Vector3D(this->x_ - that.x_, this->y_ - that.y_, this->z_ - that.z_);
}

inline Vector3D Vector3D::operator*(const Vector3D& that) const {
  return Vector3D(this->x_ * that.x_, this->y_ * that.y_, this->z_ * that.z_);
}

inline Vector3D Vector3D::operator/(const Vector3D& that) const {
  return Vector3D(this->x_ / that.x_, this->y_ / that.y_, this->z_ / that.z_);
}

inline void Vector3D::operator+=(const Vector3D& that) {
  this->x_ += that.x_;
  this->y_ += that.y_;
  this->z_ += that.z_;
}

inline void Vector3D::operator-=(const Vector3D& that) {
  this->x_ -= that.x_;
  this->y_ -= that.y_;
  this->z_ -= that.z_;
}

inline void Vector3D::operator*=(const Vector3D& that) {
  this->x_ *= that.x_;
  this->y_ *= that.y_;
  this->z_ *= that.z_;
}

inline void Vector3D::operator/=(const Vector3D& that) {
  this->x_ /= that.x_;
  this->y_ /= that.y_;
  this->z_ /= that.z_;
}

inline void Vector3D::operator+=(const float s) {
  this->x_ += s;
  this->y_ += s;
  this->z_ += s;
}

inline void Vector3D::operator-=(const float s) {
  this->x_ -= s;
  this->y_ -= s;
  this->z_ -= s;
}

inline void Vector3D::operator*=(const float s) {
  this->x_ *= s;
  this->y_ *= s;
  this->z_ *= s;
}

inline void Vector3D::operator/=(const float s) {
  this->x_ /= s;
  this->y_ /= s;
  this->z_ /= s;
}

inline float Vector3D::operator[](int32_t index) const {
  return reinterpret_cast<const float*>(this)[index];
}

inline float& Vector3D::operator[](int32_t index) {
  return reinterpret_cast<float*>(this)[index];
}

inline Vector3D Vector3D::Cross(const Vector3D& that) const {
  return Vector3D(
      this->y_ * that.z_ - this->z_ * that.y_,
      this->z_ * that.x_ - this->x_ * that.z_,
      this->x_ * that.y_ - this->y_ * that.x_);
}

inline float Vector3D::Dot(const Vector3D& that) const {
  return this->x_ * that.x_ + this->y_ * that.y_ + this->z_ * that.z_;
}

inline float Vector3D::Length() const {
  return std::sqrt(
      this->x_ * this->x_ + this->y_ * this->y_ + this->z_ * this->z_);
}

inline float Vector3D::LengthSquare() const {
  return this->x_ * this->x_ + this->y_ * this->y_ + this->z_ * this->z_;
}

inline Vector3D& Vector3D::Normalize() {
  auto s = 1.0f / this->Length();

  this->x_ *= s;
  this->y_ *= s;
  this->z_ *= s;

  return *this;
}

inline Vector3D Vector3D::Normalized() const {
  auto s = 1.0f / this->Length();

  return Vector3D(this->x_ * s, this->y_ * s, this->z_ * s);
}

#endif
