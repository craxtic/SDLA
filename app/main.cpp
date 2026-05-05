// #include "axim/animations/shift.h"
#include "axim/animations/shift.h"
#include "axim/bindings/bindings.h"
#include "axim/core/types/color.h"
#include "axim/mobjects/rect.h"
#include "axim/mobjects/rect.h"
#include "axim/presenters/presenter.h"
#include "axim/scene/scene.h"
#include <axim/axim.h>
#include <axim/presenters/export.h>
#include <axim/presenters/window.h>
#include <cstddef>
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
  


  PresenterInterface *presenter;

  char opt;
  std::cout << "demo code, \n1.preview\n2.export\nchoose: ";
  std::cin >> opt;

  if (opt == '1') {
    presenter = new PreviewPresenter();
  } else if (opt == '2') {
    presenter = new ExportPresenter({1920, 1080}, "test.mp4");
  } else
    return 0;

  Scene scene(60, axm::Color::Black, presenter);
  axm::lua::bind_scene_funcs(lua, scene);


  Rect r = Rect({100, 100}, {200, 200}, Color::White);

  Shift sh1 = Shift(r, {350, 50}, 2.f);
  Shift sh2 = Shift(r, {-350, -100}, 2.f);
  scene.play(sh1);
  scene.play(sh2);

  // bool previewing = true;
  // while(previewing){

  //   std::cout << "reload" << std::endl;
  
  //   lua.script_file(argv[1]);

  //   scene.idle(-1, &previewing);

  //   scene.clear();
  // }

  scene.idle(-1);


  return 0;
}
