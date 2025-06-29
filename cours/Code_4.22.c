#include <stdio.h>
int main(int argc, char** argv) { 
  int c;
  while (1) {
    c = getchar();
    if (c==EOF) return 0;
    putchar(c);
  }
  /* this point is never reached */
}
