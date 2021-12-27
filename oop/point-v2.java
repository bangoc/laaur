import java.lang.Math;
import java.util.Scanner;

class Point {
  public double Distance (Point p) {
    double dx = x - p.x, dy = y - p.y;
    return Math.sqrt(dx * dx + dy * dy);
  }
  public Point(double x, double y) {
    this.x = x;
    this.y = y;
  }
  public void Scale(double k) {
    x *= k;
    y *= k;
  }
  private double x, y;
}

class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    Point p1 = new Point(sc.nextDouble(), sc.nextDouble()),
      p2 = new Point(sc.nextDouble(), sc.nextDouble());
    System.out.println(p1.Distance(p2));
  }
}