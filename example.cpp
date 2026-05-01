#include "axim/core/types/color.h"
#include "axim/mobjects/rect.h"
#include "axim/animations/shift.h"
#include "axim/scene/scene.h"
#include <axim/axim.h>

using namespace axm;

int main(){

  axm::Scene scene(60, axm::Color::Black);
  
  Rect r({100, 100}, {200, 200}, Color::Blue);
  Shift sh(r, {200, 0});

  scene.add(r);
  scene.add(Rect({120, 300}, {30, 29}, Color::Cyan));
  scene.play(sh);
  
  scene.idle();

  return 0;
}