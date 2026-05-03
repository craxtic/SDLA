// #include "axim/animations/shift.h"
#include "axim/bindings/bindings.h"
#include "axim/core/types/color.h"
#include "axim/mobjects/rect.h"
#include "axim/mobjects/rect.h"
#include "axim/renderer/renderer_interface.h"
#include "axim/scene/scene.h"
#include <axim/axim.h>
#include <axim/renderer/export.h>
#include <axim/renderer/window.h>
#include <unistd.h>

#include <sol/sol.hpp>

using namespace axm;



int main(int argc, char *argv[]) {

  if (argc != 2)
    return 1;

  sol::state lua;
  lua.open_libraries(sol::lib::base);
  axm::lua::bind_maths_types(lua);
  axm::lua::bind_mobject_types(lua);
  


  IRenderer *renderer;

  char opt;
  std::cout << "demo code, \n1.preview\n2.export\nchoose: ";
  std::cin >> opt;

  if (opt == '1') {
    renderer = new PreviewRenderer();
  } else if (opt == '2') {
    renderer = new ExportRenderer({1920, 1080}, "test.mp4");
  } else
    return 0;

  Scene scene(60, axm::Color::Black, renderer);

  axm::lua::bind_scene_funcs(lua, scene);


  lua.script_file(argv[1]);


  scene.idle();

  return 0;
}
