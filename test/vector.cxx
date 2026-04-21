#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <SDLA/core/vector2.h>

SDLA::vec2f v(3, 4);

TEST_CASE() {
  REQUIRE(v.norm() == 5 );
  REQUIRE(v.normal() == SDLA::vec2f(-4, 3));  
}

TEST_CASE(){
  BENCHMARK("norm"){
    float t = v.norm();
  };
}