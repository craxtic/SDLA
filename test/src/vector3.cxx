#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <axim/core/types/vector3.h>

using namespace axm;

TEST_CASE("init"){
  vec3i v;
  REQUIRE((v.x == 0 && v.y == 0 && v.z == 0));
  
  vec3f u(2.4f, 2.99f, 5.6f);
  REQUIRE((u.x == 2.4f && u.y == 2.99f && u.z == 5.6f));
}

TEST_CASE("operations"){
  
  REQUIRE(vec3i(3, 8, 2) == vec3i(3, 8, 2));
  REQUIRE(vec3i(3, 8, 9) != vec3i(3, 9, 0));
  
  vec3i a(3, 4, -6);
  vec3i b(3, -2, 5);

  REQUIRE(a + b  == vec3i(6, 2, -1));
  REQUIRE(a - b == vec3i(0, 6, -11));
  REQUIRE(a * b == -29);
  REQUIRE(a * 2 == vec3i(6, 8, -12));
  REQUIRE(2 * a == vec3i(6, 8, -12));
  REQUIRE(a / 2 == vec3i(1, 2, -3));
  a += b;
  REQUIRE(a == vec3i(6, 2, -1));
  a -= b;
  REQUIRE(a == vec3i(3, 4, -6));
  a *= 2;
  REQUIRE(a == vec3i(6, 8, -12));
  a /= 2;
  REQUIRE(a == vec3i(3, 4, -6));

  a = vec3i(1, 4, 8);
  REQUIRE(a.norm() == 9);

  REQUIRE(a.squared() == 81);

  vec3f v(3, 0, 4);
  REQUIRE(v.unit() == vec3f(0.6, 0, 0.8));


}
