#include "gc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  GC_INIT();
  char *str = GC_malloc(100);
  strcpy(str, "Hello world!");
  return 0;
}