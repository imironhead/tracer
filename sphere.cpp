#include <cmath>

#include "sphere.hpp"
#include "vec.hpp"


bool Sphere::hit(
        const Ray& r,
        float min_time,
        float max_time,
        Hitable::Record& hit_record) const {
    // NOTE: solve a quadratic equation
    auto oc = r.origin - this->center;

    auto a = dot(r.direction, r.direction);
    auto b = dot(oc, r.direction);
    auto c = dot(oc, oc) - this->radius * this->radius;

    auto discriminant = b * b - a * c;

    // NOTE: no real number solutions
    if (discriminant <= 0.0) { return false; }

    // NOTE: check the nearer position first
    auto temp = (-b - std::sqrt(discriminant)) / a;

    if (min_time >= temp || temp >= max_time) {
        temp = (-b + std::sqrt(discriminant)) / a;
    }

    if (min_time < temp && temp < max_time) {
        hit_record.position = r.position_at_time(temp);
        hit_record.normal = (hit_record.position - this->center) / this->radius;
        hit_record.material_ptr = this->material_ptr;

        return true;
    }

    return false;
}

