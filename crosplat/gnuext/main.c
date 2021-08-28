#include <stdio.h>

int main() {
  int sum = ({
    int x, y;
    printf("Nhập x và y: ");
    scanf("%d%d", &x, &y);
    x + y;
  });
  printf("sum = %d\n", sum);
  return 0;
}