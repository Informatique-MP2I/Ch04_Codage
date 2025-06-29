#include <stdio.h>
int main(int argc, char** argv){
  int n = 20;
  int sum = 0;
  int i = 0;
  while (i<=n) {
    sum = sum+i;
    i++;
  }
  printf("The sum of the numbers from 1 to %d is %d.\n", n, sum);
  return 0;
}
