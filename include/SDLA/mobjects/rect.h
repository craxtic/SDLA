#include <SDLA/config.h>
#include <SDLA/mobjects/vmobject.h>
#include <SDLA/core/types/vector2.h>

namespace SDLA {

  
class SDLA_API Rect : public VMobject {

public:
  Rect(vec2f p1, vec2f p2, Color fill_color = Color::White);
  
  ~Rect(){
    
  }
};



}