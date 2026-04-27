#pragma once

#include <SDLA/core/types/vector.h>

namespace SDLA {

template <typename T> struct vec<3, T> {

  union {
    T data[3]{};
    struct {
      T x, y, z;
    };
    struct {
      T r, g, b;
    };
  };
  
  constexpr vec() = default;
  


  constexpr vec(T x, T y, T z){
    this->x = x;
    this->y = y;
    this->z = z;
  }


  /// vec[i]
  [[nodiscard]] constexpr T& operator[](int i) { return data[i]; }
  [[nodiscard]] constexpr const T& operator[](int i) const { return data[i]; }


  /// \brief norm of vector |v|
  [[nodiscard]] constexpr T norm() const {
    return sqrt(x * x + y * y + z * z);
  }

  /// square of vector's norm 
  /// General property of Euclidean vector:  vector v^2 = norm |v|^2
  [[nodiscard]] constexpr T squared() const{
    return x * x + y * y + z * z;
  }


  /// return a normal (perpendicular) vector of this*
  // [[nodiscard]] constexpr vec<2, T> normal() const{
  //   return vec<2, T>(-y, x);
  // }

  /// return a unit vector of this*
  [[nodiscard]] constexpr vec<3, T> unit() const{
    T norm = this->norm();
    return  vec<3, T>(x/norm, y/norm, z/norm);
  }


  /// convert to SkPoint
  


};



template<typename T> using vec3 = vec<3, T>;
using vec3i = vec3<int>;
using vec3f = vec3<float>;


} 
