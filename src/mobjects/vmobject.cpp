
#include <include/core/SkPath.h>
#include <include/core/SkPathBuilder.h>

#include <SDLA/core/types/color.h>
#include <SDLA/core/types/vector3.h>
#include <SDLA/mobjects/vmobject.h>

namespace SDLA {

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

} // namespace SDLA