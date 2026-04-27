#pragma once

#include <SDL3pp/SDL3pp_messagebox.h>
#include <include/core/SkPaint.h>
#include <include/core/SkPathBuilder.h>
#include <vector>
#include <iostream>

#include <SDLA/config.h>
#include <SDLA/core/types/color.h>
#include <SDLA/core/types/vector3.h>
#include <SDLA/mobjects/cloud.h>

#include <include/core/SkPath.h>

namespace SDLA {

/// Mathematical Object Class
class SDLA_API Mobject {

protected:
  const u32 id;
public:
  float z_index;

  Mobject(Color color = Color::White, float z_index = 0);

  // Mobject(u32 id): id(id) {}
  
  virtual ~Mobject();
   
  [[nodiscard]] virtual SkPath get_path() const  {
    SkPathBuilder builder;
    return builder.detach();
  };

  // deep copy on the points & metadata cloud with new id
  // [[nodiscard]] virtual constexpr Mobject copy(bool should_clone) const = 0;
  

  [[nodiscard]] inline constexpr vec3f &operator[](u32 index) const {
    return cloud->points[cloud->metadata[id].poindex + index];
  }



  [[nodiscard]] inline constexpr const SkPaint &get_paint() const {
    return cloud->paints[cloud->metadata[id].paindex];
  }

  [[nodiscard]] inline constexpr u32 get_poindex() const {
    return cloud->metadata[id].poindex;
  }

  [[nodiscard]] inline constexpr u16 get_pocount() const {
    return cloud->metadata[id].pocount;
  }

  [[nodiscard]] inline constexpr u16 get_paindex() const {
    return cloud->metadata[id].paindex;
  }

  // virtual void generate_points() = 0;
  // Mobject add(const Mobject &mobject);
  


protected:  
  inline constexpr void push_point(vec3f point){
    cloud->push_point(point);
  }

  inline constexpr void set_pocount(u16 pocount){
    cloud->metadata[id].pocount = pocount;
  }


};


\


}


