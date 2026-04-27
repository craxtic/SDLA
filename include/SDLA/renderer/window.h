#pragma once 

#include "SDLA/config.h"
#include "SDLA/core/types/color.h"
#include <SDLA/renderer/renderer_interface.h>


#include <SDL3pp/SDL3pp_video.h>

#include <include/core/SkSurface.h>


namespace SDLA {

  
class SDLA_API PreviewRenderer : public IRenderer {
  SDL::Window window;
  sk_sp<SkSurface> surface;
  sk_sp<GrDirectContext> context;
  SkCanvas *canvas;
public:
  PreviewRenderer();

  void clear(Color color) const override;
  void draw_path(const SkPath &path, const SkPaint &paint) const override;
  void present() const override;

  /// keep window alive and wait for window close event
  void idle() const override;

  /// test open window (should remove later)
  void test_open_window(){
    clear(Color::Black);
    present();
  }

  ~PreviewRenderer();
  
 
private:
  sk_sp<SkSurface> _create_sk_surface(int w, int h);
};

extern PreviewRenderer * const preview_renderer;

}