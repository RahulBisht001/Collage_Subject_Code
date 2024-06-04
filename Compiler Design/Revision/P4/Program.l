%{
#include<stdio.h>
int n=0;
%}


KEYWORDS "while"|"if"|"else"|"int"|"float"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
OPERATORS "<="|"=="|"="|"++"|"-"|"*"|"+"|","
SEPARATORS "{"|"}"|";"|"("|")"

%%
{KEYWORDS} {n++; printf("keywords: %s\n",yytext);}
{IDENTIFIER} {n++; printf("Identifier: %s\n",yytext);}
{OPERATORS} {n++; printf("Operators: %s\n",yytext);}
{SEPARATORS} {n++; printf("Seperators: %s\n",yytext);}
%%

int yywrap()
{
return 1;
}

int main()
{
yylex();
printf("Total Number of tokens is : %d",n);
return 0;
}