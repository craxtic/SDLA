#pragma once

#include <SDLA/mobjects/mobject.h>

namespace SDLA {

class SDLA_API VMobject : public Mobject {

public:
  VMobject() = default;

  VMobject(Color fill_color);

  [[nodiscard]] SkPath get_path() const override;
};

} // namespace SDLA