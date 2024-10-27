In this task, we are going to use a pre-written verilog code which is a micro-architecture and analyse the waveforms.
This is a micro-architecture of a few important instructions of the instruction set of a Single cycle Reduced Instruction Set Computer - Five(RISC-V) Instruction Set Architecture suitable for use across wide-spectrum of Applications from low power embedded devices to high performance Cloud based Server processors.
All the registers are 32-bit long.
Below is the image of all instructions.

Instruction


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
Step-1:
-> Create a directory using command ' mkdir ' in the terminal.

$ mkdir directory_name

Step-2:
-> Set the path to the directory using command 'cd' in the terminal.

$ cd directory_name

Step-3:
-> Now, create two ' .v ' files using command ' touch ' .
-> ' .v ' is the extension for verilog files.

$ touch module_name.v
$ touch module_name_tb.v

Step-4:
-> To run the verilog code enter below commands.
Note :

While running this command, you have to be in the directory where .v files exist.
The code doesn't give us any block diagrams or elaborated designs.
$ iverilog -o directory_name module_name.v module_name_tb.v
$ ./directory_name -> From running these commands, ' .vcd ' file will be generated.
-> We use this ' .vcd ' file for simulation.

Step-5:
-> To simulate the waveforms,we are going to use ' gtkwave '.
-> To invoke gtkwave =>

gtkwave module_name.vcd

This image shows the user interface of " gtkwave " .

Gtkwave


To see the waveforms, we have to append them to the waveformsimulator.

For that, click on the signal and click on ' append '.

Append


Instructions:
The below images will show the output waveform showing the instructions performed in a 5-stage pipelined architecture.
In these images=>
' clk ' is the clock signal.
' EX_MEM_IR[31:0] is the 32-bit register storing instruction.
' ID_EX_A[31:0] ' and ' ID_EX_B[31:0] ' are the operands (32-bit registers).
' EX_MEM_ALUOUT[31:0] ' is the output 32-bit register.

Note :
We can observe the delay of " one clock cycle " in the output (sequential)=> So, we have to do operations between op1[n-1] and op2[n-1].(such as in signals)
ADD R6,R1,R2 :
ADD

-> EX_MEM_IR[31:0] = 32'h02208300.
-> Operation => 1 + 2 = 3.

SUB R7,R1,R2 :
SUB

-> EX_MEM_IR[31:0] = 02209380.
-> Operation => 1 - 2 = -1. (In signed decimal form).
-> In hexadecimal form, it is 'FFFFFFFF' (2's complement).

AND R8,R1,R3:
AND

-> EX_MEM_IR[31:0] = 32'h0230A400.
-> Operation => 1 & 3 = 1 (bitwise AND operation) -> 001 & 011 = 001.

OR R9,R2,R5:
OR

-> EX_MEM_IR[31:0] = 32'h02513480.
-> Operation => 2 | 5 = 7 (bitwise OR operation) -> 010 | 101 = 111.

XOR R10,R1,R4:
XOR

-> EX_MEM_IR[31:0] = 32'h0240C500.
-> Operation => 1 ^ 4 = 5 (bitwwise XOR operation) -> 001 ^ 100 = 101.

SLT R1,R2,R4:
SLT

-> EX_MEM_IR[31:0] = 32'h02415580.
-> SLT means ' Set if Less Than ' .For rs1 and rs2 => if rs1 < rs2 output will be ' 1 ' or else ' 0 '.
-> Operation : 2 < 4 = 1.

ADDI R12,R4,4:
ADDI

-> EX_MEM_IR[31:0] = 32'h00520600.
-> ADDI means 'Add Immediate '.
-> Operation 4 + 5 = 9.

SW R3,R1,2:
SW

-> EX_MEM_IR[31:0] = 32'h00209181.
-> SW means ' Store Word '.
-> Here Memory address = Base value in register + 12-bit offset.
-> Offset = 2 , base value = 1; Output = 3;

LW R13,R1,2:
LW

-> EX_MEM_IR[31:0] = 32'h00208681.
-> LW means ' Load Word '. -> Here Memory address = Base value in register + 12-bit offset.
-> Offset = 2 , base value = 1; Output = 3;

BEQ R0,R0,15:
BEQ (2)

-> EX_MEM_IR[31:0] = 32'h00f00002.
-> BEQ means ' Branch if Equal '.
-> We can see a new line named ' ID_EX_NPC '. It is the " Program Counter (PC) ".
-> Since the stored value in register is same as output, we have to increment PC by immediate value = 15.
-> PC = 10 (previous cycle) . Operation => 10 +15 = 25.

ADD R14,R2,R2:
ADD2


-> EX_MEM_IR[31:0] = 32'h00210700.
-> Operation => 2 + 2 = 4.



These are the instructions used in the given micro-architecture
