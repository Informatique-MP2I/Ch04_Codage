#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/*
  in  : double n - a double-precision floating-point number
  out : long int - the raw bit representation of the double,
                   interpreted as a long int
 */
long int double_as_long_int(double n){
  union {
    double d;
    long int i;
  } u;
  
  u.d = n;
  return u.i;
}

/*
  in  : char c - a character
  out : void - prints the binary representation of the character
               (most significant bit first)
 */
void print_bin_char(char c) {
  printf("The binary representation of '%c' (%d) is: ", c, c);
  for (int i = 7; i >= 0; i--) {
    printf("%d", (c >> i) & 1);
  }
  printf("\n");
  return;
}

/*
  in  : int n - an integer
  out : void - prints the 32-bit binary representation of the integer
 */
void print_bin_int (int n){
  printf("The binary representation of %d : ", n);
  for (int i=31;i>=0;i--){
    printf("%d", (n>>i)&1);
  }
  printf("\n");
  
  return;
}

/*
  in  : double d - a double-precision floating-point number
  out : void - prints the 64-bit binary representation of the double
 */
void print_bin_double (double d){
  long int n = double_as_long_int(d);
  printf("The binary reprensetation of %lf : \n", d);
  for (int i=63;i>=0;i--){
    printf("%ld", (n>>i)&1);
  }
  printf("\n");
  
  return;
}

/*
  in  : double d - a double-precision floating-point number
  out : void - prints the sign, exponent, and mantissa bits of the double
 */
void print_bin_double2 (double d){
  long int n = double_as_long_int(d);
  printf("The binary representation of %lf : \n", d);

  printf("S - %ld\n", (n>>63)&1);
  printf("E - ");
  for (int i=62;i>=52;i--){
    printf("%ld", (n>>i)&1);
  }
  printf("\n");
  printf("M - ");
  for (int i=51;i>=0;i--){
    printf("%ld", (n>>i)&1);
  }
  printf("\n");
  
  return;
}

/*
  in  : double a, double b - two double-precision floating-point numbers
  out : bool - true if a * b == 1.0, false otherwise
 */
bool inverse (double a, double b) {
  return a*b == 1.0;
}

/*
  in  : none
  out : void - demonstrates floating-point addition inaccuracies with 0.1 + 0.1 + ... + 0.1
 */
void print_sum() {
  float sum = 0.0;
  
  for (int i = 0; i < 10; i++) {
    sum = sum + 0.1;
  }
  if (sum == 1.0) {
    printf("The sum is equal to 1.0.\n");
  } else {
    printf("The sum is not equal to 1.0 but to %1.10lf.\n", sum);
  }
  printf("%1.52f\n", sum-1.0);
  print_bin_double(1.0);
  print_bin_double(sum);

  return;
}

/*
  Main function
 */
int main(int argc, char** argv){
  print_bin_char('A');
  print_bin_char(48);

  print_bin_int(5);
  print_bin_int(-5);

  print_bin_int(73);
  print_bin_int(-73);

  print_bin_int(-13);

  print_bin_double(5.0);
  print_bin_double(-5.0);

  print_bin_double2(73.4);

  printf("The numbers 3 and 1/3 are inverses : %d \n",inverse(3., 1./3.));
  
  bool found = false;
  double n = 1.0;
  while (!found) {
    if (n==3) printf("%d", inverse(n, 1/n));
    if (inverse(n, 1/n)==false)
      found = true;
    else
      n=n+1;
  }
  printf("The first number found is %f.\n", n);

  print_sum();
  
  return 0;
}
