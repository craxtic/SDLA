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
#include <axim/scene/scene.h>

namespace axm {

void lua::bind_scene_funcs(sol::state_view state, Scene &scene){

  state.set_function("add", [&](axm::Mobject &mob) { scene.add(mob); });

}



}