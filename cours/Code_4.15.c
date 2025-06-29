#include <stdio.h>
int main(int argc, char** argv){
  int n = 20;
  int sum = 0;
  for (int i=1; i<=n; i++)
    sum = sum+i;
  printf("The sum of the numbers from 1 to %d is %d.\n", n, sum);
  return 0;
}
