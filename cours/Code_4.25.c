#include <stdio.h>
int main(int argc, char** argv) {
  for (int i = 0; i < 10; i++) {
    char c = '0' + i;
    printf("%d + '0' = '%c'\n", i, c);
  }
  char invalid = '0' + 10;
  printf("10 + '0' = '%c' (code ASCII %d)\n", invalid, invalid); 
  return 0;
}
