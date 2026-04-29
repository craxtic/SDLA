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