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

#include "axim/config.h"
#include "log.hpp"
#include <vector>

#include <include/core/SkPaint.h>

#include <axim/core/types/vector3.h>

namespace axm {

// struct MobjectMetadata {
//   u32 poindex; /// point index
//   u16 pocount; /// point count
//   MobjectMetadata(u32 poi, u16 poc)
//       : poindex(poi), pocount(poc) {}
// };

class MobjectCloud {

public:
  std::vector<vec3f> points;
  std::vector<SkPaint> paints;
  // std::vector<MobjectMetadata> metadata; /// mobject's metadata

  MobjectCloud() = default;

  MobjectCloud(size_t init_mobcount, size_t std_pocount);

  inline void push_point(const vec3f &point) {
    this->points.emplace_back(point.x, point.y, point.z);
  }

  inline u16 push_paint(const SkPaint &paint) {
    this->paints.emplace_back(paint);
    return this->paints.size() - 1;
  }
  
  inline u16 init_new_paint(){
    this->paints.emplace_back();
    return this->paints.size() - 1;
  }


  inline u32 new_poindex(){
    return points.size();
  }

};

extern MobjectCloud *const cloud;

} // namespace axm