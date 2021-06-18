#include "catch.hpp"

#include "ray.hpp"


TEST_CASE("PositionAtParameter", "[Ray]") {
  Ray ray(Vector3D(1.0, 2.0, 3.0), Vector3D(4.0f, 5.0f, 6.0f));

  auto position = ray.PositionAtParameter(2.0f);

  REQUIRE_THAT(position.x_, Catch::WithinAbs(9.0f, 0.0001f));
  REQUIRE_THAT(position.y_, Catch::WithinAbs(12.0f, 0.0001f));
  REQUIRE_THAT(position.z_, Catch::WithinAbs(15.0f, 0.0001f));
}
