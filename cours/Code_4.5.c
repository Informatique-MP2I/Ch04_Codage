#include <stdio.h>
int add_one(int nbr) {
  return nbr+1;
}
int main(int argc, char** argv){
  printf("%d\n", add_one(5));  
  return 0;
}
