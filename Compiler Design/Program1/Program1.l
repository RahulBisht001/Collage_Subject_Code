%{#include<stdio.h>
int c=0;
%}

%%
"hi" {printf("Bye");}
.* {printf("Wrong");}
%%

int yywrap(){
return(1);
}
int main(){
printf("Enter input");
yylex();
return 1;
}