#include <stdio.h>

__attribute((constructor)) void ctor() {
  printf("Constructor\n");
}

__attribute((destructor)) void dtor() {
  printf("Destructor\n");
}

int main() {
  printf("Hello world!\n");
  return 0;
}