#pragma once


#include <axim/config.h>
#include <axim/utils/utils.h>
#include <axim/core/types/ctype.h>

#include <ostream>
#include <include/core/SkColor.h>

namespace axm {

// template <typename T>
struct Color {

  union {
    u8 data[4]{};
    struct {
      u8 r, g, b, a;
    };
  };


  constexpr Color() = default;

  constexpr Color(u8 r, u8 g, u8 b, u8 a = 255);

  constexpr explicit Color(u32 hex);


  [[nodiscard]] constexpr u8 &operator[](int i) { return data[i]; }
  [[nodiscard]] constexpr const u8 &operator[](int i) const { return data[i]; }


  // skia mapping
  [[nodiscard]] constexpr operator SkColor() const {
    return SkColorSetARGB(a, r, g, b);
  }


  static const Color Black;       // Black predefined color
  static const Color White;       // White predefined color
  static const Color Red;         // Red predefined color
  static const Color Green;       // Green predefined color
  static const Color Blue;        // Blue predefined color
  static const Color Yellow;      // Yellow predefined color
  static const Color Magenta;     // Magenta predefined color
  static const Color Cyan;        // Cyan predefined color
  static const Color Transparent; // Transparent (black) predefined color
  

};






constexpr Color::Color(u8 r, u8 g, u8 b, u8 a){
  data[0] = r;
  data[1] = g;
  data[2] = b;
  data[3] = a;
}

constexpr  Color::Color(u32 hex){
  data[0] = static_cast<u8>((hex & 0xff000000) >> 24);
  data[1] = static_cast<u8>((hex & 0x00ff0000) >> 16);
  data[2] = static_cast<u8>((hex & 0x0000ff00) >> 8 );
  data[3] = static_cast<u8>((hex & 0x000000ff) >> 0); 
}




/// v() + u()
[[nodiscard]] constexpr Color operator+(const Color &v, const Color &u) {
  Color w;
  static_loop_unroll<4>([&](auto i){
    int result = int{v[i]} + int{u[i]};
    w[i] = static_cast<u8>(result < 255 ? result : 255); 
  });
 
  return w;
}

/// v() - u()
[[nodiscard]] constexpr Color operator-(const Color &v, const Color &u) {
  Color w;
  static_loop_unroll<4>([&](auto i){
    int result = int{v[i]} - int{u[i]};
    w[i] = static_cast<u8>(result > 0 ? result : 0);
  });
  return w;
}

/// v() * k
[[nodiscard]] constexpr Color operator*(const Color &v, u8 k) {
  Color w;
  static_loop_unroll<4>([&](auto i){
    int result = int{v[i]} * k;
    w[i] = static_cast<u8>(result < 255 ? result : 255);
  });
  return w;
}

/// k * v()
[[nodiscard]] constexpr Color operator*(u8 k, const Color &v) {
  Color w;
  static_loop_unroll<4>([&](auto i){
    int result = int{v[i]} * k;
    w[i] = static_cast<u8>(result < 255 ? result : 255);
  });
  return w;
}

// / scalar multiplication * 
constexpr Color operator*(const Color v, const Color u){
  Color w;
  static_loop_unroll<4>([&](auto i){
    int result = v[i] * u[i];
    w[i] = static_cast<u8>(result < 255 ? result : 255); 
  });
  return w;
}

/// v() / k
[[nodiscard]] constexpr Color operator/(const Color &v, u8 k) {
  Color w;
  static_loop_unroll<4>([&](auto i){
    int result = int{v[i]} / k;
    // w[i] = static_cast<u8>(result < 255 ? result : 255);
  });
  return w;
}

/// v() == u()
[[nodiscard]] constexpr bool operator==(const Color &v, const Color &u) {
  return (v.r == u.r) && (v.g == u.g) && (v.b == u.b) && (v.a == u.a);  
}

/// v() != u()
[[nodiscard]] constexpr bool operator!=(const Color &v, const Color &u) {  
  return !(v == u); 
}

/// v() += u()
constexpr Color& operator+=(Color &v, const Color &u) {
  static_loop_unroll<4>([&](auto i){
    int result = int{v[i]} + int{u[i]};
    v[i] = static_cast<u8>(result < 255 ? result : 255);
  });  
  return v;
}

/// v() -= u()
constexpr Color& operator-=(Color &v, const Color &u) {
  static_loop_unroll<4>([&](auto i){
    int result = int{v[i]} - int{u[i]};
    v[i] = static_cast<u8>(result > 0 ? result : 0);
  });
  return v;
}



/// format into "(a, b, c, ...)"
inline std::ostream& operator<<(std::ostream &stream, const Color &v){
  stream << "Color(";
  static_loop_unroll<3>([&](auto i){
    stream << +v[i] << ',';
  });
  return stream << +v[3] <<')';
}


 
inline constexpr Color Color::Black(0, 0, 0);
inline constexpr Color Color::White(255, 255, 255);
inline constexpr Color Color::Red(255, 0, 0);
inline constexpr Color Color::Green(0, 255, 0);
inline constexpr Color Color::Blue(0, 0, 255);
inline constexpr Color Color::Yellow(255, 255, 0);
inline constexpr Color Color::Magenta(255, 0, 255);
inline constexpr Color Color::Cyan(0, 255, 255);
inline constexpr Color Color::Transparent(0, 0, 0, 0);




}



  