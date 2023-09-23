/*
 * symbol-table.h
 *
 * Author: Saumya Debray
 */

#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#define Global 0
#define Local  1

#include <stdbool.h>

typedef struct stblnode {
  char *name;
  int scope; 
  bool formal;             /* true if formal, false o/2 */
  int type;                /* the type of the symbol */
  int elt_type;            /* the type of array elements */
  int num_elts;            /* no. of array elements */
  int ret_type;            /* the return type of a function */
  struct stblnode *formals;  /* the list of formals for a function */
  int fn_proto_state;      /* status of prototype definitions for a function */
  bool is_extern;          /* whether or not an ID was declared as an extern */
  struct stblnode *next;
} symtabnode;

/*********************************************************************
 *                                                                   *
 *                             Prototypes                            *
 *                                                                   *
 *********************************************************************/

/*
 * SymTabInit(sc)
 *
 * Given a scope sc, initialize the symbol table for that scope by setting
 * all the hash table buckets to NULL.
 */
void SymTabInit(int sc); // initialize the symbol table at scope sc to empty

/*
 * SymTabLookup(str, sc)
 *
 * Look up the string str in the symbol table with scope sc.  If found,
 * return a pointer to the corresponding symbol table node, otherwise
 * return NULL.
 */
symtabnode *SymTabLookup(char *str, int sc); // lookup scope sc

/*
 * SymTabLookupAll(str)
 *
 * Look up the string str in the symbol table, starting with the
 * local symbol table and then (if not found) in the global table.
 * If found in either table, return a pointer to the corresponding
 * symbol table node, otherwise return NULL.
 */
symtabnode *SymTabLookupAll(char *str); // lookup local first, then global

/*
 * SymTabInsert(str, sc)
 *
 * Add string str to the symbol table with scope sc, and return a
 * pointer to the resulting entry.  This code assumes that str does not
 * already occur in that symbol table; it gives an error message if it does.
 */
symtabnode *SymTabInsert(char *str, int sc);  // add ident to symbol table

/*
 * SymTabRecordFunInfo(isProto) -- records information in the symbol
 * table about a function.  The argument isProto indicates whether or
 * not this is a prototype.  It communicates with the YACC parser
 * through the globals fnName (the name of the function), fnRetType
 * (the return type), and lptr (a linked list of information about the
 * parameters).  It returns a pointer to the symbol table record of
 * the function.
 */
symtabnode *SymTabRecordFunInfo(bool isProto);

/*
 * CleanupFnInfo() -- clean up after processing information
 * for a function prototype/definition.
 */
void CleanupFnInfo(void);
/*
 * Defugging functions
 */
void printSTNode(symtabnode *stptr);
void DumpSymTabLocal();
void DumpSymTabGlobal();
void DumpSymTab();

/*********************************************************************
 *                                                                   *
 *          Functions: states for prototypes and definitions         *
 *                                                                   *
 *********************************************************************/

#define FN_PROTO     0  // prototype seen
#define FN_DEFINED   1  // definition seen

#endif /* _SYMBOL_TABLE_H_ */
