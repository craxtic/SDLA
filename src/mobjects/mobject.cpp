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

#include "log.hpp"
#include <axim/mobjects/cloud.h>
#include <axim/mobjects/mobject.h>

namespace axm {

Mobject::Mobject(Color color, float z_index)
    : z_index(z_index), id(cloud->metadata.size()) {
  
  cloud->push_metadata(MobjectMetadata(cloud->points.size(), 0, 0));

  /// TODO: handle z_index initialization
}

Mobject::~Mobject() {}

} // namespace axm