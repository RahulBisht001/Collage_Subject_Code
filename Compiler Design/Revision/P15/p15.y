%{
#include <stdio.h>
#include <stdlib.h>
// Function declarations
void yyerror(const char *);
int yylex(void);
int sym[26]; // Array to store variable values
%}
%token id digit
%left '+' '-'
%left '*' '/'
%%
P: P S '\n' { /* Handle multiple statements */ }
| { /* Empty production */ }
;
S: E { printf("Output: %d\n", $1); }
| id '=' E { sym[$1] = $3; }
;
E: digit { $$ = $1; }
| id { $$ = sym[$1]; }
| E '+' E { $$ = $1 + $3; }
| E '-' E { $$ = $1 - $3; }
| E '*' E { $$ = $1 * $3; }
| E '/' E { $$ = $1 / $3; }
| '(' E ')' { $$ = $2; }
;
%%
void yyerror(const char *s) {
fprintf(stderr, "Error: %s\n", s);
}
int main(void) {
printf("Enter expression to evaluate:\n");
yyparse();
return 0;
}