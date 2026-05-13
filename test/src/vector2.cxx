#include <catch2/catch_test_macros.hpp>

#include <axim/core/types/vector2.h>

using namespace axm;


TEST_CASE("init"){
  vec2f v;
  REQUIRE((v.x == 0 && v.y == 0));
  
  vec2f u(2.4f, 2.99f);
  REQUIRE((u.x == 2.4f && u.y == 2.99f));
}

TEST_CASE("operations"){
  
  REQUIRE(vec2f(3.4, 8) == vec2f(3.4, 8));
  REQUIRE(vec2f(3.4, 8) != vec2f(3.4, 8.2));
  
  vec2f a(3.5f, 4.5f);
  vec2f b(3.f, -2.f);

  REQUIRE(a + b == vec2f(6.5, 2.5));
  REQUIRE(a - b == vec2f(0.5, 6.5));
  REQUIRE(a * b == 1.5);
  REQUIRE(a * 2.f == vec2f(7, 9));
  REQUIRE(2.f * a == vec2f(7, 9));
  REQUIRE(a / 2.f == vec2f(1.75, 2.25));
  a += b;
  REQUIRE(a == vec2f(6.5, 2.5));
  a -= b;
  REQUIRE(a == vec2f(3.5, 4.5));
  a *= 2.f;
  REQUIRE(a == vec2f(7, 9));
  a /= 2.f;
  REQUIRE(a == vec2f(3.5, 4.5));

  a = vec2f(3, 4);
  REQUIRE(a.norm() == 5.f);

  REQUIRE(a.squared() == 25.f);

  REQUIRE(a.normal() == vec2f(-4, 3));
  
  REQUIRE(a.unit() == vec2f(0.6, 0.8));

}
