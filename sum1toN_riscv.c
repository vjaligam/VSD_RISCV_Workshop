#Write a C code to calculate the sum of 1 to N numbers and compile with riscv compiler
#include <stdio.h>
int main() {
  int i, sum =0;
  int N = 1000;
  for (i=1; i<=N; i++) {
    sum += i;
  }
  printf ("The sum of 1 to %d numbers is %d", N, sum);
  return 0;
}


## RISV tool compiler command
# riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1toN_riscv.o sum1toN_riscv.c
## disassembly command
# riscv64-unknown-elf-objdump sum1toN_risv.o  ## output file from above command
