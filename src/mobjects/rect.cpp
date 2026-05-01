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

#include <axim/mobjects/rect.h>
#include "axim/mobjects/cloud.h"


namespace axm {

Rect::Rect(vec2f p1, vec2f p2, Color fill_color) : VMobject(fill_color) {
  this->set_pocount(4);
  this->push_point({p1.x, p1.y, 0});
  this->push_point({p2.x, p1.y, 0});
  this->push_point({p2.x, p2.y, 0});
  this->push_point({p1.x, p2.y, 0});
  return;
}

[[nodiscard]] Mobject *Rect::copy(bool should_clone) const {
    Rect *_Rect = new Rect();
    
    if(!should_clone) {
      _Rect->id = this->id;
      return _Rect;
    }

    _Rect->id = cloud->new_mobject_uid();
    cloud->push_metadata({
      cloud->new_poindex(),
      this->get_pocount(),
      this->get_paindex()
    });
    for(int i = 0; i < _Rect->get_pocount(); i++)
      _Rect->push_point((*this)[i]);

    return _Rect;
  }

} // namespace axm