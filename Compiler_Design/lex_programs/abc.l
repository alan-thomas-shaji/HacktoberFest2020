%option noyywrap
%{
#include<string.h>
%}

%%
abc {strcpy(yytext, "ABC"); ECHO;}
. ECHO;
%%

int main(){
	yyin = fopen("abc.txt", "r");
	yyout = fopen("resul_abc.txt", "w");
	yylex();
	return 0;
}
