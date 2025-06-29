#include <stdio.h>
int main(int argc, char** argv){
  int n = 47;
  int d = n/2;
  while (d>1 && n%d != 0) {
    d--;
  }
  if (d==1) 
    printf("The number %d is prime.\n", n);
  else
    printf("The greatest divisor (other than itself) of the number %d is %d.\n", n, d);
  return 0;
}
