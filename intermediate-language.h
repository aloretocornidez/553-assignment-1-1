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
  PLUS,
  MINUS,
  TIMES,
  DIVIDE

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
  symtabnode *src1;
  // source operand 2
  symtabnode *src2;
  // destination of the instruction
  symtabnode *dest;

  struct instr *label;


  // points to the next instructions that pertain to each node.
  // (Makes this data structure a linked list.)
  struct instr *next;
  struct instr *previous;
} instr;



/* 
 * ----------------------------------------
 *
 *          Function Definitions
 *
 * ----------------------------------------
 */

// stichInstructionList : attaches the tail of the first list to the head of the 
void stichInstructionList(instr *firstList, instr *secondHead);

void generateIntermediateCode(symtabnode* fn_name, tnode* fn_body);




#endif // INTERMEDIATE_LANGUAGE_H
