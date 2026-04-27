#pragma once

#include <SDLA/config.h>
#include <SDLA/core/types/vector2.h>
#include <SDLA/core/types/color.h>
#include <SDLA/renderer/renderer_interface.h>
#include <SDLA/mobjects/mobject.h>
#include <SDLA/animations/animation.h>

#include <memory>
#include <vector>

namespace SDLA {

enum class RenderMode {
  Preview,
  Export
};  

class SDLA_API Scene final {
  
  IRenderer *renderer;
  std::vector<Mobject*> mobjects; /// z_index of 0  
  u8 frame_rate;
  Color bg_color;
  RenderMode render_mode;

public:
  
  
  Scene(u8 frame_rate, const Color &bg_color, RenderMode render_mode = RenderMode::Preview);
  

  inline void set_framerate(u8 frame_rate){
    this->frame_rate = frame_rate;
  }

  inline void set_bg_color(const Color &color){
    this->bg_color = color;
  }

 
  /// add an mobject to the mobject list
  inline void push(Mobject *mobject){
    mobjects.emplace_back(mobject);
  }

  inline void remove(const Mobject &mobject) {
    /// TODO: need a hash map maybe 
    /// 
  }

  void set_render_mode(RenderMode render_mode); 

  /// render the current frame using the mobject list
  void render_frame() const;

  /// add an mobject to the scene and render
  void add(Mobject &mobject);
  void add(const Mobject &&mobject);

  /// play an animation
  void play(const Animation &animatoin);


  void idle() const;
};
  
}