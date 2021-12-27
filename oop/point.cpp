#include <cmath>
#include <iostream>

class Point {
 public:
  double Distance(Point &p);
 private:
  double x, y;
  friend int main();
};

double Point::Distance(Point &p) {
  double dx = x - p.x, dy = y - p.y;
  return std::sqrt(dx * dx + dy * dy);
}

int main() {
  Point p1, p2;
  std::cin >> p1.x >> p1.y
    >> p2.x >> p2.y;
  std::cout << p1.Distance(p2) << "\n";
  return 0;
}