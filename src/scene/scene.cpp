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

#include <axim/mobjects/mobject.h>
#include <axim/mobjects/vmobject.h>
#include <axim/renderer/window.h>
#include <axim/scene/scene.h>
#include <ostream>


namespace axm {

Scene::Scene(u8 frame_rate, const Color &bg_color, RenderMode render_mode)
    : frame_rate(frame_rate), bg_color(bg_color), render_mode(render_mode) {
  if (render_mode == RenderMode::Preview) {
    this->renderer = preview_renderer;
  }

  this->mobjects.reserve(MOBJECT_COUNT_PER_SCENE_PROBABLY);
  this->render_frame();
}

void Scene::render_frame() const {
  this->renderer->clear(this->bg_color);
  for (const Mobject *mobject : this->mobjects) {
    SkPath path = mobject->get_path();
    SkPaint paint = mobject->get_paint();
    this->renderer->draw_path(path, paint);
  }
  this->renderer->present();
  return;
}

void Scene::set_render_mode(RenderMode render_mode) {
  if (render_mode == RenderMode::Preview)
    this->renderer = preview_renderer;

  this->render_mode = render_mode;
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