# VSD_SQUADRON_MINI _RISCV_RESEARCH_INTERNSHIP

![image](https://github.com/user-attachments/assets/b274e917-58a5-457f-857a-661ee18211b7)


Instructor : Kunal Ghosh


# Task1 : Create GitHub repo. Install RISC-V toolchain using VDI shared over whatsapp group. Refer to C based Lab video and RISC-V based lab videos. Complete exact steps on your machine. Upload snapshot of compiled C code and RISC-V Objdmp on your GitHub repo


//Write a C code to calculate the sum of 1 to N numbers and compile with riscv compiler
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


RISV tool compiler command
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1toN_riscv.o sum1toN_riscv.c
disassembly command
riscv64-unknown-elf-objdump sum1toN_risv.o  ## output file from above command

![image](https://github.com/user-attachments/assets/a47a1172-8dd8-430c-911d-3b2b27fe3dbd)


![image](https://github.com/user-attachments/assets/7cc097b1-edc4-4dc4-b847-a915ec173fa0)


![image](https://github.com/user-attachments/assets/41713ec5-040c-4ead-abf1-0ca97b81d62d)



# Task2: SPIKE Simulation and observation with -O1 and -Ofast. Upload snapshot of compiled C Code, RISC-V Objdmp with above options on your GitHub repo. 

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

![image](https://github.com/user-attachments/assets/c71b2626-c793-4e58-a498-d17b212a414a)

![image](https://github.com/user-attachments/assets/a7bdb39c-0786-41d0-8870-46327e8c1e76)

![image](https://github.com/user-attachments/assets/81f909fb-7a28-4fce-9151-dee244633263)

![image](https://github.com/user-attachments/assets/6b51d85a-7c75-4053-8821-f884e66dffb3)

![image](https://github.com/user-attachments/assets/c62aaff5-7c13-4b63-b45c-7d3571cf084a)

![image](https://github.com/user-attachments/assets/95b7c06a-a01f-4e65-af42-bb9cec19ce68)

![image](https://github.com/user-attachments/assets/5438d670-05e5-418a-b194-f33a22794805)


![image](https://github.com/user-attachments/assets/bf1c543e-b77c-4d1f-b3d1-827b03c8cc46)




# Task 3: 1) List various RISC-V instruction type (R, I, S, B, U, J) after going through RISC-V software documentation 2) Identify 15 unique RISC-V instructions from riscv-objdmp of your application code  3) Identify exact 32-bit instruction code in the instruction type format for 15 unique instructions 4) Upload the 32-bit pattern on Github



# Task 4: Using Existing RISC-V Core Verilog netlist and testbench for functional simulation experiment. Upload waveform snapshots for the commands on your GitHub. Reference GitHub repo is here. 



# Task5: Update the repo with project name., Overview, Components Required to build your application, Circuit Connection, Pinout Diagram using ppt (current image is hand-drawn) and Table for Pin connection. Refer to this link for reference



# Applications:



# Application Video :



# Acknowledgement:
I would like to appreciate Kunal Ghosh and VSD team for this initiating the RISCV internship to gain knowledge on RISCV Architecture using VSDSquadron Mini Kit.
