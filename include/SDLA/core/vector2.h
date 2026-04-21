#pragma once

#include <SDLA/core/vector.h>

namespace SDLA {

template <typename T> struct vec<2, T> {

  union {
    T data[2];
    struct {
      T x{}, y{};
    };
  };
  
  constexpr vec() = default;
  
  constexpr vec(T x, T y){
    this->x = x;
    this->y = y;
  }

  /// vec[i]
  [[nodiscard]] constexpr T& operator[](int i) { return data[i]; }
  [[nodiscard]] constexpr const T& operator[](int i) const { return data[i]; }


  /// \brief norm of vector |v|
  [[nodiscard]] constexpr T norm() const {
    return sqrt(x * x + y * y);
  }

  /// square of vector's norm 
  /// General property of Euclidean vector:  vector v^2 = norm |v|^2
  [[nodiscard]] constexpr T squared() const{
    return x * x + y * y;
  }


  /// return a normal (perpendicular) vector of this*
  [[nodiscard]] constexpr vec<2, T> normal() const{
    return vec<2, T>(-y, x);
  }

  /// return a unit vector of this*
  [[nodiscard]] constexpr vec<2, T> unit() const{
    T norm = this->norm();
    return  vec<2, T>(x/norm, y/norm);
  }

};



template<typename T> using vec2 = vec<2, T>; 
using vec2i = vec2<int>;
using vec2u = vec2<unsigned int>;
using vec2f = vec2<float>;


} 
