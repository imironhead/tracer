#include "catch.hpp"

#include "hitable.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "vector_3d.hpp"


TEST_CASE("Hit", "[Sphere]") {
  Sphere sphere(Vector3D(0.0f, 0.0f, 1.0f), 1.0f);

  SECTION("infinit time hit none outside") {
    Ray ray(Vector3D(0.0, 0.0, -1.0), Vector3D(0.0f, 1.0f, 0.0f));
    HitRecord record;

    REQUIRE_FALSE(sphere.Hit(ray, 0.0f, 1000.f, record));
  }

  SECTION("infinit time hit one outside") {
  }

  SECTION("infinit time hit two outside") {
    Ray ray(Vector3D(0.0, 0.0, -1.0), Vector3D(0.0f, 0.0f, 1.0f));
    HitRecord record;

    REQUIRE(sphere.Hit(ray, 0.0f, 1000.f, record));

    REQUIRE_THAT(record.time_, Catch::WithinAbs(1.0, 0.0001f));

    REQUIRE_THAT(record.position_.x_, Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(record.position_.y_, Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(record.position_.z_, Catch::WithinAbs(0.0f, 0.0001f));

    REQUIRE_THAT(record.normal_.x_, Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(record.normal_.y_, Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(record.normal_.z_, Catch::WithinAbs(-1.0f, 0.0001f));
  }

  SECTION("infinit time hit from inside") {
    Ray ray(Vector3D(0.0, 0.0, 1.0), Vector3D(0.0f, 0.0f, 1.0f));
    HitRecord record;

    REQUIRE(sphere.Hit(ray, 0.0f, 1000.f, record));

    REQUIRE_THAT(record.time_, Catch::WithinAbs(1.0, 0.0001f));

    REQUIRE_THAT(record.position_.x_, Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(record.position_.y_, Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(record.position_.z_, Catch::WithinAbs(2.0f, 0.0001f));

    /* FIXME
    REQUIRE_THAT(record.normal_.x_, Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(record.normal_.y_, Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(record.normal_.z_, Catch::WithinAbs(-1.0f, 0.0001f));
    */
  }

  SECTION("short time hit none outside") {
    Ray ray(Vector3D(0.0, 0.0, -1.0), Vector3D(0.0f, 0.0f, 1.0f));
    HitRecord record;

    REQUIRE_FALSE(sphere.Hit(ray, 0.0f, 0.1f, record));
  }

  SECTION("short time hit none inside") {
    Ray ray(Vector3D(0.0, 0.0, 1.0), Vector3D(0.0f, 0.0f, 1.0f));
    HitRecord record;

    REQUIRE_FALSE(sphere.Hit(ray, 0.0f, 0.1f, record));
  }
}
