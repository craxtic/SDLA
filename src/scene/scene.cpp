#include "SDLA/mobjects/mobject.h"
#include "SDLA/mobjects/vmobject.h"
#include "SDLA/renderer/window.h"
#include <SDLA/scene/scene.h>
#include <iostream>


namespace SDLA {

Scene::Scene(u8 frame_rate, const Color &bg_color, RenderMode render_mode):
  frame_rate(frame_rate),
  bg_color(bg_color),
  render_mode(render_mode)
{
  if(render_mode == RenderMode::Preview){
    this->renderer = preview_renderer;
  }

  this->mobjects.reserve(MOBJECT_COUNT_PER_SCENE_PROBABLY);
  this->render_frame();
}
  

void Scene::render_frame() const {
  this->renderer->clear(this->bg_color);
  for(const Mobject *mobject : this->mobjects){
    SkPath path = mobject->get_path();
    SkPaint paint = mobject->get_paint();
    this->renderer->draw_path(path, paint);
  }
  this->renderer->present();
  return;
}


void Scene::set_render_mode(RenderMode render_mode){
  if(render_mode == RenderMode::Preview)
    this->renderer = preview_renderer;
  
  this->render_mode = render_mode;
}

void Scene::add(Mobject &mobject){
  this->push(&mobject);
  this->render_frame();
  std::cout<< "passed " << __LINE__ << std::endl;
  return;
}


void Scene::idle() const {
  this->renderer->idle();
  return;
};


}