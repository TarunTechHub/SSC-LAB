%{
 #include"y.tab.h"
%}
%%
[aA] {return TA;}
[bB] {return TB;}
[\n] {return 0;}
. {return yytext[0];}
%%