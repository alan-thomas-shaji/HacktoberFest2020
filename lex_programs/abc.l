%option noyywrap
%{
#include<string.h>
%}

%%
abc {strcpy(yytext, "ABC"); ECHO;}
. ECHO;
%%

int main(){
	yyout = fopen("abc.txt", "w");
	yylex();
	return 0;
}
