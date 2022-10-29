%option noyywrap
%{
#include "iden.tab.h"
%}

%%
[0-9] { return DIGIT;}
[_a-zA-Z] {return LETTER;}
\n  {return NL;}
.   {return yytext[0];}
%%

