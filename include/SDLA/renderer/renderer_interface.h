#pragma once

#include "SDLA/config.h"
#include <include/core/SkPath.h>
#include <include/core/SkPaint.h>
#include <SDLA/core/types/color.h>

namespace SDLA {

  
class SDLA_API IRenderer {
  
public: 
  virtual ~IRenderer() = default;
  virtual void clear(Color color) const = 0;
  virtual void draw_path(const SkPath &path, const SkPaint &paint) const = 0;
  virtual void present() const = 0;
  virtual void idle() const = 0; 
};

}

