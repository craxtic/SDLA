#include "log.hpp"
#include <axim/animations/shift.h>
#include <cmath>

namespace axm {

Shift::Shift(Mobject &target, vec2f delta, float run_time)
    : Animation(target, run_time), delta(delta)
{
}

constexpr void Shift::interpolate(float alpha) {
  // alpha = 3*alpha*alpha - 2 * alpha * alpha * alpha;
  // alpha = 1 + 2.70158 * (t-1)*(t-1)*(t-1) + 1.70158*(t-1)*(t-1);
  // alpha = 6*pow(t, 5) - 15*pow(t, 4) + 10* pow(t, 3);
  // alpha = pow(2,(10 * (alpha - 1)));
  float t = alpha;
  alpha = t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f);

  
  for(int i = 0; i < this->mobject.get_pocount(); i++){
    this->mobject[i].x = begin_state[i].x + delta.x * alpha;
    this->mobject[i].y = begin_state[i].y + delta.y * alpha;
  }

}


} // namespace axm