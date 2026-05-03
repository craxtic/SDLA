#include "axim/core/types/vector2.h"
#include <axim/config.h>
#include <axim/drivers/driver.h>
#include <include/core/SkSurface.h>
#include <cstdio>


namespace axm {


class AXIM_API ExportDriver : public DriverInterface {

  sk_sp<SkSurface> surface;
  FILE* ffmpeg;
  vec2i dimensions;

public:

  ExportDriver(vec2i dimensions, std::string_view output_filename);
  ~ExportDriver();

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