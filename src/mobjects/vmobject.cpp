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


#include <include/core/SkPath.h>
#include <include/core/SkPathBuilder.h>

#include <axim/core/types/color.h>
#include <axim/core/types/vector3.h>
#include <axim/mobjects/vmobject.h>

namespace axm {

VMobject::VMobject(Color fill_color) : Mobject(fill_color) {}

[[nodiscard]] SkPath VMobject::get_path() const {

  SkPathBuilder builder;
  if (this->get_pocount() == 0)
    return builder.detach();

  vec3f point = (*this)[0];
  builder.moveTo({point.x, point.y});

  for (int i = 1; i < this->get_pocount(); i++) {
    vec3f p = (*this)[i];
    builder.lineTo({p.x, p.y});
  }
  builder.close();

  return builder.detach();
};

} // namespace axm