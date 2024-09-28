//#Simulate the riscv code with SPIKE Simulator and debug through the code
//#Command to invoke the spike riscv simulator is
//spike pk <objectcode.o> 
//#With debug option
//spike -d pk <objectcode.0>

#include <stdio.h>

int main () {
  int i, sum=0;
  int N=100;
  for (i=1; i<=N; i++) {
    sum += i;
    }
  printf ("The sum of 1 to %d number is : %d \n", N, sum);
  return 0;
}
