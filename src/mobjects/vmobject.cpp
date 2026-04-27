#include <SDLA/core/types/vector3.h>
#include <SDLA/core/types/color.h>
#include <SDLA/mobjects/vmobject.h>

#include <include/core/SkPath.h>
#include <include/core/SkPathBuilder.h>

namespace SDLA {

VMobject::VMobject(Color fill_color): Mobject(fill_color){
  

}

[[nodiscard]] SkPath VMobject::get_path() const {

  SkPathBuilder builder;
  std::cout << this->get_pocount() << std::endl;
  if(this->get_pocount() == 0) return builder.detach();
  vec3f point = (*this)[0];
  builder.moveTo({point.x, point.y});
  for(int i = 1; i < this->get_pocount(); i++){
    vec3f p = (*this)[i];
    std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
    builder.lineTo({p.x, p.y});
  }
  builder.close();
  return builder.detach();
};



}