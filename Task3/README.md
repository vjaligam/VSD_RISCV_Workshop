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

WhatsApp Image 2024-10-02 at 18 24 23_e72038e7


WhatsApp Image 2024-10-02 at 18 46 25_7f72f2d2


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


WhatsApp Image 2024-10-02 at 20 37 42_baee9696


B-type Instructions:
-> These are used for conditional branching.
-> They compare two registers and branch specified instruction if comparison is true.
-> Below image shows different B-type instructions.


WhatsApp Image 2024-10-02 at 20 43 44_addcfc45


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
-> Below is the image of some instructions in the object code.

