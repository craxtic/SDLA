#pragma once

#include <axim/mobjects/mobject.h>

namespace axm {

class AXIM_API VMobject : public Mobject {

public:
  VMobject() = default;

  VMobject(Color fill_color);

  [[nodiscard]] SkPath get_path() const override;
};

} // namespace axm