#ifndef HOMEWORK_0_H
#define HOMEWORK_0_H

#include "global.h"
#include "protos.h"
#include "syntax-tree.h"
#include <stdio.h>
#include "intermediate-language.h"
/*
 * Count the number of nodes of the passed in type.
 * treeTraversal(fn_body, count, testNode)
 *
 */


static char *nodeTypeName[] = {"Error",     "Intcon",     "Charcon",
                               "Stringcon", "Var",        "ArraySubscript",
                               "Plus",      "UnaryMinus", "BinaryMinus",
                               "Mult",      "Div",        "Equals",
                               "Neq",       "Leq",        "Lt",
                               "Geq",       "Gt",         "LogicalAnd",
                               "LogicalOr", "LogicalNot", "FunCall",
                               "Assg",      "Return",     "For",
                               "While",     "If",         "STnodeList"};
                               
void treeTraversal(tnode *fn_body, int *count, int testNodeType);

// Homework 0
void countNodeTypes(symtabnode *fn_name, tnode *fn_body);




#endif // HOMEWORK_0_H
