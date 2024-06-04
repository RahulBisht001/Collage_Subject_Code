%{
#include <stdio.h>
%}
%%
"<"[^>]*">" { fprintf(yyout, "%s\n", yytext); } // Match and print HTML tags
. {}
%%
int yywrap()
{
return 1;
}
int main() {
yyin = fopen("index.html","r");
yyout = fopen("output.txt","w");
yylex();
return 0;
}




========================

%{
#include<stdio.h>
%}

%%
\<\![^>]*\> ;
\<[^>^!]*\> fprintf(yyout,"%s\n",yytext);
.|\n;
%%

int yywrap()
{
return 1;
}

int main()
{
yyin=fopen("input.html","r");
yyout=fopen("out.txt","w");
yylex();
return 0;
}