%{
#include<stdio.h>
#include<stdlib.h>
%}

%token NL DIGIT LETTER

%%
stmt: variable NL {printf("Valid Identifier\n"); return 0;}
variable: LETTER alphanumeric
alphanumeric: LETTER alphanumeric | DIGIT alphanumeric | LETTER | DIGIT

%%
int main()
{
    printf("Enter an Identifier\n");
    yyparse();
    return 0;
}
int yyerror()
{
  printf("Invalid Identifier!\n");
  exit(0);
}

