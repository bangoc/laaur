/*
  Minh họa vấn đề bộ nhớ đệm khi đọc từ luồng dữ liệu văn bản và
  cách xóa bộ nhớ đệm,
  Ví dụ:
  Nhập 2 số nguyên a, b sau đó nhập 1 ký tự là phép toán +/- rồi
  đưa ra kết quả phép toán.
*/

#include <stdio.h>

char *read_ptr = NULL;
void update_ptr() {
  read_ptr = stdin->_IO_read_ptr;
}

int main() {
  int a, b;
  printf("Nhập 2 số nguyên: ");
  scanf("%d%d", &a, &b);
  // while (getchar() != '\n') ;
  char op;
  printf("Nhập phép toán [+/-]: ");
  scanf("%c", &op);
  if (op == '+') {
    printf("%d + %d = %d\n", a, b, a + b);
  } else if (op == '-') {
    printf("%d - %d = %d\n", a, b, a - b);
  } else {
    printf("Phép toán không hợp lệ.\n");
  }
  return 0;
}
