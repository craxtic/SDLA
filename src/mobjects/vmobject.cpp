
#include <include/core/SkPath.h>
#include <include/core/SkPathBuilder.h>

#include <axim/core/types/color.h>
#include <axim/core/types/vector3.h>
#include <axim/mobjects/vmobject.h>

namespace axm {

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

} // namespace axm