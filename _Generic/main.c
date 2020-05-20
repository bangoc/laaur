#include <math.h>
#include <stdio.h>

#define type_name(x) _Generic((x), \
            long double: "long double", \
            double: "double", \
            float: "float", \
            default: "still not specified")
#define exp(x) _Generic((x), \
            long double: expl, \
            default: exp, \
            float: expf) (x)

int main() {
  printf("type_name(1.0f) = %s\n", type_name(1.0f));
  printf("type_name(1.0) = %s\n", type_name(1.0));
  printf("type_name(1.0l) = %s\n", type_name(1.0l));
  float e_f = exp(1.0f);
  double e = exp(1.0);
  long double e_l = exp(1.0l);
  return 0;
}