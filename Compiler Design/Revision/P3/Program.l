%{
#include<stdio.h>
%}

%%
^[-+]?[0-9]* {printf("\nINTEGER");}
^[-+]?[0-9]*[.][0-9]+$ {printf("\nFLOAT");}
.* {printf("\nOTHER");}
%%

int yywrap()
{
return 1;
}

int main()
{
yylex();
printf("Enter the value : ");
return 0;
}