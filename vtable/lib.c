#include "lib.h"

#include <stdio.h>
#include <stdlib.h>

void Draw(Shape* obj) {
  obj->_vtable[DRAW](obj);
}

void Move(Shape* obj, double dx, double dy) {
  obj->_vtable[MOVE](obj, dx, dy);
}

void ShapeDraw(Shape *obj) {
  printf("Shape Generic Draw!\n");
}

void ShapeMove(Shape *obj, double dx, double dy) {
  printf("Shape Generic Move!\n");
}

void CircleDraw(Circle *obj) {
  printf("Draw circle at (%.2lf, %.2lf) with radius = %.2lf\n",
    obj->cx, obj->cy, obj->r);
}

void CircleMove(Circle *obj, double dx, double dy) {
  obj->cx += dx;
  obj->cy += dy;
  printf("Circle moved to (%.2lf, %.2lf)\n", obj->cx, obj->cy);
}

void RectangleDraw(Rectangle *obj) {
  printf("Draw a %.2lf x %.2lf rectangle\n", obj->a, obj->b);
}

static fpointer_t shape_vtable[] = {
          [DRAW] = ShapeDraw,
          [MOVE] = ShapeMove};
static fpointer_t rectangle_vtable[] = {
          [DRAW] = RectangleDraw,
          [MOVE] = ShapeMove};
static fpointer_t circle_vtable[] = {
          [DRAW] = CircleDraw,
          [MOVE] = CircleMove};

Shape *NewShape() {
  Shape *obj = (Shape*)malloc(sizeof(Shape));
  obj->_vtable = shape_vtable;
}

Rectangle *NewRectangle(double a, double b) {
  Rectangle *obj = (Rectangle*)malloc(sizeof(Rectangle));
  obj->a = a;
  obj->b = b;
  obj->_vtable = rectangle_vtable;
}

Circle *NewCircle(double r, double cx, double cy) {
  Circle *obj = (Circle*)malloc(sizeof(Circle));
  obj->r = r;
  obj->cx = cx;
  obj->cy = cy;
  obj->_vtable = circle_vtable;
  return obj;
}