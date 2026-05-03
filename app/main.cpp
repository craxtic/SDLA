// #include "axim/animations/shift.h"
#include "axim/bindings/bindings.h"
#include "axim/core/types/color.h"
#include "axim/mobjects/rect.h"
#include "axim/mobjects/rect.h"
#include "axim/drivers/driver.h"
#include "axim/scene/scene.h"
#include <axim/axim.h>
#include <axim/drivers/export.h>
#include <axim/drivers/window.h>
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
  


  DriverInterface *driver;

  char opt;
  std::cout << "demo code, \n1.preview\n2.export\nchoose: ";
  std::cin >> opt;

  if (opt == '1') {
    driver = new PreviewDriver();
  } else if (opt == '2') {
    driver = new ExportDriver({1920, 1080}, "test.mp4");
  } else
    return 0;

  Scene scene(60, axm::Color::Black, driver);
  axm::lua::bind_scene_funcs(lua, scene);

  bool previewing = true;
  while(previewing){

    std::cout << "reload" << std::endl;
  
    lua.script_file(argv[1]);

    scene.idle(-1, &previewing);

    scene.clear();
  }




  return 0;
}
