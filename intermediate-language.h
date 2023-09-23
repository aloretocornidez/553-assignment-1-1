// File: intermediate-language.h
// Author: Alan Manuel Loreto Cornidez
// Purpose: Header file for intermediate code generation.

#ifndef INTERMEDIATE_LANGUAGE_H
#define INTERMEDIATE_LANGUAGE_H
#include "symbol-table.h"
#include "syntax-tree.h"
#include <stdio.h>

typedef enum lr { L_value, R_value } lr;
// OpType is the type that I'm using to define the type of operation that a node
// is conducting.
typedef enum OpType {
  PLUS

} OpType;

// Operand is the kind of operation that is being conducted in a statement.
typedef struct Operand {
  OpType operandType;
  union {
    int iconst;        // integer const.
    symtabnode *stptr; // symbol table pointer.
  } val;
} Operand;

// instruction contains the kind of operation, the two sources and the
// destination.
typedef struct instr {
  // PLUS, MINUS, etc.
  OpType operandType;
  // source operand 1
  symtabnode* src1;
  // source operand 2
  symtabnode* src2;
  // destination of the instruction
  symtabnode* dest;
  // points to the list of the instructions
  struct instr *next;
} instr;

// Function Definitions
#if 0
// Create a symbol table entry for a new temporary
// Return a pointer to this ST entry.
struct symtab_entry *newtemp(tnode* t);

// Return a new label.
struct instr *newLabel();

// Create a new instruction
// Fill in the arguments supplied
// Return a pointer to the result
struct instr *newInstr(OpType opType, Operand src1, Operand src2, Operand dest);

// Recursive function to traverse the tree.
// Runs intermediate code generation logic while traversing.
void intermediateTreeTraversal(tnode *fn_body);

// This function generates the expression.
void codeGenExpression(tnode *node, lr valueType);

// This function generates the code statement.
void codeGenStatement(tnode *node);

// generateIntermediateCode
// This function genrates the symbol tables for all of the nodes in the syntax
// tree.
void generateIntermediateCode(symtabnode *fn_name, tnode *fn_body);

// Generate mips code from the symbol table.
void generateMipsCode();
#endif
#endif // INTERMEDIATE_LANGUAGE_H
