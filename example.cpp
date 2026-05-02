#include "axim/core/types/color.h"
#include "axim/mobjects/rect.h"
#include "axim/animations/shift.h"
#include "axim/renderer/renderer_interface.h"
#include "axim/scene/scene.h"
#include <axim/axim.h>
#include <axim/renderer/window.h>
#include <axim/renderer/export.h>
#include <unistd.h>

using namespace axm;

int main(){

  IRenderer *renderer;
  
  char opt;
  std::cout << "demo code, \n1.preview\n2.export\nchoose: ";
  std::cin >> opt; 
  
  if (opt ==  '1'){
    renderer = new PreviewRenderer();
  }else if (opt == '2')  {
    renderer = new ExportRenderer({1920, 1080}, "test.mp4");
  }else return 0;

  Scene scene(60, axm::Color::Black, renderer);
  
  Rect r({100, 100}, {200, 200}, Color::Blue);
  Shift sh(r, {200, 0});

  scene.add(r);
  scene.add(Rect({120, 300}, {30, 29}, Color::Cyan));
  scene.play(sh);
  
  scene.idle();
  

  return 0;
}