// #include "axim/animations/shift.h"
#include "axim/animations/shift.h"
// #include "axim/bindings/vec.h"
#include "axim/core/types/color.h"
#include "axim/core/types/vector2.h"
#include "axim/mobjects/rect.h"
#include "axim/mobjects/rect.h"
#include "axim/presenters/presenter.h"
#include "axim/scene/scene.h"
#include <axim/axim.h>
#include <axim/presenters/export.h>
#include <axim/presenters/window.h>

// #include <sol/sol.hpp>
#include <thread>
#include <unistd.h>
#include <vector>

// #include <SFML/Config.hpp>
// #include <SFML/System/Export.hpp>
// #include <SFML/Graphics/Export.hpp>

#include <luajit-2.1/lua.hpp>


using namespace axm;



int main(int argc, char *argv[]) {

  if (argc != 2)
    return 1;

  lua_State *state = luaL_newstate();
  luaL_openlibs(state);

  if(luaL_dofile(state, argv[1])){
    std::cerr << "Error: " << lua_tostring(state, -1) << std::endl;
  }

  lua_close(state);

  // PresenterInterface *presenter;

  // char opt;
  // std::cout << "demo code, \n1.preview\n2.export\nchoose: ";
  // std::cin >> opt;

  // if (opt == '1') {
  //   presenter = new PreviewPresenter();
  // } else if (opt == '2') {
  //   presenter = new ExportPresenter({1920, 1080}, "test.mp4");
  // } else
  //   return 0;

  // Scene scene(60, axm::Color::Black, presenter);
  // // axm::lua::bind_scene_funcs(lua, scene);

  

  

  // bool previewing = true;
  // while(previewing){

    // std::cout << "reload" << std::endl;
  
    // lua.script_file(argv[1]);

    // scene.idle(-1, &previewing);

    // scene.clear();
  // }

  // scene.idle(-1);


  return 0;
}
