#include <axim/animations/shift.h>
#include <axim/axim.h>
#include <axim/mobjects/rect.h>

using namespace axm;

int main(){
  
  Scene scene(60, Color::Black);

  Rect rect({100, 100}, {200, 200});


  scene.add(rect);
  Shift shift(rect, {500, 0}, 1);
  scene.play(shift);

  scene.idle();
  return 0;
}