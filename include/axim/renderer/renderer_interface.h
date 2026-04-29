#pragma once

#include "axim/config.h"
#include <axim/core/types/color.h>
#include <include/core/SkPaint.h>
#include <include/core/SkPath.h>

namespace axm {

class AXIM_API IRenderer {

public:
  virtual ~IRenderer() = default;

  /// clear the buffer with a given color
  virtual void clear(Color color) const = 0;

  /// draw a path with a given paint object
  virtual void draw_path(const SkPath &path, const SkPaint &paint) const = 0;

  /// display the drawn buffer to the output
  virtual void present() const = 0;

  /// pause
  /// TODO: introduce a new param to accept the idling duration
  virtual void idle() const = 0;
};

} // namespace axm
