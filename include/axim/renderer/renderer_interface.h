/*     _          _
 *    / \   __  _(_)_ __ ___
 *   / _ \  \ \/ / | '_ ` _ \
 *  / ___ \  >  <| | | | | | |
 * /_/   \_\/_/\_\_|_| |_| |_|
 *
 * Copyright (c) 2026 The Axim Team
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org.
 */

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
