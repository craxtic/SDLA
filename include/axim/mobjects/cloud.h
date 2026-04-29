#pragma once

#include "axim/config.h"
#include "log.hpp"
#include <vector>

#include <include/core/SkPaint.h>

#include <axim/core/types/vector3.h>

namespace axm {

struct MobjectMetadata {
  u32 poindex; /// point index
  u16 pocount; /// point count
  u16 paindex; /// paint index
  MobjectMetadata(u32 poi, u16 poc, u16 pai)
      : poindex(poi), pocount(poc), paindex(pai) {}
};

class MobjectCloud {

public:
  std::vector<vec3f> points;
  std::vector<SkPaint> paints;
  std::vector<MobjectMetadata> metadata; /// mobject's metadata

  MobjectCloud() = default;

  MobjectCloud(size_t init_mobcount, size_t std_pocount);

  inline void push_point(const vec3f &point) {
    this->points.emplace_back(point.x, point.y, point.z);
  }

  inline void push_paint(const SkPaint &paint) {
    this->paints.emplace_back(paint);
  }

  inline void push_metadata(const MobjectMetadata &metadata) {
    this->metadata.emplace_back(metadata.poindex, metadata.pocount,
                                metadata.paindex);
  }

  inline u32 new_mobject_uid(){
    return metadata.size();
  }

  inline u32 new_poindex(){
    return points.size();
  }

};

extern MobjectCloud *const cloud;

} // namespace axm