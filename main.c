#include "global.h"
#include "symbol-table.h"
#include <stdio.h>

extern int yydebug;
extern int yyparse();

int status = 0;

int main(void) {
  SymTabInit(Global);
  SymTabInit(Local);

  printf("Hellow");

  if (yyparse() < 0) {
    printf("main: syntax error\n");
    status = 1;
  }

  return status;
}
