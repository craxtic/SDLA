#pragma once

#include "log.hpp"
#include <axim/core/types/vector2.h>
#include <axim/mobjects/vmobject.h>

namespace axm {

class AXIM_API Rect : public VMobject {

public:
  Rect() = default;

  Rect(vec2f p1, vec2f p2, Color fill_color = Color::White);

  /// TODO: implement a full version of copy
  [[nodiscard]] Mobject *copy(bool should_clone) const override;
};

} // namespace axm