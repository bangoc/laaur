#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./gen 1000 numbers.txt\n");
    return 0;
  }
  int n;
  sscanf(argv[1], "%d", &n);
  FILE *out = fopen(argv[2], "w");
  srand(time(NULL));
  fprintf(out, "%d\n", n);
  for (int i = 0; i < n; ++i) {
    fprintf(out, "%d", rand());
    if (i < n - 1) {    
      if (i % 20 == 0) {
        fprintf(out, "\n");
      } else {
        fprintf(out, " ");
      }
    }
  }
  fclose(out);
}