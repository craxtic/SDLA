#include "SDLA/config.h"
#include "SDLA/renderer/window.h"
#include <SDL3pp/SDL3pp_stdinc.h>
#include <SDLA/mobjects/cloud.h>
#include <iostream>

#include <SDLA/config.h>

namespace SDLA {

/// these objects are created to last the entire life time of the program
/// no free is required, the memory leak is harmless
/// a clean up function may be implemented later

MobjectCloud *const cloud =
    new MobjectCloud(MOBJECT_COUNT_PER_SCENE_PROBABLY, 10);
PreviewRenderer *const preview_renderer = new PreviewRenderer();

static class _init {

public:
  _init() { std::cout << "sdla run" << std::endl; }

} init;

} // namespace SDLA