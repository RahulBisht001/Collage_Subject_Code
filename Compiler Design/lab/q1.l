%{
%}

%s A B

%%
<INITIAL>A BEGIN INITIAL;
<INITIAL>B BEGIN A;
<INITIAL>[^B|\n] BEGIN B;
<INITIAL>\n BEGIN INITIAL; printf("Accepted\n");
<A>A BEGIN A;
<A>B BEGIN INITIAL;
<A>[^B|\n] BEGIN B;
<A>\n BEGIN INITIAL; printf("Not Accepted\n");
<B>B BEGIN B;
<B>A BEGIN B;
<B>[^B|\n] BEGIN B;
<B>\n {BEGIN INITIAL; printf("INVALID\n");}
%%


int yywrap()
{
return A;
}


void main()
{
yylex();
}
