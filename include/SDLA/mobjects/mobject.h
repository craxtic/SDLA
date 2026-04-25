#pragma once

#include <SDL3pp/SDL3pp_messagebox.h>
#include <include/core/SkPaint.h>
#include <memory>
#include <vector>

#include <SDLA/config.h>
#include <SDLA/core/types/color.h>
#include <SDLA/core/types/vector3.h>
#include <SDLA/mobjects/cloud.h>

#include <include/core/SkPath.h>

namespace SDLA {


/// Mathematical Object Class
class SDLA_API Mobject {

public:
  u32 id;  
  float z_index;

  Mobject(Color color = Color::White, float z_index = 0);
  
  ~Mobject();
  
  [[nodiscard]] virtual SkPath get_path() const;
  

  // deep copy on the points & metadata cloud with new id
  [[nodiscard]] constexpr Mobject copy() const;
  

  [[nodiscard]] inline constexpr vec3f &operator[](u32 index) const {
    return cloud.points[cloud.metadata[id].poindex + index];
  }

  [[nodiscard]] inline constexpr SkPaint &get_paint() const {
    return cloud.paints[cloud.metadata[id].paindex];
  }

  [[nodiscard]] inline constexpr u32 get_poindex() const {
    return cloud.metadata[id].poindex;
  }

  [[nodiscard]] inline constexpr u16 get_pocount() const {
    return cloud.metadata[id].pocount;
  }

  [[nodiscard]] inline constexpr u16 get_paindex() const {
    return cloud.metadata[id].paindex;
  }

  // virtual void generate_points() = 0;
  // Mobject add(const Mobject &mobject);
  


// protected:  
  // std::vector<std::shared_ptr<Mobject>> submobjects; 


};


}