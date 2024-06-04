%{
#include <stdio.h>
%}

%s A B C DEAD

%%

<INITIAL>a { BEGIN(A); }
<INITIAL>b { BEGIN(C); }
<INITIAL>[^ab\n] { BEGIN(DEAD); printf("invalid string and now IN DEAD STATE\n"); }
<INITIAL>\n { BEGIN(INITIAL); printf("ACCEPTED\n"); }

<A>a { BEGIN(INITIAL); }
<A>b { BEGIN(B); }
<A>[^ab] { BEGIN(DEAD); printf("invalid string and now IN DEAD STATE\n"); }

<B>a { BEGIN(C); }
<B>b { BEGIN(A); }
<B>[^ab] { BEGIN(DEAD); printf("invalid string and now IN DEAD STATE\n"); }

<C>a { BEGIN(B); }
<C>b { BEGIN(INITIAL); }
<C>[^ab] { BEGIN(DEAD); printf("invalid string and now IN DEAD STATE\n"); }

<DEAD>a { BEGIN(DEAD); }
<DEAD>b { BEGIN(DEAD); }
<DEAD>[^ab] { BEGIN(DEAD); printf("invalid string and now IN DEAD STATE\n"); }

%%

int main() {
    printf("Enter string: ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
