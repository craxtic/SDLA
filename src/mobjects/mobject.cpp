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

#include <axim/mobjects/cloud.h>
#include <axim/mobjects/mobject.h>
#include <include/core/SkPaint.h>

namespace axm {

Mobject::Mobject(Color color, float z_index)
    : poindex(cloud->new_poindex()), z_index(z_index) {
  
  this->paindex = cloud->init_new_paint();
  SkPaint &paint = cloud->paints.at(this->paindex);
  paint.setColor(color);

  /// TODO: handle z_index initialization
}

Mobject::~Mobject() {
  
}

} // namespace axm