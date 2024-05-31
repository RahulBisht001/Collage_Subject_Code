%{
#include<stdio.h>
int n=0;
%}

KEYWORDS "if"|"else"|"while"|"for"|"int"
IDENTIFIER [A-Za-z_][a-zA-Z0-9_]*
OPERATORS "+"|"-"|"*"|"/"|"++"|"--"|"+="|"-="
SEPARATORS ";"|","|"{"|"}"|"("|")"

%%
KEYWORDS {n++;printf("\n %s is a keyword", yytext);}
IDENTIFIER {n++;printf("\n %s is a identifier", yytext);}
OPERATORS {n++;printf("\n %s is an operator", yytext);}
SEPARATORS {n++;printf("\n %s is an separator", yytext);}
%%

int yywrap(){
return 1;
}
int main(){
yylex();
printf("%d",n);
return 0;
}