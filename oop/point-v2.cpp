#include <cmath>
#include <iostream>

class Point {
 public:
  double Distance(Point &p);
  void Scale(double k);
 private:
  double x, y;
  friend int main();
};

double Point::Distance(Point &p) {
  double dx = x - p.x, dy = y - p.y;
  return std::sqrt(dx * dx + dy * dy);
}

void Point::Scale(double k) {
  x *= k;
  y *= k;
}

int main() {
  Point p1, p2;
  std::cin >> p1.x >> p1.y
    >> p2.x >> p2.y;
  std::cout << p1.Distance(p2) << "\n";
  return 0;
}