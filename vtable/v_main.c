#include "lib.h"

#include <stdio.h>

int main() {
  Shape *s = NewShape();
  Shape *r = NewRectangle(10, 20);
  Shape *c = NewCircle(100, 0, 0);
  Draw(s);
  Draw(r);
  Draw(c);
  Move(s, 30, 50);
  Move(r, 30, 50);
  Move(c, 30, 50);
  return 0;
}