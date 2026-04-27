#include <SDLA/mobjects/rect.h>


namespace SDLA {

Rect::Rect(vec2f p1, vec2f p2, Color fill_color):
  VMobject(fill_color) 
{
  this->set_pocount(4);
  this->push_point({p1.x, p1.y, 0});
  this->push_point({p2.x, p1.y, 0});
  this->push_point({p2.x, p2.y, 0});
  this->push_point({p1.x, p2.y, 0});
  return;
}



}