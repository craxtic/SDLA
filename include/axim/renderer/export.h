#include "axim/core/types/vector2.h"
#include <axim/config.h>
#include <axim/renderer/renderer_interface.h>
#include <include/core/SkSurface.h>
#include <cstdio>


namespace axm {


class AXIM_API ExportRenderer : public IRenderer {

  sk_sp<SkSurface> surface;
  FILE* ffmpeg;
  vec2i dimensions;

public:

  ExportRenderer(vec2i dimensions, std::string_view output_filename);
  ~ExportRenderer();

  virtual void make_current() override;

  /// get a new canvas from this renderer
  virtual SkCanvas *get_canvas() override;

  /// display the drawn buffer to the output
  virtual void present() const override;

  /// pause
  /// TODO: introduce a new param to accept the idling duration
  virtual void idle() const override;

};


}