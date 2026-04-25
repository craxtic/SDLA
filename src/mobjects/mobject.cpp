#include "SDLA/core/types/ctype.h"
#include <SDLA/mobjects/mobject.h>
#include <SDLA/mobjects/cloud.h>

namespace SDLA {

Mobject::Mobject(Color color, float z_index): z_index(z_index) {
  u16 new_id = cloud.metadata.size();
  cloud.push_metadata(MobjectMetadata(
    cloud.points.size(),
    0,
    0
  ));
  this->id = new_id; 

  /// TODO: handle z_index initialization

}

Mobject::~Mobject(){
  
}

SkPath Mobject::get_path() const {

}


[[nodiscard]] constexpr Mobject Mobject::copy() const {
  Mobject new_mobject;
  u16 new_id = new_mobject.id;
  

  for(int i = 0; i < this->get_pocount(); i++)  
    cloud.push_point((*this)[i]);

  cloud.metadata[new_id].pocount = this->get_pocount();
  cloud.metadata[new_id].paindex = this->get_paindex();

  return new_mobject;  
} 

}