#pragma once

#include <axim/mobjects/mobject.h>

namespace axm {

class Animation {

protected:
  const Mobject &begin_state;
  Mobject &mobject;
  float run_time;
public:
  Animation(Mobject &target, float run_time)
      : mobject(target), run_time(run_time), begin_state(*(target.copy(true))) {}

  virtual constexpr void interpolate(float alpha) = 0;

  [[nodiscard]] inline float get_run_time(){
    return run_time;
  }

  [[nodiscard]] inline Mobject &get_mobject(){
    return mobject;
  }

};

} // namespace axm