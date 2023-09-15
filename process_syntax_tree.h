#ifndef PROCESS_SYNTAX_TREE_H
#define PROCESS_SYNTAX_TREE_H

#include "global.h"
#include "protos.h"
#include "syntax-tree.h"
#include <stdio.h>



static char *nodeTypeName[] = {"Error",     "Intcon",     "Charcon",
                               "Stringcon", "Var",        "ArraySubscript",
                               "Plus",      "UnaryMinus", "BinaryMinus",
                               "Mult",      "Div",        "Equals",
                               "Neq",       "Leq",        "Lt",
                               "Geq",       "Gt",         "LogicalAnd",
                               "LogicalOr", "LogicalNot", "FunCall",
                               "Assg",      "Return",     "For",
                               "While",     "If",         "STnodeList"};

// Print the syntax tree.
extern void printSyntaxTree(tnode *t, int n, int depth);





// Generate mips code using symbol table entries. 
void generateIntermediateCode();

// Generate mips code from the generated intermediate language.
void generateMipsCode();














#endif // !PROCESS_SYNTAX_TREE_H

