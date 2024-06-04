%{
#include<stdio.h>
%}

%%
^[a-zA-Z_][a-zA-Z0-9_]* {printf("valid Identifier");}
^[^a-zA-Z_] { printf("invalid indentifier");}
.;
%%

int yywrap()
{
return 1;
}

int main()
{
yylex();
return 0;
}