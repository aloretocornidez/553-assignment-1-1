// File: intermediate-language.c
// Author: Alan Manuel Loreto Cornidez
// Purpose: Code definition file for intermediate code generation.
#include "intermediate-language.h"
#include "protos.h"
#include "symbol-table.h"
#include "syntax-tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void generateSymbolTableName(symtabnode * stnode)
{

}

// This function creates a new symbol table entry for a new temporary.
// return a pointer to this new symbol table entry.
symtabnode *newtemp(tnode *t) {
  symtabnode *ntemp = malloc(sizeof(symtabnode));

  // ntmp->name = generateSymbolTableName(); //  ...create a new name that
  generateSymbolTableName(ntemp);
  // doesn’t conflict... ntmp->type = tnode->ntype
  //
  // ...insert ntmp into the function's local symbol table...

  return ntmp;
}

// newInstr returns a pointer to a new instruction.
// This takes in as arguments:
// the operation type
// the sources and destinations.
struct instr *newInstr(OpType opType, symtabnode *src1, symtabnode *src2,
                       symtabnode *dest ) {
  struct instr *ninstr = malloc(sizeof(instr));
  ninstr->operandType = opType;
  ninstr->src1 = src1;
  ninstr->src2 = src2;
  ninstr->dest = dest;

  // Initialize pointers to the next instruction initialized as null.
  
  ninstr->previous = NULL;
  ninstr->next = NULL;

  return ninstr;
}

// stichInstructionList : attaches the tail of the first list to the head of the
// second list.
void stichInstructionList(instr *firstIstrList, instr *secondIstrList) {
  instr *temp;

  temp = firstIstrList;

  // Find the tail of the first list.
  while (temp->next != NULL) {
    temp = temp->next;
  }

  // Assign the pointer to the next instruction of the first list to the head of
  // the first list.
  temp->next = secondIstrList;

  // Assign the previous of the second list to the tail of the first list.
  secondIstrList->previous = temp;
}

// Global Variable to keep track of the label number.
static int label_num = 0;
// struct instr *newLabel(instr* instruction) {
  // return newInstr(LABEL, label_num++;);
  // return newInstr( label_num++);
  // newInstr(OpType opType, symtabnode *src1, symtabnode *src2, symtabnode *dest);
// }



// codeGenExpression this function generates the expression for each node.
void codeGenExpression(tnode *node, lr lr_value) {
  switch (node->ntype) {

  case Intcon:
    if (lr_value == L_value) {
      printf("Error: lr_value for integer constant assigned to L_value.");
      assert(0);
    } else if (lr_value == R_value) {

      // symtabnode *stnode = SymTabPtr(node);
    }
    // assert(0);
    break;

  case Var:
    if (lr_value == L_value) {
      // find the address of the variable.

    } else if (lr_value == R_value) {
    }

    // node->place = SymTabPtr(node);

    break;

  case Assg:
    // If the node is an of type assignment, then the left side is set to the
    // right side.
    //

  default:
    assert(0);
  }
}

// codeGenExpression : Stiches the code from the two child nodes.
void codeGenStatement(tnode *S) {
  switch (S->ntype) {


  case Assg:
    codeGenExpression(LChild(S), L_value);
    codeGenExpression(RChild(S), R_value);
    // Stitch the code together by stitching linked lists of instructions
    // together. The lists of instructions are gathered from the two children
    // nodes.

    // S->code = LChild(S)->code + RChild(S)->code + newInstr(Assg,
    // RChild(S)->place, NULL, LChild(S)->place);

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
    // Generate the code for the integer type node.
    codeGenStatement(fn_body);

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
    intermediateTreeTraversal(stAssg_Lhs(fn_body));
    intermediateTreeTraversal(stAssg_Rhs(fn_body));
    // After the two children of the node are processed, generate the code for
    // this node and then stich it together.
    codeGenStatement(fn_body);
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
