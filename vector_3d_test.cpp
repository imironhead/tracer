#include "catch.hpp"

#include "vector_3d.hpp"


TEST_CASE("operators", "[Vector3D]") {
  SECTION("operator== and operator!=") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(0.0f, 3.0f, 1.0f);

    REQUIRE(u == u);
    REQUIRE(u != v);
  }

  SECTION("operator sign") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(0.0f, 3.0f, 1.0f);
    Vector3D w(-u.x_, -u.y_, -u.z_);

    REQUIRE(u == +u);
    REQUIRE(u == -w);
  }

  SECTION("operator+") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(0.0f, 3.0f, 1.0f);
    Vector3D w(u.x_ + v.x_, u.y_ + v.y_, u.z_ + v.z_);

    REQUIRE(u + v == w);
  }

  SECTION("operator-") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(0.0f, 3.0f, 1.0f);
    Vector3D w(u.x_ - v.x_, u.y_ - v.y_, u.z_ - v.z_);

    REQUIRE(u - v == w);
  }

  SECTION("operator*") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(0.0f, 3.0f, 1.0f);
    Vector3D w(u.x_ * v.x_, u.y_ * v.y_, u.z_ * v.z_);

    REQUIRE(u * v == w);
  }

  SECTION("operator/") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(2.0f, 3.0f, 1.0f);
    Vector3D w(u.x_ / v.x_, u.y_ / v.y_, u.z_ / v.z_);

    REQUIRE(u / v == w);
  }

  SECTION("operator+=") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(0.0f, 3.0f, 1.0f);
    Vector3D w(u.x_ + v.x_, u.y_ + v.y_, u.z_ + v.z_);

    u += v;

    REQUIRE(u == w);
  }

  SECTION("operator-=") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(0.0f, 3.0f, 1.0f);
    Vector3D w(u.x_ - v.x_, u.y_ - v.y_, u.z_ - v.z_);

    u -= v;

    REQUIRE(u == w);
  }

  SECTION("operator*=") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(0.0f, 3.0f, 1.0f);
    Vector3D w(u.x_ * v.x_, u.y_ * v.y_, u.z_ * v.z_);

    u *= v;

    REQUIRE(u == w);
  }

  SECTION("operator/=") {
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D v(2.0f, 3.0f, 1.0f);
    Vector3D w(u.x_ / v.x_, u.y_ / v.y_, u.z_ / v.z_);

    u /= v;

    REQUIRE(u == w);
  }

  SECTION("operator+= scalar") {
    float scalar = 2.0f;
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D w(u.x_ + scalar, u.y_ + scalar, u.z_ + scalar);

    u += scalar;

    REQUIRE(u == w);
  }

  SECTION("operator-= scalar") {
    float scalar = 2.0f;
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D w(u.x_ - scalar, u.y_ - scalar, u.z_ - scalar);

    u -= scalar;

    REQUIRE(u == w);
  }

  SECTION("operator*= scalar") {
    float scalar = 2.0f;
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D w(u.x_ * scalar, u.y_ * scalar, u.z_ * scalar);

    u *= scalar;

    REQUIRE(u == w);
  }

  SECTION("operator/= scalar") {
    float scalar = 2.0f;
    Vector3D u(1.0f, 3.0f, 0.0f);
    Vector3D w(u.x_ / scalar, u.y_ / scalar, u.z_ / scalar);

    u /= scalar;

    REQUIRE(u == w);
  }

  SECTION("operator[] const") {
    Vector3D u(1.0f, 2.0f, 3.0f);

    REQUIRE(u[0] == 1.0f);
    REQUIRE(u[1] == 2.0f);
    REQUIRE(u[2] == 3.0f);
  }

  SECTION("operator[]") {
    Vector3D u(1.0f, 2.0f, 3.0f);

    u[0] = 0.0f;
    u[1] = 1.0f;
    u[2] = 2.0f;

    REQUIRE(u.x_ == 0.0f);
    REQUIRE(u.y_ == 1.0f);
    REQUIRE(u.z_ == 2.0f);
  }
}

TEST_CASE("Product", "[Vector3D]") {
  Vector3D u(1.0f, 2.0f, 3.0f);
  Vector3D v(2.0f, 3.0f, 4.0f);

  SECTION("cross product") {
    auto w = u.Cross(v);

    REQUIRE_THAT(w.Dot(u), Catch::WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(w.Dot(v), Catch::WithinAbs(0.0f, 0.0001f));
  }

  SECTION("inner product") {
    float dot = u.x_ * v.x_ + u.y_ * v.y_ + u.z_ * v.z_;

    REQUIRE_THAT(u.Dot(v), Catch::WithinAbs(dot, 0.0001f));
    REQUIRE_THAT(v.Dot(u), Catch::WithinAbs(dot, 0.0001f));
  }

  SECTION("inner product") {
    REQUIRE_THAT(u.Dot(u), Catch::WithinAbs(u.LengthSquare(), 0.0001f));
  }
}

TEST_CASE("length", "[Vector3D]") {
  REQUIRE_THAT(
      Vector3D(1.0f, 2.0f, 2.0f).Length(),
      Catch::WithinAbs(3.0f, 0.0001f));

  REQUIRE_THAT(
      Vector3D(1.0f, 2.0f, 2.0f).LengthSquare(),
      Catch::WithinAbs(9.0f, 0.0001f));

  REQUIRE_THAT(
      Vector3D(1.0f, 2.0f, 2.0f).Normalize().Length(),
      Catch::WithinAbs(1.0f, 0.0001f));

  REQUIRE_THAT(
      Vector3D(1.0f, 2.0f, 2.0f).Normalized().Length(),
      Catch::WithinAbs(1.0f, 0.0001f));
}
