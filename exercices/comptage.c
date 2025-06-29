#include <stdio.h>
int main(int argc, char** argv) {
  int c = getchar();
  while (c != EOF) {
    c = getchar();
    putchar(c);
  }
  return 0;
}
