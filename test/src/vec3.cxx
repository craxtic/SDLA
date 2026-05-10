#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <axim/core/types/vector3.h>

using namespace axm;

vec3f v(3, 4, 0);
vec3f u(6, 8, 0);

TEST_CASE("vec3 t") {
  REQUIRE(v.norm() == 5 );
  REQUIRE(u.norm() == 10);  
}


TEST_CASE("vec3 norm"){
  BENCHMARK("norm"){
    return v.norm();
  };
}

TEST_CASE("vec3 unit"){
  BENCHMARK("unit"){
    return v.unit();
  };
}