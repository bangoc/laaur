#include <stdio.h>
#include <complex.h>

int main() {
  complex double x = {1.0, 2.0};
  printf("Giá trị phần thực: %g\n", creal(x));
  printf("Giá trị phần ảo: %g\n", cimag(x));
  return 0;
}