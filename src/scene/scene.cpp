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

#include "axim/drivers/driver.h"
#include <axim/mobjects/mobject.h>
#include <axim/mobjects/vmobject.h>
#include <axim/scene/scene.h>
#include <axim/utils/errors.h>


namespace axm {

Scene::Scene(u8 frame_rate, const Color &bg_color, DriverInterface* renderer)
    : frame_rate(frame_rate), bg_color(bg_color), renderer(renderer) {

  
  this->mobjects.reserve(MOBJECT_COUNT_PER_SCENE_PROBABLY);
  
  if(renderer == nullptr) return;
  renderer->make_current();
  this->canvas = renderer->get_canvas();

}

void Scene::render_frame() const {
  this->canvas->clear(this->bg_color);
  
  for (const Mobject *mobject : this->mobjects) {
    SkPath path = mobject->get_path();
    SkPaint paint = mobject->get_paint();
    this->canvas->drawPath(path, paint);
  }

  this->renderer->present();
  return;
}

void Scene::set_renderer(DriverInterface *renderer) {
  if (renderer == nullptr) 
    return;

  renderer->make_current();
  this->canvas = renderer->get_canvas();
  this->renderer = renderer;
  return;
}

void Scene::add(Mobject &mobject) {
  this->push(&mobject);
  this->render_frame();
  return;
}

void Scene::add(const Mobject &&mobject) {
  Mobject *mob = mobject.copy(false);
  this->rvalue_mobjects.emplace_back(mob);
  this->push(mob);
  this->render_frame();
}

void Scene::play(Animation &animation) {

  this->push(&animation.get_mobject());
  
  int total_frames = this->frame_rate * animation.get_run_time();
  for(float f = 0; f < total_frames; f++){
    float alpha = f / total_frames;
    animation.interpolate(alpha);
    this->render_frame();
  }

}


void Scene::idle() const {
  this->renderer->idle();
  return;
};

Scene::~Scene() {

  for (Mobject *mob : this->rvalue_mobjects)
    delete mob;
  this->rvalue_mobjects.clear();

}

} // namespace axm