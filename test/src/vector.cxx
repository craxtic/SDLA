#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <axim/core/types/vector2.h>

using namespace axm;

vec2f v(3, 4);
vec2f u(6, 8);

TEST_CASE("test correction") {
  REQUIRE(v.norm() == 5 );
  REQUIRE(u.norm() == 10);  
}


TEST_CASE(){
  BENCHMARK("norm"){
    return v.norm();
  };
}

TEST_CASE(){
  BENCHMARK("unit"){
    return v.unit();
  };
}