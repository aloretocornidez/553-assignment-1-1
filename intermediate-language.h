// File: intermediate-language.h
// Author: Alan Manuel Loreto Cornidez
// Purpose: Header file for intermediate code generation.

#ifndef INTERMEDIATE_LANGUAGE_H
#define INTERMEDIATE_LANGUAGE_H

#include "symbol-table.h"
#include "syntax-tree.h"
#include <stdio.h>

// OpType is the type that I'm using to define the type of operation that a node
// is conducting.
typedef enum OpType {
  PLUS,
  symbolTableEntry

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
typedef struct instruction {
  // PLUS, MINUS, etc.
  OpType op;
  // source operand 1
  Operand src1;
  // source operand 2
  Operand src2;
  // destination of the instruction
  Operand destination;

  // points to the list of the instructions
  struct instruction *next;
} instruction;

// lr : contains whether or not a
typedef enum lr { L_value, R_value } lr;

/*
 * Functions that are given in the presentation slides.
 */
struct symbolTableEntry *newtemp(tnode t);
// Return a new label.
struct instruction *newLabel();

// Return a new instruction.
struct instruction *newInstr(OpType opType, Operand src1, Operand src2,
                             Operand dest);

/*
 * Function Prototypes
 *
 */
void intermediateTreeTraversal(tnode *fn_body);

// generateIntermediateCode | This function recursively traverses the tree and
// creates intermediate code for each of the encountered
void generateIntermediateCode(symtabnode *fn_name, tnode *fn_body);

// This function generates the expression.
void codeGenExpression(tnode *node, lr valueType);

// This function generates the code statement.
void codeGenStatement(tnode *node);

void generateMipsCode();

/*
// Create a symbol table entry for a new temporary
// Return a pointer to this ST entry.
struct symtab_entry *newTemp(typename t);


// Create a new instruction
// Fill in the arguments suipplied
// Return a pointer to the result
struct instr *newInstr(op operation, arg_1 arg1, arg_2 arg2);
*/

#endif // INTERMEDIATE_LANGUAGE_H
