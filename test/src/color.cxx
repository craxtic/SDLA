#include <catch2/catch_test_macros.hpp>

#include <axim/core/types/color.h>

using namespace axm;

TEST_CASE("init"){
  Color c1;
  REQUIRE((c1.r == 0 && c1.g == 0 && c1.b == 0 && c1.a == 255));

  Color c2(100, 34, 26, 200);
  REQUIRE((c2.r == 100 && c2.g == 34 && c2.b == 26 && c2.a == 200));

  Color c3(0xfa4490ff);
  REQUIRE((c3.r == 0xfa && c3.g == 0x44 && c3.b == 0x90 && c3.a == 0xff));
}

TEST_CASE("operators"){
  Color c1(200, 200, 200, 200);
  Color c2(30, 40, 50, 60);
  Color c3(50, 40, 30, 20);

  REQUIRE(Color(0x112233ff) == Color(0x112233ff));
  REQUIRE(Color(0x112233ff) != Color(0x112233f0));
  REQUIRE(c1 + c2 == Color(230, 240, 250, 255));
  REQUIRE(c1 - c2 == Color(170, 160, 150, 140));
  REQUIRE(c2 - c3 == Color(0, 0, 20, 40));
}
