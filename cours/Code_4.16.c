#include <stdio.h>
int main(int argc, char** argv){
  int n = 47;
  int i;
  for (i=n/2; i>1; i--){
    if (n%i == 0)
      break;
  }
  if (i==1) 
    printf("The number %d is prime.\n", n);
  else
    printf("The greatest divisor (other than itself) of the number %d is %d.\n", n, i); 
  return 0;
}
