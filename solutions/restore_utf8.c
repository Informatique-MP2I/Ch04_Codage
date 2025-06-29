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
bool restore_utf8() {
  int c1;
  c1=getchar();
  if(c1==-1) return true;
  if(decode_start_char(c1)==0) { 
    // wrong starting bytes -> remove the nested char
    int i;
    for(i=1;i<=3;i++) { 
      c1=getchar();
      if(c1==EOF) return false;
      if(decode_start_char(c1)!=0) break;
    }
  }
  // process the file
  while(c1!=-1) {
    int nb_char=decode_start_char(c1);
    if(nb_char==0) return false ;
    else {
      putchar(c1);
      for(int i=1;i<nb_char;i++) {
        int cn=getchar();
        if(cn==-1) return false;
        if(!check_next_char(cn)) return false ;  
        putchar(cn);      
      } 
    }
    c1=getchar();
  }
  return true;
}
int main(int argc, char** argv) {
  if(restore_utf8()) return 0;
  else return 1;
}
