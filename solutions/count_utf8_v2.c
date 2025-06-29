#include <stdio.h>
#include <stdbool.h>
int decode_start_char(int c) {
  if(c>=0   && c<128) return 1;
  if(c>=192 && c<224) return 2;
  if(c>=224 && c<240) return 3;
  if(c>=240 && c<248) return 4;
  return 0; // error on c==-1 (EOF) || c>=128 && c<192 (nested char) || c>=248 (undefined)
}
bool check_next_char(int c) {
  return (c>=128 && c<192) ;
}
int count_utf8() {
  int count=0; 
  int c1=getchar();
  while(c1!=-1) {
    int nb_char=decode_start_char(c1);
    if(nb_char==0) return -1 ;
    else {
      for(int i=1;i<nb_char;i++) {
        int cn=getchar();
        if(cn==-1) return -1 ;
        if(!check_next_char(cn)) return -1 ;        
      }
      count ++; 
    }
    c1=getchar();
  }
  return count ;
}
int main(int argc, char** argv) {
  int i=count_utf8();
  if(i==-1) printf("utf8 ko\n");
  else printf("utf8 ok with %d char\n",i);
}
