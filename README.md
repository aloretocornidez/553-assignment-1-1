# 553-assignment-1-1
CSC 553: Principles of Compilation

Programming Assignment 1 (Code Generation)
Milestone 1: Handling function calls and returns

Start: Tuesday September 5th, 2023
Due: 11:50 PM Friday September 15th, 2023

# General
This assignment involves generating code for C--. 
You will write code to traverse the syntax tree for each function in a program and generate three-address statements, then translate these into MIPS assembly code and output the assembly code generated.
Your code generator should reuse temporaries as far as possible.

For intermediate code generation, you can use the three-address instruction set given here; a translation from this instruction set to MIPS assembly code is given here.
You are not required to adhere to this particular three-address instruction set, and are free to deviate from it if you want; however, if you do you will have to work out the mapping to MIPS assembly code yourself.
*Note*: Even though the intermediate code plays a relatively small role in this assignment, future assignments will involve dataflow analysis and machine-independent optimization using the intermediate code generated from this assignment.

# Scope of this milestone
For this milestone my test cases will consider only the following subset of C--. 
You are, of course, free to go beyond this subset and implement additional features of C--: that will mean less work for subsequent milestones.
But this is what I will test.
## Global and local variables 
Scalar variables of type int and char. No arrays.

## Function bodies A sequence of statements.
Each statement is as described below. 

Statements
- Assignment statements.
- Function calls.

No *if*, *while*, *for*, or *return* statements.

Expressions appearing on the right-hand side of assignments and as arguments to function calls are limited to those described below.

Expressions
- Integer constants
- Scalar variables

No operators, no array references, no function calls.

# Behavior
## General
The executable that implements your compiler should be called compile. It will take its input from stdin and generate MIPS assembly code to stdout. Error messages, if any, will be sent to stderr.

## I/O
Your programs will print out values using the following routine:

```c
void println(int val){
    printf("%d\n", val);
}
```
To make type checking work, these will be declated as **externs** in the input programs. For example:
```c 
extern void println(int x)''

void main(void)
{
    int x;
    x = 123;
    println(x);
}
```

The examples below show the output generated when the code generated from the input program is executed on SPIM:

*Example 1*
Input program
```c 
extern void println(int x);
int main (){
    println(34567);
}
```
*SPIM Output*
```
SPIM Version 8.0 of January 8, 2010
Copyright 1990-2010, James R. Larus.
All Rights Reserved.
See the file README for a full copyright notice.
Loaded: /usr/lib/spim/exceptions.s
34567
```

*Example 2* 
Input Program:
```c 
extern void println(int x);
int main() {
    int x;
    x = 12345;
    println(x);
}
```
*SPIM Output*
```
SPIM Version 8.0 of January 8, 2010
Copyright 1990-2010, James R. Larus.
All Rights Reserved.
See the file README for a full copyright notice.
Loaded: /usr/lib/spim/exceptions.s
12345
```


Note that the input program uses `println()` but does not **define** it.
This is similar to the way we use library functions like `prinft()`.
To make this work, your compiler should generate the following sequence of `MIPS` instructions for `println()`.
(This is conceptually analogous to linking in the library code for `printf()` statically).

```mips

.align 2
.data
_nl: .asciiz "\n"

.align 2
.text
# println: print out an integer followed by a newline
_println:
    li $v0, 1
    lw $a0, 0($sp)
    syscall
    li $v0, 4
    la $a0, _nl
    syscall
    jr $ra
```


## Makefile
You should submit a `Makefile` that provides (at least) the following targets:

`make clean`: Deletes any object files (*.o) as well as the file 'compile'

`make compile`: Compiles all the files from scratch and creates an executable file named 'compile'



# Gotchas to Watch Out For

- Variables and funciton names in the input program that conflict with MIPS opcodes, e.g., **b**. 
    - The simlest way to guard agains such conflcts is to add an underscore "_" at the front of each identifier in the generated code. (This is the reason the label for the function `println()` in the code shown in section 3.2 is `_println`.)
    - If you do, howeve,r you should keep in minde that execution still needs to begin at `main` (which then jumps to `_main`). The simplest way to handle this is to have the code generated create a label `main` whose code is a single unconditional jump to `_main:`
    ```
    main:
    j _mainSPIM Version 8.0 of January 8, 2010
Copyright 1990-2010, James R. Larus.
All Rights Reserved.
See the file README for a full copyright notice.
Loaded: /usr/lib/spim/exceptions.s
12345
    ```
- Large integer constants: Immediate operands can be at most 16 bits wide. Loading a constant more than 16 bits wide into a register requires two instructions.


# Running the Generated MIPS Code
I will run the `MIPS` assembly code generated by your compiler using `spim-stats`, a version of `SPIM` that provide statistics on different kinds of instructions executed by a program.
(**Note:** For this assignment I will only test whther the code generated by your compiler behaves gorrectly.
Instruction execution counts will be used to evaluate the effects of optimizations once we get to that point.)






urce code for `spim-stats` is available as a zipped file and also on the CD Department server `lectura` in the directory `/home/cs553/fall23/spim-stats`; the executable for this version of `SPIM` is on `lectura` in the file `/home/cs553/spring23/bin/spim`

To run `SPIM` on a file `foo.s` containing `MIPS` assembly code, use:

```
spim -file foo.s
```

To get execution count statistics, use:
```
spim -keepstats -file foo.s
```

For example: The following two files are the soure and MIPS assembly code for a program to compute and print out the value `factorial(7)`:
```
fact.c
fact.s
```

When we run it on SPIM using the command `sprim -keepstats -file fact.s`, the generated output is:

```
5040
States -- #instructions : 307
          #reads : 84   #writes 69  #branches 31    #other  123
```

The first line is the output from the program; the last two lines are statistics about the executed instrucitons.

# Submitting your work
Submit your work in GradeScope in the submission area created for this assignment. You should submit the following files:

- All files neeed to build an executable of your compiler.
- A `Makefile` that suppors the functionality described above.



























