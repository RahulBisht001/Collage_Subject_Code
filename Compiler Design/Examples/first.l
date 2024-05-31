%{
#include<stdio.h>
int lines=0;
int tabs=0;
int space=0;
int others=0;
%}

%%
\n {lines++;}
\t {tabs++;}
[ ] {space++;}
. {others++;}
%%
int yywrap(){
return 1;
}
int main(){
    yylex();
    printf("%d %d %d %d", lines, tabs, space, others);
    return 1;
}