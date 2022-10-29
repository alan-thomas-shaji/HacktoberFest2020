%option noyywrap
%{
	int words=0, chars=0, lines=0;
%}

%%
[a-zA-Z]+ {words++; chars+=yyleng;}
\n {chars++; lines++;}
. chars++;
%%


int main(){
	yylex();
	printf("\n\nwords=%d \ncharacters= %d \nlines= %d \n", words, chars, lines);	
	return 0;
}
