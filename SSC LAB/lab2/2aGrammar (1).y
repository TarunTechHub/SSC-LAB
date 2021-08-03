%{
#include<stdio.h>       
#include<stdlib.h>       
%}
%token TA TB
%%
S:VarA TB
;
VarA:VarA TA
|
;
%%
main()
{
 printf("Enter the string\n");
 yyparse();
 printf("Valid\n");
}
 yyerror()
{
 printf("Invalid\n");
 exit(0);
}