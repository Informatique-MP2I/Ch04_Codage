#include <stdio.h>
int main(int argc, char** argv){
  int n = 47;
  int i = n/2;
  while (i>1) {
    if (n%i == 0)
      break;
    i--;
  }
  if (i==1) 
    printf("The number %d is prime.\n", n);
  else
    printf("The greatest divisor (other than itself) of the number %d is %d.\n", n, i);
  return 0;
}

