%{
#include<stdio.h>
%}

%%
[0-9]+ {printf("Integer %s", yytext);}
[0-9]+"."[0-9]+ {printf("Float %s", yytext);}
%%

int yywrap(){
return 1;
}
int main(){
yylex();
return 0;
}