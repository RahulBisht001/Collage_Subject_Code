%{
#include<stdio.h>
%}

%%

[\t" "]+ fprintf(yyout," ");
. fprintf(yyout,"%s",yytext);

%%

int yywrap()
{
return 1;
}

int main()
{
extern FILE *yyin,*yyout;
yyin = fopen("input.txt","r");
yyout = fopen("ans.txt","w");

yylex();
}