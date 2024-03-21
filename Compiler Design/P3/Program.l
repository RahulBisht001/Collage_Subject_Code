%{
#include<stdio.h>
%}

%%
^[-+]?[0-9]* {printf("\nINTEGER\n");}
^[-+]?[0-9]*[.][0-9]+$ {printf("\nFLOAT\n");}
.* printf("Other");
%%

int yywrap()
{
return 1;
}

int main()
{
yylex();
printf("Enter the Number : ");
return 0;
}