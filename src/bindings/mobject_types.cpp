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

#include <axim/bindings/bindings.h>
#include <axim/mobjects/mobject.h>
#include <axim/mobjects/vmobject.h>
#include <axim/mobjects/rect.h>
#include <iostream>
#include <sol/state_view.hpp>
#include <sol/sol.hpp>


namespace axm {

// void lua::bind_mobject_types(sol::state_view state){

//   state.new_usertype<Mobject>("Mobject");

//   state.new_usertype<VMobject>("VMobject",
//     sol::base_classes, 
//     sol::bases<Mobject>());

//   state.new_usertype<Rect>("Rect", 
//     sol::call_constructor,
//     sol::constructors<axm::Rect(vec2f, vec2f)>(), 
//     sol::base_classes,
//     sol::bases<Mobject, VMobject>()
//   );

// }


void lua::bind_mobject_types(sol::state_view state){
  
  std::cout << "did get called" << std::endl;

  state.new_usertype<Mobject>("Mobject");

  state.new_usertype<VMobject>("VMobject",
    sol::base_classes, 
    sol::bases<Mobject>());

  state.new_usertype<Rect>("Rect", 
    sol::call_constructor,
    sol::constructors<axm::Rect(vec2f, vec2f)>(), 
    sol::base_classes,
    sol::bases<Mobject, VMobject>()
  );



}


}