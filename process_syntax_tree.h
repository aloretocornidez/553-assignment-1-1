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














#endif // !PROCESS_SYNTAX_TREE_H

