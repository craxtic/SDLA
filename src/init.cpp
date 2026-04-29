#include "axim/config.h"
#include "axim/renderer/window.h"
#include <SDL3pp/SDL3pp_stdinc.h>
#include <axim/mobjects/cloud.h>
#include <iostream>

#include <axim/config.h>

namespace axm {

/// these objects are created to last the entire life time of the program
/// no free is required, the memory leak is harmless
/// a clean up function may be implemented later

MobjectCloud *const cloud =
    new MobjectCloud(MOBJECT_COUNT_PER_SCENE_PROBABLY, 10);
PreviewRenderer *const preview_renderer = new PreviewRenderer();

static class _init {

public:
  _init() {  }

} init;

} // namespace axm