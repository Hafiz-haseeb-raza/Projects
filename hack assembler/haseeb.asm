// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/06/max/MaxL.asm

// Symbol-less version of the Max.asm program.

@R1
D=D+1
D=M
@R1
D=D-M
@10
D;JGT
@R1
D=M
@12
0;JMP
@0
D=M
@2
M=D
@14
0;JMP