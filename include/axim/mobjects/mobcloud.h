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

#include <include/core/SkPaint.h>
#include <vector>

#include <axim/config.h>
#include <axim/core/types/vector3.h>
#include <axim/core/types/ctype.h>

namespace axm::mobcloud {

class MobjectCloud {

public:
  std::vector<vec3f> points;
  std::vector<SkPaint> paints;

  MobjectCloud() = default;

  MobjectCloud(size_t init_mobcount, size_t std_pocount);

  

  
 
};


extern MobjectCloud *const mobject_cloud;

inline u32 new_poindex(){
  return mobject_cloud->points.size();
}

inline u16 init_new_paint(){
  mobject_cloud->paints.emplace_back();
  return mobject_cloud->paints.size() - 1;
} 

inline SkPaint &get_paint_at(u16 paindex){
  return mobject_cloud->paints[paindex];
}

inline vec3f &get_point_at(u32 poindex){
  return mobject_cloud->points[poindex];
}

inline void push_point(const vec3f &point) {
  mobject_cloud->points.emplace_back(point.x, point.y, point.z);
} 


inline u16 push_paint(const SkPaint &paint) {
  mobject_cloud->paints.emplace_back(paint);
  return mobject_cloud->paints.size() - 1;
}

} // namespace axm