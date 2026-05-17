/*     _          _
 *    / \   __  _(_)_ __ ___
 *   / _ \  \ \/ / | '_ ` _ \
 *  / ___ \  >  <| | | | | | |
 * /_/   \_\/_/\_\_|_| |_| |_|
 *
 * Copyright (c) 2026 The Axim Team
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org.
 */

#include <axim/axim.h>
#include <axim/presenters/presenter.h>
#include <axim/presenters/window.h>
#include <axim/presenters/export.h>

#include "app.hpp"

#include <iostream>

using namespace axm;


axm::Scene* glob_scene = nullptr;


int main(int argc, char *argv[]) {

  if (argc != 2)
    return 1;

  
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
  glob_scene = &scene;

  lua_State *lstate = luaL_newstate();
  luaL_openlibs(lstate);

  init_luajit_ffi_module(lstate);

  bool previewing = true;
  while(previewing){
    
    std::cout << "reload" << std::endl;
    
    
    if(luaL_dofile(lstate, argv[1])){
      std::cerr << "Error: " << lua_tostring(lstate, -1) << std::endl;
    }
    
    scene.idle(-1, &previewing);
    
    scene.clear();
  }
  
  lua_close(lstate);


  return 0;
}
