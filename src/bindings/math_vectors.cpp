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
#include <axim/core/types/vector2.h>

#include <sol/state_view.hpp>

namespace axm{

template <typename T>
void register_vector2_type(sol::state_view state, std::string_view name){

  state.new_usertype<vec2<T>>(
    name,
    sol::call_constructor,
    sol::constructors<vec2<T>(), vec2<T>(T, T)>(),

    "x", &vec2<T>::x,
    "x", &vec2<T>::y

  );

}
 
  
void lua::bind_maths_types(sol::state_view state){

  register_vector2_type<float>(state, "vec2f");

}


}
