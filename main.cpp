#include "hitable.hpp"
#include "image.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "vector_3d.hpp"


int main() {
  Image image(100, 150);

  Sphere spheres[2];

  spheres[0].radius_ = 0.5;
  spheres[0].center_ = Vector3D(0.0f, 0.0f, -1.0f);
  spheres[1].radius_ = 100.0f;
  spheres[1].center_ = Vector3D(0.0f, -100.5f, -1.0f);

  for (auto y = 0; y < 100; ++y) {
    for (auto x = 0; x < 150; ++x) {
      auto u = float(x) / 150.0f;
      auto v = float(y) / 100.0f;

      Ray ray(
        Vector3D(0.0f, 0.0f, 0.0f),
        Vector3D(-1.5f, -1.0f, -1.0f) + Vector3D(3.0f, 0.0f, 0.0f) * u + Vector3D(0.0f, 2.0f, 0.0f) * v);

      HitRecord record;

      float time_max = 10000.0f;

      for (auto sphere : spheres) {
        if (sphere.Hit(ray, 0.0, time_max, record)) {
          image[y][x] = record.normal_;

          time_max = record.time_;
        }
      }
    }
  }

  image.SaveAsBmp("test.bmp");
}
