#ifndef __TRACER_VECTOR_3D_H__
#define __TRACER_VECTOR_3D_H__


class Vector3D {
public:
    union { float x_, r_; };
    union { float y_, g_; };
    union { float z_, b_; };

public:
    Vector3D() : x_(0.0f), y_(0.0f), z_(0.0f) {}
    Vector3D(float x, float y, float z) : x_(x), y_(y), z_(z) {}
};

typedef Vector3D Color3D;

#endif
