%{
#include "y.tab.h"
%}

%%
a        { return A; }
b        { return B; }
.        { return yytext[0]; }
\n       { return 0; }
%%



  %{
#include<stdio.h>
#include<stdlib.h>
%}

%token A B

%%
S:
    X B { /* Rule for S */ }
    ;

X:
    A X { /* Recursive rule for X */ }
    |
    ;   /* Empty production */
%%
void main() {
    printf("Enter the input:\n");
    yyparse();
    printf("Valid String\n");
}

int yyerror() {
    printf("Invalid String\n");
    exit(0);
}
