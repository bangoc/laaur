#include <stdio.h>
int main() {
	int a[] = {[1] = 10, [7] = 200};
  int n = sizeof(a) / sizeof(a[0]);
  return 0;
}
