/*
 * File: process_syntax_tree.c
 * Purpose: Code to traverse the syntax tree of each function and
 *     perform any desired actions.
 */

#include <stdio.h>
#include "global.h"
#include "protos.h"
#include "syntax-tree.h"




static char *nodeTypeName[] ={
  "Error",
  "Intcon",
  "Charcon",
  "Stringcon",
  "Var",
  "ArraySubscript",
  "Plus",
  "UnaryMinus",
  "BinaryMinus",
  "Mult",
  "Div",
  "Equals",
  "Neq",
  "Leq",
  "Lt",
  "Geq",
  "Gt",
  "LogicalAnd",
  "LogicalOr",
  "LogicalNot",
  "FunCall",
  "Assg",
  "Return",
  "For",
  "While",
  "If",
  "STnodeList"
};

// Print the syntax tree.
extern void printSyntaxTree(tnode *t, int n, int depth);


// Print line declaration from professor.
// extern void println(int val);


/* 
 * Count the number of nodes of the passed in type.
 * treeTraversal(fn_body, count, testNode)
 * 
 */
void treeTraversal(tnode* fn_body, int* count, int testNodeType)
{

  tnode* tntmp0;


  // Check if the node exists.
  if (fn_body == NULL) {
    return;
  }

  // Increase the count of the node type if the node matches the current test node.
  if(fn_body->ntype == testNodeType)
  {
    // printf("fn_body->type matches testNodeType with value: (%d): %s\n", testNodeType, nodeTypeName[fn_body->ntype]);
    (*count)++;
    
  }

  // Iterate syntax tree with proper recursive pointers.
  switch (fn_body->ntype) {
    case Error:
    case Intcon:
    case Charcon:
    case Stringcon:
    case Var:
    break;

    case ArraySubscript:
      treeTraversal(stArraySubscript_Subscript(fn_body), count, testNodeType);

    
    break;

    case UnaryMinus:
    case LogicalNot:
      treeTraversal(stUnop_Op(fn_body), count, testNodeType);

    
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
      treeTraversal(stBinop_Op1(fn_body), count, testNodeType);
      treeTraversal(stBinop_Op2(fn_body), count, testNodeType);
    break;

    case FunCall:
      treeTraversal(stFunCall_Args(fn_body), count, testNodeType);
    break;

    case Assg:
      treeTraversal(stAssg_Lhs(fn_body), count, testNodeType);
      treeTraversal(stAssg_Rhs(fn_body), count, testNodeType);
    break;

    case Return:
      treeTraversal(stReturn(fn_body), count, testNodeType);

    break;

    case For:
      treeTraversal(stFor_Init(fn_body), count, testNodeType);
      treeTraversal(stFor_Test(fn_body), count, testNodeType);
      treeTraversal(stFor_Update(fn_body), count, testNodeType);
      treeTraversal(stFor_Body(fn_body), count, testNodeType);
    break;



    case While:
      treeTraversal(stWhile_Test(fn_body), count, testNodeType);
      treeTraversal(stWhile_Body(fn_body), count, testNodeType);
    break;

    case If:
      treeTraversal(stIf_Test(fn_body), count, testNodeType);
      treeTraversal(stIf_Then(fn_body), count, testNodeType);
      treeTraversal(stIf_Else(fn_body), count, testNodeType);
      
      
    break;

    case STnodeList:  /* list of syntax tree nodes */ 
      for (tntmp0 = fn_body; tntmp0 != NULL; tntmp0 = stList_Rest(tntmp0)) {
        treeTraversal(stList_Head(tntmp0), count, testNodeType);
      }

    break;

    default:
      fprintf(stderr, "Unknown syntax tree node type %d\n", fn_body->ntype);
  }
    








}

/*
 * process_syntax_tree(fn_name, fn_body) -- fn_name is a poiner to
 * the symbol table entry of the function being processed (which can
 * be used, for example, to get the name of the fucntion); fn_body
 * is a pointer to the root of the syntax tree of the function body.
 * This function can be used to carry out tree traversals of the
 * function's syntax tree.
 */
void process_syntax_tree(symtabnode *fn_name, tnode *fn_body)
{
#ifdef DEBUG
  printf("@@FUN: %s\n", fn_name->name);
  printf("@@BODY:\n");
  printSyntaxTree(fn_body, 4, 0);
  printf("-----\n");
#endif




  
  // Print function name
  // printf("@@FUN: %s\n", fn_name->name);
  

  // Test each possible node type and traverse the tree to get a count for the number of that node type.
  // for(int nodeType = 0; nodeType < 27; nodeType++)
  // {

  //   // Reset count
  //   int count = 0;

  //   // Count the number of nodes that match the node type.
  //   treeTraversal(fn_body, &count, nodeType);


  //   // Print the count of the node type.
  //   if(count > 0){
  //     printf("%s: %d\n", nodeTypeName[nodeType], count);
  //   }
  // }


  return;
}















void println(int val) {
printf("%d\n", val);
}