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

#include "axim/core/types/color.h"
#include <axim/renderer/renderer_interface.h>

#include <SDL3pp/SDL3pp_video.h>
#include <include/core/SkSurface.h>


namespace axm {

  
class AXIM_API PreviewRenderer : public IRenderer {
  SDL::Window window;
  sk_sp<SkSurface> surface;
  sk_sp<GrDirectContext> context;
  SDL::GLContext gl_context; 
  SkCanvas *canvas;

public:
  PreviewRenderer();

  void present() const override;

  void make_current() override;
  
  SkCanvas *get_canvas() override;

  /// keep window alive and wait for window close event
  void idle() const override;

  ~PreviewRenderer();
   
private:
  sk_sp<SkSurface> _create_sk_surface(int w, int h);
};

// extern PreviewRenderer * const preview_renderer;

}