%{
#include<stdio.h>
%}

%%
"//"[^\n]* ;
"/*"([^*]|[*]+[^/])*[*]+"/" ;
%%

int yywrap() 
{
return 1;
}

int main ()
{
extern FILE *yyin, *yyout;
yyin = fopen("in.c", "r");
yyout = fopen("out.c", "w");
yylex();

}