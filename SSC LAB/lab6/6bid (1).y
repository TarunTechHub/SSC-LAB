%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int id=0, key=0, op=0;
extern FILE *yyin;
extern int yylex();
extern int yyparse();
%}
%name parse
%token ID KW OP
%start S
%%
S: ID S { id++; }
| KW S { key++; }
| OP S {op++;}
| 
;
%%

int main() 
{
yyin = fopen("input.c", "r");
do
{
yyparse();
}while(!feof(yyin));
printf("Keywords = %d\nIdentifiers = %d\noperators = %d\n", key,id, op);

}

yyerror() {
printf("EEK, parse error! Message: ");
exit(0);
}

