#pragma once

#include <SDLA/core/types/vector2.h>
#include <SDLA/mobjects/vmobject.h>

namespace SDLA {

class SDLA_API Rect : public VMobject {

public:
  Rect() = default;

  Rect(vec2f p1, vec2f p2, Color fill_color = Color::White);

  /// TODO: implement a full version of copy
  [[nodiscard]] Mobject *copy(bool should_clone) const override {
    Rect *rect = new Rect();
    rect->id = this->id;
    return rect;
  }
};

} // namespace SDLA