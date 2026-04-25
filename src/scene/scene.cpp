#include <SDLA/scene/scene.h>


namespace SDLA {

Scene::Scene(u8 frame_rate, const Color &bg_color, RenderMode render_mode):
  frame_rate(frame_rate),
  bg_color(bg_color),
  render_mode(render_mode)
{
  if(render_mode)

  this->mobjects.reserve(MOBJECT_COUNT_PER_SCENE_PROBABLY);
  this->render_frame();
}
  
void Scene::render_frame() const {
  this->renderer->clear(this->bg_color);
  for(const Mobject &mobject : this->mobjects){
    this->renderer->draw_path(mobject.get_path(), mobject.get_paint());
  }
  this->renderer->present();
  return;
}

void Scene::add(const Mobject &mobject){
  this->push(mobject);
  this->render_frame();
  return;
}

void Scene::play(const Animation &animatoin){

}



}