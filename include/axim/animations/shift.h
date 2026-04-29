#pragma once

#include <axim/core/types/vector2.h>
#include <axim/animations/animation.h>

namespace axm {

class AXIM_API Shift : public Animation {
  vec2f delta;

public:
  Shift(Mobject &target, vec2f delta, float run_time = 1.f);


  virtual constexpr void interpolate(float alpha) override;

};

} // namespace axm