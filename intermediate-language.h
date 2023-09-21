// File: intermediate-language.h
// Author: Alan Manuel Loreto Cornidez
// Purpose: Head file for intermediate code generation.

#ifndef INTERMEDIATE_LANGUAGE_H
#define INTERMEDIATE_LANGUAGE_H

#include "symbol-table.h"
#include "syntax-tree.h"
#include <stdio.h>

typedef enum OpType {
  PLUS

} OpType;

typedef struct {
  OpType operand_type;
  union {
    int iconst; // integer const.
    symtabnode *stptr;
  } val;
} Operand;

struct instr {
  OpType op;    // PLUS, MINUS, etc.
  Operand src1; // source operand 1
  Operand src2; // source operand 2
};

/*

struct symtab_entry
{


};



// Create a symbol table entry for a new temporary
// Return a pointer to this ST entry.
struct symtab_entry *newTemp(typename t);


// Return a new label instruction.
struct instr *newLabel();



// Create a new instructinon
// Fill in the arguments suipplied
// Return a pointer to the result
struct instr *newInstr(op operation, arg_1 arg1, arg_2 arg2);

*/

// void codeGenStatement(tnode *S);

// void intermediateTreeTraversal(tnode *fn_body);

// generateIntermediate Code
// This function recursively traverses the tree and creates antermediate code
// for each of the encountered
void generateIntermediateCode(symtabnode *fn_name, tnode *fn_body);

/*
 * CleanupFnInfo() -- clean up after processing information
 * for a function prototype/definition.
 */
void generateMipsCode();

#endif // INTERMEDIATE_LANGUAGE_H
