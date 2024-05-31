%{
#include<stdio.h>
%}
%%
^[a-zA-Z_][a-zA-Z0-9_]* {printf("valid identifier");}
^[^a-zA-Z_] {printf("invalid identifier");}
.;
%%
int yywrap(){
return 1;
}
int main(){
yylex();
return 0;
}