#include <SDLA/SDLA.h>
#include <SDLA/mobjects/rect.h>

using namespace SDLA;

int main(){
  
  Scene scene(60, Color::Black);

  Rect rect({10, 10}, {20, 20});
  scene.add(rect);
  scene.add(Rect({30, 30}, {100, 200}));
  scene.add(Rect());

  scene.idle();
  return 0;
}