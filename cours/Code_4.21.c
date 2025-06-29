#include <stdio.h>
int collatz_distance(int n) {
  int steps = 0;
  int x = n;
  while (x != 1) {
    if (x % 2 == 0)
      x /= 2;
    else
      x = 3 * x + 1;
    steps++;
  }
  return steps;
}
int main(int argc, char **argv) {
  int n=14;
  int steps = collatz_distance(n);
  printf("The number of steps to reach %d is %d.\n", n, steps);
  return 0;
}

