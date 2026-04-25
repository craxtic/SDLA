#include "SDLA/renderer/window.h"
#include <iostream>

#include <SDLA/SDLA.h>

int main(){

  // SDLA::PreviewRenderer pr;
  SDLA::Scene scene(60, SDLA::Color::Black);

  scene.render_frame();

  SDLA::PreviewRenderer::idle();

  return 0;
}