#pragma once


#include "SDLA/mobjects/mobject.h"

namespace SDLA {


class Animation {

protected:
  Mobject begin_state;
  Mobject &mobject;
  float run_time;

public:

  Animation(Mobject &target, float run_time) : 
    mobject(target),
    run_time(run_time)
  {}

  virtual constexpr void interpolate(float alpha) = 0; 
  
};


}