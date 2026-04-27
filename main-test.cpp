#include <SDLA/SDLA.h>
#include <SDLA/mobjects/rect.h>

using namespace SDLA;

int main(){
  
  Scene scene(60, Color::Black);

  Rect rect({10, 10}, {20, 20});
  scene.add(rect);

  scene.idle();
  return 0;
}