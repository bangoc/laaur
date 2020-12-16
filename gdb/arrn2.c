#include <stdio.h>
void print_ai(int *a, int n) {
  printf("Nội dung mảng a là:\n");
  for (int i = 0; i < n; ++i) {
    printf("a[%d] = %d\n", i, a[i]);
  }
}
int main() {
  int a[] = {[1] = 10, [7] = 200};
  int n = sizeof(a) / sizeof(a[0]);
  return 0;
}