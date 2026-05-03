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

#pragma once

#define SOL_ALL_SAFETIES_ON 1
#define SOL_TYPE_CHECK_INVARIANT_ID 1
#include <axim/config.h>
#include <axim/scene/scene.h>

#include <sol/forward.hpp>

namespace axm::lua {

void AXIM_API bind_maths_types(sol::state_view state);
void AXIM_API bind_mobject_types(sol::state_view state);
void AXIM_API bind_scene_funcs(sol::state_view state, Scene &scene);


}