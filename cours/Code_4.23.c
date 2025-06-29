#include <stdio.h>
int main(int argc, char **argv) {
  char c1='A'; 
  char c2='\101';
  char c3='\x41';
  char c4=65; 
  char c5=0x41;
  printf("c1 ='%c', c2='%c', c3='%c', c4='%c', c5='%c'\n",
	 c1,c2,c3,c4,c5); 
  printf("c1 =%d, c2=%d, c3=%d, c4=%d, c5=%d\n",c1,c2,c3,c4,c5); 
  printf("c1 =%x, c2=%x, c3=%x, c4=%x, c5=%x\n",c1,c2,c3,c4,c5);
  return 0;
}
