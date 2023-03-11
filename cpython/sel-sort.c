#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./ss input.txt output.txt\n");
    return 0;
  }
  int n;
  int *a = NULL;
  FILE *inp = fopen(argv[1], "r");
  fscanf(inp, "%d", &n);
  a = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    fscanf(inp, "%d", a + i);
  }
  fclose(inp);
  
  long start = clock();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
  long end = clock();
  printf("Thời gian xử lý: %.3f s\n", (double)(end - start)/CLOCKS_PER_SEC);
  
  FILE *out = fopen(argv[2], "w");
  for (int i = 0; i < n; ++i) {
    fprintf(out, "%d ", a[i]);
  }
  fclose(out);

  free(a);
}