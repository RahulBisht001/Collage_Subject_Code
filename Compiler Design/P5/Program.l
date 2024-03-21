%{
#include<stdio.h>
int chars=0,words=0,spaces=0,lines=0;
%}


%%

[\n] {words++;lines++;}
[ \t] {spaces++;words++;}
[^\n\t] {chars++;}
%%

int yywrap()
{
return 1;
}

int main()
{
extern FILE *yyin;
yyin = fopen("input.txt","r");
yylex();
printf ("No. of Words= %d\n Spaces= %d\n Characters= %d\n Lines= %d\n",words,spaces, chars,lines);
return 0;
}