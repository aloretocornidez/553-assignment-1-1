# 553-assignment-1-1


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

## Behavior
### General
The executable that implements your compiler should be called compile. It will take its input from stdin and generate MIPS assembly code to stdout. Error messages, if any, will be sent to stderr.

### I/O
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

| Example 1 | Example 2 |
| --- | --- |
| Input program: 

```c 
extern void println(int x);
int main (){
    println(34567);
}
```
| 
Input
|












