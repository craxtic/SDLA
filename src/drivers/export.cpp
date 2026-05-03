#include <axim/drivers/export.h>
#include <cstdio>
#include <format>
#include <include/core/SkImageInfo.h>
#include <include/core/SkPixmap.h>
#include <include/core/SkSurface.h>
#include <string_view>


namespace axm {

ExportDriver::ExportDriver(vec2i dimensions, std::string_view output_filename): dimensions(dimensions){


  this->surface = SkSurfaces::Raster(SkImageInfo::MakeN32Premul(dimensions.x, dimensions.y));
   if (!surface) {
        throw std::runtime_error("Could not create Skia surface. Check dimensions.");
  }

  /*
  
  ffmpeg -y -f rawvideo -pixel_format rgba -video_size 1920x1080 -i - \
-c:v libx264 -preset slower -crf 18 -pix_fmt yuv420p output.mp4

  
  */
  std::string command = std::format(
    "ffmpeg -y -f rawvideo -framerate 60 -pixel_format bgra -video_size {}x{} -i - -c:v libx264 -preset slower -crf 18 -pix_fmt yuv420p {}", 
    dimensions.x, dimensions.y, output_filename
  );

  this->ffmpeg = popen(command.c_str(), "w");

}


void ExportDriver::make_current() {
  return;
}

/// get a new canvas from this renderer
SkCanvas *ExportDriver::get_canvas() {
  return this->surface->getCanvas();
}

/// display the drawn buffer to the output
void ExportDriver::present() const {
  SkPixmap pixmap;
  if(this->surface->peekPixels(&pixmap)){
    fwrite(pixmap.addr(), 1, pixmap.computeByteSize(), this->ffmpeg);
  }
}

/// pause
void ExportDriver::idle() const {
  sleep(2);
  return;
}

ExportDriver::~ExportDriver() {
  this->surface->unref();
  pclose(this->ffmpeg);
}



}