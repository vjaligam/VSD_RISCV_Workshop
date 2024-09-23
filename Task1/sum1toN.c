// Create a code that calculates the sum of 1 to N number
#include <stdio.h>
int main () {
  int i, sum =0;
  int n = 1000;
  for (i=1; i<=n; i++) {
    sum += i;
  }
  printf ("The sum of 1 to %d numbers is %d", n, sum);
  return 0;
}

The output of the code is snapshot
