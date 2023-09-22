// File: intermediate-language.c
// Author: Alan Manuel Loreto Cornidez
// Purpose: Code definition file for intermediate code generation.
#include "intermediate-language.h"
#include "protos.h"
#include "symbol-table.h"
#include "syntax-tree.h"
#include <assert.h>
#include <stdlib.h>

// This function creates a new symbol table entry for a new temportary.
// return a pointer to this new symbol tabl entry.
struct symtab_entry *newtemp(tnode t) {
  struct symtab_entry *ntmp = malloc(sizeof(tnode));
  // ntmp->name = ; //  ...create a new name that doesn’t conflict...
  // ntmp->type = tnode->ntype
  // ...insert ntmp into the function's local symbol table...
  return ntmp;
}

// Global Variable to keep track of the label number.
static int label_num = 0;
struct instr *newLabel() {
  // return newInstr(LABEL, label_num++;);
  return newInstr(LABEL, label_num++;);
  
}

// TODO: Fill in fariables and variable types.
// Create a new instruction, fill in the arugments.
// Return a pointer to the  result.
struct instr *newInstr(OpType opType, Operand src1, Operand src2,Operand dest) {
  struct instr *ninstr = malloc(sizeof(instruction));
  // ninstr->operandType = opType;
  // ninstr->src1 = src1;
  // ninstr->src2 = src2;
  // ninstr->dest = dest;
}

// codeGenExpression makes the
void codeGenExpression(tnode *node, lr valueType) {
  switch (node->ntype) {
  case Intcon:
    assert(0);
    break;

  case Var:
    node->place = SymTabPtr(node);
    break;

  default:
    assert(0);
  }
}

// Conde Generation Statement makes the
void codeGenStatement(tnode *S) {
  switch (S->ntype) {

  case Assg:
    codeGenExpression(LChild(S), L_value);
    codeGenExpression(RChild(S), R_value);
    // Append different pieces of code.
    // S->code = LChild(S)->code + RChild(S)->code + newInstr(Assg,
    // RChild(S)->place, NULL, LChild(S)->place);

    // Stitch the code together by stitching linked lists together.

    break;

  case Return:
    assert(0);
    break;

  case For:
    assert(0);
    break;

  case While:
    assert(0);
    break;

  case If:
    assert(0);
    break;

  case STnodeList:
    assert(0);
    break;

  default:
    assert(0);
    break;
  }
}

void intermediateTreeTraversal(tnode *fn_body) {

  tnode *tntmp0;

  // Check if the node exists.
  if (fn_body == NULL) {
    return;
  }

  // Iterate syntax tree with proper recursive pointers.
  switch (fn_body->ntype) {
  case Error:
  case Intcon:
    // Generate the code for
    break;

  case Charcon:
  case Stringcon:
  case Var:
    break;

  case ArraySubscript:
    intermediateTreeTraversal(stArraySubscript_Subscript(fn_body));

    break;

  case UnaryMinus:
  case LogicalNot:
    intermediateTreeTraversal(stUnop_Op(fn_body));
    break;

  case Plus:
  case BinaryMinus:
  case Mult:
  case Div:
  case Equals:
  case Neq:
  case Leq:
  case Lt:
  case Geq:
  case Gt:
  case LogicalAnd:
  case LogicalOr:
    intermediateTreeTraversal(stBinop_Op1(fn_body));
    intermediateTreeTraversal(stBinop_Op2(fn_body));
    break;

  case FunCall:
    intermediateTreeTraversal(stFunCall_Args(fn_body));
    break;

  case Assg:
    //
    intermediateTreeTraversal(stAssg_Lhs(fn_body));
    intermediateTreeTraversal(stAssg_Rhs(fn_body));
    break;

  case Return:
    intermediateTreeTraversal(stReturn(fn_body));
    break;

  case For:
    intermediateTreeTraversal(stFor_Init(fn_body));
    intermediateTreeTraversal(stFor_Test(fn_body));
    intermediateTreeTraversal(stFor_Update(fn_body));
    intermediateTreeTraversal(stFor_Body(fn_body));
    break;

  case While:
    intermediateTreeTraversal(stWhile_Test(fn_body));
    intermediateTreeTraversal(stWhile_Body(fn_body));
    break;

  case If:
    intermediateTreeTraversal(stIf_Test(fn_body));
    intermediateTreeTraversal(stIf_Then(fn_body));
    intermediateTreeTraversal(stIf_Else(fn_body));

    break;

  case STnodeList: /* list of syntax tree nodes */
    for (tntmp0 = fn_body; tntmp0 != NULL; tntmp0 = stList_Rest(tntmp0)) {
      intermediateTreeTraversal(stList_Head(tntmp0));
    }

    break;

  default:
    fprintf(stderr, "Unknown syntax tree node type %d\n", fn_body->ntype);
  }
}

// generateIntermediate Code
// This function recursively traverses the tree and creates antermediate code
// for each of the encountered nodes.
void generateIntermediateCode(symtabnode *fn_name, tnode *fn_body) {
  // Recursively traverse the syntax tree
  intermediateTreeTraversal(fn_body);

  /* Code for each node is a list of three-address instructions

   Generate code for each node after processing its children

   At each syntax tree node, create  alist of instructions that executes the
   computation for the syntax tree rooted at the node

   Glue together the instructions for its children, plus code specific to that
   node.

  */
}
