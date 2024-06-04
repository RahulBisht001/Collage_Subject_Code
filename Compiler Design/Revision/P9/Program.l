%{
#include <stdio.h>
int ca=0;
int cb=0;
%}

%s A

%%
<INITIAL>a BEGIN A ; ca++;
<INITIAL>b BEGIN A; cb++;
<INITIAL>\n if (ca%2==0 && cb%2==0) {printf("Accepted\n");}else {printf("Not
Accepted\n");ca=0,cb=0;}
<A>a BEGIN A ; ca++;
<A>b BEGIN A; cb++;
<A>\n if (ca%2==0 && cb%2==0) {printf("Accepted\n");}else {printf("Not
Accepted\n");ca=0,cb=0;}
%%

int yywrap(){
return 1;
}

int main(){
yylex();
return 1;
}