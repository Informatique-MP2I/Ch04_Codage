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
bool check_utf8() {
  while(true) {
    int c1=getchar();
    if(c1==-1) return true;
    int nb_char=decode_start_char(c1);
    if(nb_char==0) return false ;
    else {
      for(int i=1;i<nb_char;i++) {
        int cn=getchar();
        if(cn==-1) return false;
        if(!check_next_char(cn)) return false ;        
      } 
    }
  }
  return true;
}
int main(int argc, char** argv) {
  if(check_utf8()) printf("utf8 ok\n");
  else printf("utf8 ko\n");
}
