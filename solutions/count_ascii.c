#include <stdio.h>
int main(int argc, char** argv) {
  int c = getchar();
  int count = 0;
  while (c != EOF) {
    c = getchar();
    if(c>127) { 
      printf("ascii ko\n");
      return -1;
    }
    count++;
  }
  printf("ascii ok with %d characters\n",count);
  return 0;
}
