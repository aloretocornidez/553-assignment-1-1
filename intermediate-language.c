// File: intermediate-language.c
// Author: Alan Manuel Loreto Cornidez
// Purpose: Code definition file for intermediate code generation.
#include "intermediate-language.h"
#include "symbol-table.h"
#include "syntax-tree.h"
#include "protos.h"

/*
struct symtab_entry *newTemp(typename t)
{

    struct symtab_entry *ntmp = malloc(sizeof(t));
    // ntmp->name = ...create a new name that doesn't conflict.
    // ntmp->type = t
    // ... insert ntmp into the function's local symbol table....
    return ntmp;
}

// Global Variable to keep track of the label number.
static int label_num = 0;
struct instr *newLabel()
{
    return newInstr(LABEL, label_num++;);
}

struct instr *newInstr(operation opType, arg_1 src1, arg_2 src2, destination dest)
{
    struct instr *ninstr = malloc();
    ninstr->op = opType;
    ninstr->src1 = src1;
    ninstr->src2 = src2;
    ninstr->dest = dest;
}




codeGen_stmt(S)
{
    condeGen_expr(LHS, L_value_);
    condeGen_expr(RHS, R_value_);
    S.code = LHS.code + RHS.code + newInstr(ASSG, RHS.place, NULL, LHS.place);
}


*/

void intermediateTreeTraversal(tnode *fn_body)
{

    tnode *tntmp0;

    // Check if the node exists.
    if (fn_body == NULL)
    {
        return;
    }

    // Iterate syntax tree with proper recursive pointers.
    switch (fn_body->ntype)
    {
    case Error:
    case Intcon:
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
        for (tntmp0 = fn_body; tntmp0 != NULL; tntmp0 = stList_Rest(tntmp0))
        {
            intermediateTreeTraversal(stList_Head(tntmp0));
        }

        break;

    default:
        fprintf(stderr, "Unknown syntax tree node type %d\n", fn_body->ntype);
    }
}

// generateIntermediate Code
// This function recursively traverses the tree and creates antermediate code for each of the encountered nodes.
void generateIntermediateCode(symtabnode *fn_name, tnode *fn_body)
{
    // Recursively traverse the syntax tree
    intermediateTreeTraversal(fn_body);

    // Code for each node is a list of three-address instructions

    // Generate code for each node after processing its children

    // At each syntax tree node, create  alist of instructions that executes the computation for the syntax tree rooted at the node

    // Glue together the instructions for its children, plus code specific to that node.
}

/*
 * CleanupFnInfo() -- clean up after processing information
 * for a function prototype/definition.
 */
// void generateMipsCode()
// {

// }
