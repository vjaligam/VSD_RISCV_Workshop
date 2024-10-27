# VSD_SQUADRON_MINI _RISCV_RESEARCH_INTERNSHIP

![image](https://github.com/user-attachments/assets/b274e917-58a5-457f-857a-661ee18211b7)


Instructor : Kunal Ghosh


# Task1 : Create GitHub repo. Install RISC-V toolchain using VDI shared over whatsapp group. Refer to C based Lab video and RISC-V based lab videos. Complete exact steps on your machine. Upload snapshot of compiled C code and RISC-V Objdmp on your GitHub repo

https://github.com/vjaligam/VSD_RISCV_Workshop/blob/main/Task1/README.md 

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

https://github.com/vjaligam/VSD_RISCV_Workshop/blob/main/Task42/README.md 

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

https://github.com/vjaligam/VSD_RISCV_Workshop/blob/main/Task3/README.md 

In this task, we are going to learn about different types of instruction formats in RISC-V.
There are 6 types of instruction formats as shown below.

![image](https://github.com/user-attachments/assets/d9fe4290-5880-4bca-93df-a08fd0a84005)

Here, "op" represents a 7-bit instruction operator code, its role is to distinguish between different instructions.
"fun3" represents a 3-bit function code.it is an additional opcode.
"fun7" represents a 7-bit function code, which can help distinguish different kinds of instructions.
"rs1" and "rs2" represent two 5-bit source registers.
"rd" is a 5-bit destination register, and the result of the instruction operation is stored in rd.
"imm" represents an immediate number of different lengths, which can be used directly as an operand.
R-type Instructions:
-> It is a 32-bit instruction format.
-> These instructions use 3 register inputs.
-> Two registers are used as source operands (rs1 and rs2).
-> One desination register (rd).
-> Arithmetic and logical instructions comes under this format. Ex: add,xor,mul etc.
-> Arithmetic and logical operations between registers.


-> Below images show different types of funct3 and funct7 and opcodes of R-type instructions.
![image](https://github.com/user-attachments/assets/efe8f8a7-0c7e-4f6d-9ab6-9d26ca40a8dd)
![image](https://github.com/user-attachments/assets/4026b13d-d1ea-491a-9d51-c3ab55a91aa0)


-> Here, we can see that "opcode" for all R-type instructions is "0110011" and "funct7" is "0000000" for all except for subtraction "0100000".
-> From above image:

ADD : Addition
SUB : Subtraction
SLL : Shift Left Logical
SLT : Set Less Than
SLTU : Set Less Than Unsigned
XOR : Bitwise xor
SRL : Shift Right Logical
SRA : Shift Right Arithmetic
OR : Bitwise OR
AND : Bitwise AND
I-Type Instructions:
-> These are called as "Immediate" instructions which are used for operations involving immediate value.
-> These perform arithmetic and logical operations where one operand is a constant(immediate).
-> This type of instrutions contains "funct3", "rs1","rd","opcode" and "imm".
-> I type instruction uses 12-bit immediate value ranging from -2047 to 2048.
-> Some of the I-type instructions are =>

LI : Load Immediate.
li rd,imm

-> It loads a constant "imm" into "rd".

ADDI : Add Immediate.
addi rd,rs1,imm

-> It adds signed immediate "imm" to value in "rs1" and stores in "rd".

SUBI : Subtract Immediate.
subi rd,rs1,imm

-> It subtracts signed immediate "imm" from value in "rs1" and stores it in "rd".

SLTI : Set Less Than Immediate.
slti rd,rs1,imm

-> It sets destination register to '1' if value in "rs1" is less than value in "imm" or else set to '0'.

ORI : OR Immediate.
ori rd,rs1,imm

-> It performs a bitwise OR operation between "rs1" and "imm" values.

SLLI : Shift Left Logical Immediate.
slli rd,rs1,imm

-> It left shifts the value in "rs1" by the value given in "imm" and stores it in rd.The vacated bits are filled with 'zeroes'.

SRLI : Shift Right Logical Immediate.
srli rd,rs1,imm

-> It right shifts the value in "rs1" by the value given in "imm" and stores it in rd.The vacated bits are filled with 'zeroes'.

SRAI : Shift Right Arithmetic Immediate.
srai rd,rs1,imm

-> It right shifts the value in "rs1" by the value given in "imm" and stores it in rd.The vacated bits are filled with 'sign bit'.


-> Below are some load instructions of I-type.

![image](https://github.com/user-attachments/assets/4a7ad643-92c8-4cf7-aab6-cfda5262fbb0)


B-type Instructions:
-> These are used for conditional branching.
-> They compare two registers and branch specified instruction if comparison is true.
-> Below image shows different B-type instructions.


![image](https://github.com/user-attachments/assets/74bfab2c-10e1-463c-afd4-e52e1bffd1b6)



-> Opcode reamins "1100011".
-> Target Address = PC(program Counter) + Immediate Target address.
-> From above image:

BEQ : Branch Equal to
BNEQ : Branch Not Equal to
BGE : Branch Greater than or Equal to
BLT : Branch Less Than
-> U means 'unsigned' in BGEU and BLTU.
U-type Instructions:
-> U means "Upper Immediate".
-> These are designed to work with large immediate values.
-> These involve loading or adding a 20-bit immediate value to either a register or PC(Program Counter).<br/. -> Below are some U-type instructions:

LUI : Load Upper Immediate
-> It loads 20-bit immediate value into upper 20 bits of a register,setting lower 12 bits to 'zero'.It is used to create large constants or prepare base address for further operations.


AUIPC : Add Upper Immediate to PC
-> It adds 20-bit immediate value,shifted left by 12 bits to current value of PC.


J-type Instructions:
-> These are called as Jump Instructions.
-> These are used to alter the flow of execution by setting PC to a specified address.
-> These instructions can be conditional and unconditional.
-> One of the main jump instructions in RISC-V is:

JAL : Jump and Link.
-> It performs unconditional jump to a target address.It also stores return address in 'rd'.
-> Used typically for function calls.

Below is the image of  instructions in my object code.

![image](https://github.com/user-attachments/assets/6958c366-98d7-4a39-8b8d-5db4b11ab6f8)


# Task 4: Using Existing RISC-V Core Verilog netlist and testbench for functional simulation experiment. Upload waveform snapshots for the commands on your GitHub. Reference GitHub repo is here. 

https://github.com/vjaligam/VSD_RISCV_Workshop/blob/main/Task4/README.md 

In this task, we are going to use a pre-written verilog code which is a micro-architecture and analyse the waveforms.
This is a micro-architecture of a few important instructions of the instruction set of a Single cycle Reduced Instruction Set Computer - Five(RISC-V) Instruction Set Architecture suitable for use across wide-spectrum of Applications from low power embedded devices to high performance Cloud based Server processors.
All the registers are 32-bit long.
Below is the image of all instructions.

# Instruction


Now we are going to debug an instruction.
-> Let us take " add r6,r1,r2 ".
Given 32'h02208300.
0000 0010 0010 0000 1000 0011 0000 0000
It can be written as =>
funct7 = 0000001.
rs2 = 00010 (which is r2).
rs1 = 00001 (which is r1).
funct3 = 000.
rd = 00110 (which is r6).
opcode = 0000000.
From this, we can write the expression as => " ADD R6,R1,R2 ".

To implement this verilog code and simulate waveforms, we need to follow below steps.
In the below steps, ' directory ' and ' module ' names are of your choice.
Note : ' $ ' need not to be typed in the terminal.
# Step-1:
-> Create a directory using command ' mkdir ' in the terminal.

$ mkdir directory_name

# Step-2:
-> Set the path to the directory using command 'cd' in the terminal.

$ cd directory_name

# Step-3:
-> Now, create two ' .v ' files using command ' touch ' .
-> ' .v ' is the extension for verilog files.

$ touch module_name.v
$ touch module_name_tb.v

# Step-4:
-> To run the verilog code enter below commands.
Note :

While running this command, you have to be in the directory where .v files exist.
The code doesn't give us any block diagrams or elaborated designs.
$ iverilog -o directory_name module_name.v module_name_tb.v
$ ./directory_name -> From running these commands, ' .vcd ' file will be generated.
-> We use this ' .vcd ' file for simulation.

# Step-5:
-> To simulate the waveforms,we are going to use ' gtkwave '.
-> To invoke gtkwave =>

gtkwave module_name.vcd


To see the waveforms, we have to append them to the waveformsimulator.

# Instructions:
The below images will show the output waveform showing the instructions performed in a 5-stage pipelined architecture.
In these images=>
' clk ' is the clock signal.
' EX_MEM_IR[31:0] is the 32-bit register storing instruction.
' ID_EX_A[31:0] ' and ' ID_EX_B[31:0] ' are the operands (32-bit registers).
' EX_MEM_ALUOUT[31:0] ' is the output 32-bit register.

Note :
We can observe the delay of " one clock cycle " in the output (sequential)=> So, we have to do operations between op1[n-1] and op2[n-1].(such as in signals)
# ADD R6,R1,R2 :
ADD

-> EX_MEM_IR[31:0] = 32'h02208300.
-> Operation => 1 + 2 = 3.

# SUB R7,R1,R2 :
SUB

-> EX_MEM_IR[31:0] = 02209380.
-> Operation => 1 - 2 = -1. (In signed decimal form).
-> In hexadecimal form, it is 'FFFFFFFF' (2's complement).

# AND R8,R1,R3:
AND

-> EX_MEM_IR[31:0] = 32'h0230A400.
-> Operation => 1 & 3 = 1 (bitwise AND operation) -> 001 & 011 = 001.

# OR R9,R2,R5:
OR

-> EX_MEM_IR[31:0] = 32'h02513480.
-> Operation => 2 | 5 = 7 (bitwise OR operation) -> 010 | 101 = 111.

# XOR R10,R1,R4:
XOR

-> EX_MEM_IR[31:0] = 32'h0240C500.
-> Operation => 1 ^ 4 = 5 (bitwwise XOR operation) -> 001 ^ 100 = 101.

# SLT R1,R2,R4:
SLT

-> EX_MEM_IR[31:0] = 32'h02415580.
-> SLT means ' Set if Less Than ' .For rs1 and rs2 => if rs1 < rs2 output will be ' 1 ' or else ' 0 '.
-> Operation : 2 < 4 = 1.

# ADDI R12,R4,4:
ADDI

-> EX_MEM_IR[31:0] = 32'h00520600.
-> ADDI means 'Add Immediate '.
-> Operation 4 + 5 = 9.

# SW R3,R1,2:
SW

-> EX_MEM_IR[31:0] = 32'h00209181.
-> SW means ' Store Word '.
-> Here Memory address = Base value in register + 12-bit offset.
-> Offset = 2 , base value = 1; Output = 3;

# LW R13,R1,2:
LW

-> EX_MEM_IR[31:0] = 32'h00208681.
-> LW means ' Load Word '. -> Here Memory address = Base value in register + 12-bit offset.
-> Offset = 2 , base value = 1; Output = 3;

# BEQ R0,R0,15:
BEQ (2)

-> EX_MEM_IR[31:0] = 32'h00f00002.
-> BEQ means ' Branch if Equal '.
-> We can see a new line named ' ID_EX_NPC '. It is the " Program Counter (PC) ".
-> Since the stored value in register is same as output, we have to increment PC by immediate value = 15.
-> PC = 10 (previous cycle) . Operation => 10 +15 = 25.

# ADD R14,R2,R2:
ADD2


-> EX_MEM_IR[31:0] = 32'h00210700.
-> Operation => 2 + 2 = 4.



# Task5: Update the repo with project name., Overview, Components Required to build your application, Circuit Connection, Pinout Diagram using ppt (current image is hand-drawn) and Table for Pin connection. Refer to this link for reference

https://github.com/vjaligam/VSD_RISCV_Workshop/blob/main/Task5/README.md

The whole idea of this application is without using anything external like jumper wires, BreadBoard,etc. how we can show/demonstrate VSD SquandronMini board working.

This is a LED program using GPIO pin (PD6) when A is greater than B it will blink and when A is equal to B it wll reset and when A is less than B, it will blink. The project is based on the PlatformIO framework.

Application code written in VS and build completed successfully without any errors

![image](https://github.com/user-attachments/assets/78ec6ee7-2700-4e21-86c4-895a45af3dfb)

Application code running on SquadronMini Board in VS without any errors
![image](https://github.com/user-attachments/assets/f947b941-4ac4-480b-ae8f-6acce38a5ac7)

# Application:

#PlatformIO Compare LED application
The whole idea of this application is without using anything external like jumper wires, BreadBoard,etc. how we can show/demonstrate VSD SquandronMini board working.
This is a LED  program using GPIO pin (PD6) when A is equalto B it will blink and when A is greater than B it wll reset and when A is less than B, it will blink. The project is based on the PlatformIO framework.


# Application Video :

https://github.com/vjaligam/VSD_RISCV_Workshop/blob/main/Task5/VID_20241027010734.mp4

# Acknowledgement:
I would like to appreciate Kunal Ghosh and VSD team for this initiating the RISCV internship to gain knowledge on RISCV Architecture using VSDSquadron Mini Kit.
