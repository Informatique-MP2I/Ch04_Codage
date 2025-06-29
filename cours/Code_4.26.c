#include <stdio.h>
int main(int argc, char** argv) {
  char upper = 'A';
  char lower = upper + 32;
  printf("Uppercase '%c' to lowercase '%c'\n", upper, lower);
  upper = 'Z';
  lower = upper + 32;
  printf("Uppercase '%c' to lowercase '%c'\n", upper, lower);
  lower = 'a';
  upper = lower - 32;
  printf("Lowercase '%c' to uppercase '%c'\n", lower, upper);
  lower = '0';
  upper = lower + 32;
  printf("Digit '%c' to 'garbage' '%c'\n", lower, upper);
  return 0;
}
