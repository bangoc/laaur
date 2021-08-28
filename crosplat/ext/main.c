#include <stdio.h>

#if defined(LINUX) || defined(MACOS)
#include <termios.h>

static struct termios old, current;

void init_termios(int echo)  {
  tcgetattr(0, &old);
  current = old;
  current.c_lflag &= ~ICANON;
  if (echo) {
      current.c_lflag |= ECHO;
  } else {
      current.c_lflag &= ~ECHO;
  }
  tcsetattr(0, TCSANOW, &current);
}

void reset_termios()  {
  tcsetattr(0, TCSANOW, &old);
}

int __my_getch(int echo) {
  int ch;
  init_termios(echo);
  ch = getchar();
  reset_termios();
  return ch;
}

int my_getch() {
  return __my_getch(0);
}

int my_getche() {
  return __my_getch(1);
}
#elif defined(WINDOWS)
#include <conio.h>
#endif

int main() {
  int a = 10, b = 20;
  printf("Bấm 1 phím bất kỳ để tiếp tục.");
#if defined(LINUX) || defined(MACOS)
  my_getch();
#elif WINDOWS
  getch();
#elif MACOS

#endif
  printf("\n%d + %d = %d\n", a, b, a + b);
  return 0;
}