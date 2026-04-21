#pragma once

#include <cmath>
#include <cstddef>
#include <ostream>

#include <SDLA/config.h>
#include <SDLA/core/ctype.h>
#include <SDLA/core/utils.h>

namespace SDLA {

/// vector<dimention, type>

template <int D, typename T> struct vec {

  T data[D];

  /// vec[i]
  [[nodiscard]] constexpr T &operator[](int i) { return data[i]; }
  [[nodiscard]] constexpr const T &operator[](int i) const { return data[i]; }
};


/////////////
// maths operations (operator overloads)
//
////////////////


/// -v()
/// negate each component
template <int D, typename T>
[[nodiscard]] constexpr vec<D, T> operator-(const vec<D, T> &v) {
  vec<D, T> u;
  static_loop_unroll<D>([&](auto i){
    u[i] = -v[i];
  });
  return u;
}

/// v() + u()
template <int D, typename T>
[[nodiscard]] constexpr vec<D, T> operator+(const vec<D, T> &v, const vec<D, T> &u) {
  vec<D, T> w;
  static_loop_unroll<D>([&](auto i){
    w[i] = v[i] + u[i];
  });
 
  return w;
}

/// v() - u()
template <int D, typename T>
[[nodiscard]] constexpr vec<D, T> operator-(const vec<D, T> &v, const vec<D, T> &u) {
  vec<D, T> w;
  static_loop_unroll<D>([&](auto i){
    w[i] = v[i] - u[i];
  });
  return w;
}

/// v() * k
template <int D, typename T>
[[nodiscard]] constexpr vec<D, T> operator*(const vec<D, T> &v, T k) {
  vec<D, T> w;
  static_loop_unroll<D>([&](auto i){
    w[i] = v[i] * k;
  });
  return w;
}

/// k * v()
template <int D, typename T>
[[nodiscard]] constexpr vec<D, T> operator*(T k, const vec<D, T> &v) {
  vec<D, T> w;
  static_loop_unroll<D>([&](auto i){
    w[i] = v[i] * k;
  });
  return w;
}

/// v() / k
template <int D, typename T>
[[nodiscard]] constexpr vec<D, T> operator/(const vec<D, T> &v, T k) {
  vec<D, T> w;
  static_loop_unroll<D>([&](auto i){
    w[i] = v[i] / k;
  });
  return w;
}

/// v() == u()
template <int D, typename T>
[[nodiscard]] constexpr bool operator==(const vec<D, T> &v, const vec<D, T> &u) {
  static_loop_unroll<D>([&](auto i){
    if (v[i] != u[i]) return false;
  });
  return true;  
}

/// v() != u()
template <int D, typename T>
[[nodiscard]] constexpr bool operator!=(const vec<D, T> &v, const vec<D, T> &u) {
  static_loop_unroll<D>([&](auto i){
    if(v[i] != u[i]) return true;
  });  
  return false; 
}

/// v() += u()
template <int D, typename T>
constexpr vec<D, T>& operator+=(vec<D, T> &v, const vec<D, T> &u) {
  static_loop_unroll<D>([&](auto i){
    v[i] += u[i];
  });  
  return v;
}

/// v() -= u()
template <int D, typename T>
constexpr vec<D, T>& operator-=(vec<D, T> &v, const vec<D, T> &u) {
  static_loop_unroll<D>([&](auto i){
    v[i] -= u[i];
  });
  return v;
}



/// dot product * \
/// note: we'll use ^ for vector cross product (french context)
template<int D, typename T>
constexpr T operator*(const vec<D, T> v, const vec<D, T> u){
  T result = 0;
  static_loop_unroll<D>([&](auto i){
    result += v[i] * u[i];
  });
  return result;
}





/// format into "(a, b, c, ...)"
template<int D, typename T> 
constexpr std::ostream& operator<<(std::ostream &stream, const vec<D, T> &v){
  stream << '(';
  static_loop_unroll<D-1>([&](auto i){
    stream << +v[i] << ',';
  });
  return stream << +v[D-1] <<')';
}





} // namespace SDLA



