#include <SDLA/mobjects/cloud.h>
#include <include/core/SkColor.h>


namespace SDLA {

MobjectCloud::MobjectCloud(size_t init_mobcount, size_t std_pocount){

  this->points.reserve(init_mobcount * std_pocount);
  this->paints.reserve(init_mobcount);
  this->metadata.reserve(init_mobcount);

  // initialize a default paint
  this->paints.emplace_back();
  this->paints[0].setColor(SK_ColorWHITE);
  this->paints[0].setStyle(SkPaint::kFill_Style);
}



}