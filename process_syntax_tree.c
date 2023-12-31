/*
 * File: process_syntax_tree.c
 * Purpose: Code to traverse the syntax tree of each function and
 *     perform any desired actions.
 */
#include "global.h"
#include "intermediate-language.h"
#include "protos.h"
#include "syntax-tree.h"
#include <stdio.h>
#define DEBUG DEBUG
// #include "homework0.h"

// Print the syntax tree.
extern void printSyntaxTree(tnode *t, int n, int depth);

/*
 * process_syntax_tree(fn_name, fn_body) -- fn_name is a poiner to
 * the symbol table entry of the function being processed (which can
 * be used, for example, to get the name of the fucntion); fn_body
 * is a pointer to the root of the syntax tree of the function body.
 * This function can be used to carry out tree traversals of the
 * function's syntax tree.
 */
void process_syntax_tree(symtabnode *fn_name, tnode *fn_body) {
#ifdef DEBUG
  printf("@@FUN: %s\n", fn_name->name);
  printf("@@BODY:\n");
  printSyntaxTree(fn_body, 4, 0);
  printf("-----\n");
#endif

  // Generate the Intermediate language.
  generateIntermediateCode(fn_name, fn_body);

  // Generate mips code.
  // generateMipsCode();

  return;
}
