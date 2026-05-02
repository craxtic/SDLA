#include "axim/core/types/color.h"
#include "axim/mobjects/rect.h"
#include "axim/animations/shift.h"
#include "axim/scene/scene.h"
#include <axim/axim.h>
#include <axim/renderer/window.h>

using namespace axm;

int main(){

  PreviewRenderer preview_renderer;
  Scene scene(60, axm::Color::Black, &preview_renderer);
  
  Rect r({100, 100}, {200, 200}, Color::Blue);
  Shift sh(r, {200, 0});

  scene.add(r);
  scene.add(Rect({120, 300}, {30, 29}, Color::Cyan));
  scene.play(sh);
  
  scene.idle();




  return 0;
}