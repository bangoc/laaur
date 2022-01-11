/*
  (C) Nguyen Ba Ngoc
  A minimal test runner tool
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *cases[] = {
  "./prog f1 c222222 data/inp1m.txt",
  "./prog f2 h111111 data/inp1m.txt",
  "./prog f3 data/inp1m.txt",
  "valgrind ./prog f1 c222222 data/inp1m.txt",
  "valgrind ./prog f2 h111111 data/inp1m.txt",
  "valgrind ./prog f3 data/inp1m.txt"
};

char *real_command(const char *cmd) {
  static char buff[1024];
  strcpy(buff, "/usr/bin/time -f \"\\tTime: %E real,\\tMemory: %M Kb\" ");
  strcat(buff, cmd);
  return buff;
}

int main() {
  int n = sizeof(cases)/sizeof(cases[0]);
  for (int i = 0; i < n; ++i) {
    const char *command = real_command(cases[i]);
    printf("case %d: %s\n", i + 1, cases[i]);
    system(command);
    printf("Press Enter to continue...");
    while (getchar() != '\n') ;
  }
  return 0;
}