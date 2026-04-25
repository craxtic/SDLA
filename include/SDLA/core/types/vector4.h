#pragma once

#include <SDLA/core/types/vector.h>

namespace SDLA {

template <typename T> struct vec<4, T> {

  union {
    T data[4]{};
    struct {
      T x, y, z, w;
    };
    struct {
      T r, g, b, a;
    };
  };

  constexpr vec() = default;
  
  
  constexpr vec(T x, T y, T z, T w){
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
  }


  /// vec[i]
  [[nodiscard]] constexpr T& operator[](int i) { return data[i]; }
  [[nodiscard]] constexpr const T& operator[](int i) const { return data[i]; }


  /// \brief norm of vector |v|
  [[nodiscard]] constexpr T norm() const {
    return sqrt(x*x + y*y + z*z + w*w);
  }

  /// square of vector's norm 
  /// General property of Euclidean vector:  vector v^2 = norm |v|^2
  [[nodiscard]] constexpr T squared() const{
    return x*x + y*y + z*z + w*w;
  }


  /// return a normal (perpendicular) vector of this*
  // [[nodiscard]] constexpr vec<2, T> normal() const{
  //   return vec<2, T>(-y, x);
  // }

  /// return a unit vector of this*
  [[nodiscard]] constexpr vec<4, T> unit() const{
    T norm = this->norm();
    return  vec<4, T>(x/norm, y/norm, z/norm, w/norm);
  }

};



template<typename T> using vec4 = vec<4, T>;
using vec4i = vec4<int>;
using vec4f = vec4<float>;


} 
