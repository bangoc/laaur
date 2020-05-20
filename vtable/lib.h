#ifndef LIB_H_
#define LIB_H_

typedef void (*fpointer_t)();

typedef enum {DRAW, MOVE} virtual_function_enum;

typedef struct {
  fpointer_t *_vtable;
} Shape;

typedef struct {
  fpointer_t *_vtable;
  double r;
  double cx, cy;
} Circle;

typedef struct {
  fpointer_t *_vtable;
  double a, b;
} Rectangle;

void Draw(Shape*);
void Move(Shape*, double dx, double dy);
void ShapeDraw(Shape*);
void ShapeMove(Shape*, double dx, double dy);
void CircleDraw(Circle*);
void CircleMove(Circle*, double dx, double dy);
void RectangleDraw(Rectangle*);

Shape *NewShape();
Rectangle *NewRectangle(double a, double b);
Circle *NewCircle(double r, double cx, double cy);

#endif  // LIB_H_