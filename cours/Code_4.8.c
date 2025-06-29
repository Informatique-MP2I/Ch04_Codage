#include <stdio.h>
int add_one(int nbr) {
  nbr = nbr + 1;
  return nbr;
}
int main(int argc, char** argv){
  int nbr = 5;
  printf("%d - %d\n", add_one(nbr), nbr);  
  return 0;
}
