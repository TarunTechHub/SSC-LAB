%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
"#".*"<".*">" {printf("Header information \n"); }
[ \t\n] ;
+|-|*|/|=|<|> {printf("operator is %s\n",yytext);return OP;}
int|char|bool|float|void|for|do|while|if|else|return|void {printf("keyword is %s\n",yytext);return KW;}
[a-z][a-zA-Z0-9]* {printf("identifier is %s\n",yytext);return ID;}
"++"|"--" {printf("Increment/Decrement operator is %s\n",yytext);return OP;} 
[<>=][=]? {printf("Relational operator is %s\n",yytext);return OP; }
. ;
%%

