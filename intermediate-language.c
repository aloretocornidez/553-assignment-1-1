// File: intermediate-language.c
// Author: Alan Manuel Loreto Cornidez
// Purpose: Code definition file for intermediate code generation.
#include "intermediate-language.h"

/*
struct symtab_entry *newTemp(typename t)
{

    struct symtab_entry *ntmp = malloc(sizeof(t));
    // ntmp->name = ...create a new name that doesn't conflict.
    // ntmp->type = t
    // ... insert ntmp into the function's local symbol table....
    return ntmp;
}

// Global Variable to keep track of the label number.
static int label_num = 0;
struct instr *newLabel()
{
    return newInstr(LABEL, label_num++;);
}

struct instr *newInstr(operation opType, arg_1 src1, arg_2 src2, destination dest)
{
    struct instr *ninstr = malloc();
    ninstr->op = opType;
    ninstr->src1 = src1;
    ninstr->src2 = src2;
    ninstr->dest = dest;
}




codeGen_stmt(S)
{
    condeGen_expr(LHS, L_value_);
    condeGen_expr(RHS, R_value_);
    S.code = LHS.code + RHS.code + newInstr(ASSG, RHS.place, NULL, LHS.place);
}


*/



 
 

// generateIntermediate Code
// This function recursively traverses the tree and creates antermediate code for each of the encountered 
void generateIntermediateCode()
{
  // Recursively traverse the syntax tree
  

  // Code for each node is a list of three-address instructions

  // Generate code for each node after processing its children
  
  // At each syntax tree node, create  alist of instructions that executes the computation for the syntax tree rooted at the node
  
  // Glue together the instructions for its children, plus code specific to that node.





}

/*
 * CleanupFnInfo() -- clean up after processing information
 * for a function prototype/definition.
 */
void generateMipsCode()
{

}

