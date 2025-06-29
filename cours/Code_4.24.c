#include <stdio.h>
int main(int argc, char** argv) {
  printf("'A' < 'Z' : %d\n", 'A' < 'Z');
  printf("'Z' < 'a' : %d\n", 'Z' < 'a');
  printf("'0' < '9' : %d\n", '0' < '9');
  printf("'9' < '@' : %d\n", '9' < '@');
  return 0;
}
