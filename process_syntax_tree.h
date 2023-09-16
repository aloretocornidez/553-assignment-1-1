#ifndef PROCESS_SYNTAX_TREE_H
#define PROCESS_SYNTAX_TREE_H

#include "global.h"
#include "protos.h"
#include "syntax-tree.h"
#include <stdio.h>
#include "intermediate-language.h"



// Print the syntax tree.
extern void printSyntaxTree(tnode *t, int n, int depth);

// Generate mips code using symbol table entries. 
void generateIntermediateCode(symtabnode *fn_name, tnode *fn_body);

// Generate mips code from the generated intermediate language.
void generateMipsCode();

/*
 * process_syntax_tree(fn_name, fn_body) -- fn_name is a poiner to
 * the symbol table entry of the function being processed (which can
 * be used, for example, to get the name of the fucntion); fn_body
 * is a pointer to the root of the syntax tree of the function body.
 * This function can be used to carry out tree traversals of the
 * function's syntax tree.
 */
void process_syntax_tree(symtabnode *fn_name, tnode *fn_body);













#endif // !PROCESS_SYNTAX_TREE_H

