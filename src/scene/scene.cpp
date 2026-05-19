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

#include "axim/presenters/presenter.h"
#include <axim/mobjects/mobject.h>
#include <axim/mobjects/vmobject.h>
#include <axim/scene/scene.h>
#include <axim/utils/errors.h>


#include <chrono>

namespace axm {

Scene::Scene(u8 frame_rate, const Color &bg_color, PresenterInterface* presenter)
    : presenter(presenter), frame_rate(frame_rate), bg_color(bg_color){

  
  this->mobjects.reserve(MOBJECT_COUNT_PER_SCENE_PROBABLY);
  
  if(presenter == nullptr) return;
  presenter->make_current();
  this->canvas = presenter->get_canvas();

}

void Scene::render_frame() const {
  this->canvas->clear(this->bg_color);
  
  for (const Mobject *mobject : this->mobjects) {
    this->canvas->drawPath(mobject->get_path(), mobject->get_paint());
  }
  
  this->presenter->present();
  return;
}

void Scene::set_presenter(PresenterInterface *presenter) {
  if (presenter == nullptr) 
    return;

  presenter->make_current();
  this->canvas = presenter->get_canvas();
  this->presenter = presenter;
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
  
  float run_time = animation.get_run_time();
  float elapsed_time = 0.0f;

  auto start_time = std::chrono::high_resolution_clock::now();

  while (elapsed_time < run_time) {
    auto current_time = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<float> duration = current_time - start_time;
    elapsed_time = duration.count();

    // Clamp alpha to 1.0 maximum so it never overshoots the end positions
    float alpha = elapsed_time / run_time;
    if (alpha > 1.0f) alpha = 1.0f;

    animation.interpolate(alpha);

    this->render_frame();
  }
}

// void Scene::play(Animation &animation) {

//   this->push(&animation.get_mobject());
//   int total_frames = this->frame_rate * animation.get_run_time();
  
//   // i64 us_per_frame = 1000000.0 / this->frame_rate;
//   std::chrono::milliseconds frame_duration(1000000/this->frame_rate); 

//   for(float f = 0; f < total_frames; f++){

//     auto begin_time = std::chrono::high_resolution_clock::now(); 

//     float alpha = f / total_frames;
//     animation.interpolate(alpha);
//     this->render_frame();

//     auto end_time = std::chrono::high_resolution_clock::now();
//     auto delta_time = begin_time - end_time;

//     if(delta_time < frame_duration){
//       std::this_thread::sleep_for(frame_duration - delta_time);
//     }

//   }

// }


void Scene::idle(float duration, bool *running) const {
  this->presenter->idle(duration, running);
  return;
};

Scene::~Scene() {

  for (Mobject *mob : this->rvalue_mobjects)
    delete mob;
  this->rvalue_mobjects.clear();

}

} // namespace axm