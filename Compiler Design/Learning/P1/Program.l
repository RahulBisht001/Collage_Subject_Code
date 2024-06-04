/*Lex Program for counting number of lines, space ,tabs*/

%{
#include<stdio.h>
int lc=0,sc=0,wc=0,cc=0;
%}

%%
[\n] {lc++; cc+=yyleng;}
[ \t] {sc++; cc+=yyleng;}
[^\t\n ]+ {wc++;cc+=yyleng;}
%%


int yywrap()
{
return 1;
}

int main(){
printf("Enter the input: ");
yylex();
printf("No. of lines : %d\n",lc);
printf("No. of words are %d \n",wc); 
printf("No. of spaces are %d \n",sc); 
printf("No. of characters are %d \n",cc); 
return 0;
}
