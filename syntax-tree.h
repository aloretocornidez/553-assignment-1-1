/*
 * syntax-tree.h
 *
 * Author: Saumya Debray
 */

#ifndef _SYNTAX_TREE_H_
#define _SYNTAX_TREE_H_

#include "symbol-table.h"

// SyntaxNodeType contains the ntype of the node.
typedef enum SyntaxNodeType {
  Error,
  Intcon,
  Charcon,
  Stringcon,
  Var,
  ArraySubscript,
  Plus,
  UnaryMinus,
  BinaryMinus,
  Mult, Div,
  Equals,
  Neq,
  Leq,
  Lt,
  Geq,
  Gt,
  LogicalAnd,
  LogicalOr,
  LogicalNot,
  FunCall,
  Assg,
  Return,
  For,
  While,
  If,
  STnodeList
} SyntaxNodeType;

// symbol table reference: subscripted expr or function call
struct stref {
  symtabnode *stptr;
  struct treenode *exp;
};

// unary and binary expressions, and expression lists
struct expr {
  struct treenode *lchild, *rchild;
};

// statements
struct stmt {
  struct treenode *child0, *child1, *child2, *child3;
};

typedef struct treenode {
  enum SyntaxNodeType ntype; // the node type for a syntax tree node
  int etype; // the type of the value of a syntax tree node, once that node has
             // been evaluated.  For nodes that don't have a value, e.g.,
             // statements, this is set to t_None.
  

  // each tree node will either one of the following data points.
  // If it is an integer, then set it to the integer that it is.
  // If it is a string, then the strconst to the string.
  // If it is a variable as a leaf, then set the varabable to the strefNode.
  // If it is an expression, then set the two children.
  // If it is a statement, then you set the kind of operation it is and the three children.
  union {
    int iconst;
    char *strconst;
    struct stref strefNode; // A reference to the treenode and the symbol table node.
    struct expr exprNode; // 
    struct stmt stmtNode;
  } val;

  

  // This is a pointer to the list of instrructions that pertain to that node.
  struct instr* code;

} tnode, *tnptr;

tnode *mkConstNode(SyntaxNodeType ntype, int etype, int n);
tnode *mkStrNode(char *s);
tnode *mkSymTabRefNode(SyntaxNodeType ntype, int etype, symtabnode *stptr,
                       tnode *t0);
tnode *mkExprNode(SyntaxNodeType ntype, int etype, tnode *e1, tnode *e2);
tnode *mkSTNode(SyntaxNodeType ntype, int etype, tnode *x0, tnode *x1,
                tnode *x2, tnode *x3);
tnode *mkErrorNode(void);
tnode *mkListNode(tnode *hd, tnode *tl);
tnode *AppendReturn(tnode *t);

bool ActualsMatchFormals(symtabnode *fn, tnode *actuals);
tnode *SynTreeUnExp(SyntaxNodeType ntype, tnode *e1);
tnode *SynTreeBinExp(SyntaxNodeType ntype, tnode *e1, tnode *e2);

#define ConstVal(x) (x)->val.iconst
#define StrVal(x) (x)->val.strconst

#define SymTabPtr(x) (x)->val.strefNode.stptr
#define ExprPtr(x) (x)->val.strefNode.exp

#define LChild(x) (x)->val.exprNode.lchild
#define RChild(x) (x)->val.exprNode.rchild

#define Child0(x) (x)->val.stmtNode.child0
#define Child1(x) (x)->val.stmtNode.child1
#define Child2(x) (x)->val.stmtNode.child2
#define Child3(x) (x)->val.stmtNode.child3

#define ListNode(x) (x)->val.exprNode.lchild
#define ListNext(x) (x)->val.exprNode.rchild

#endif /* _SYNTAX_TREE_H_ */
