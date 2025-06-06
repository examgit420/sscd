%{
#include <stdio.h>
#include "y.tab.h"
extern yylval;
%}

%%
// Ignore whitespace and tabs
[ \t] ;

// Recognize operators
[+|\-|*|/|=|<|>]  { printf("Operator is %s\n", yytext); return OP; }

// Recognize numbers
[0-9]+  { yylval = atoi(yytext); printf("Number is %d\n", yylval); return DIGIT; }

// Recognize keywords
int|char|bool|float|void|for|do|while|if|else|return|void {
    printf("Keyword is %s\n", yytext); 
    return KEY; 
}

// Recognize identifiers
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier is %s\n", yytext); return ID; }

// Ignore any other characters
. ;




//yacc

%{
#include <stdio.h>
#include <stdlib.h>

int id = 0, dig = 0, key = 0, op = 0;  // Counters for each token type
%}

%token DIGIT ID KEY OP

%%
input:
    DIGIT input { dig++; }
    | ID input { id++; }
    | KEY input { key++; }
    | OP input { op++; }
    | DIGIT { dig++; }
    | ID { id++; }
    | KEY { key++; }
    | OP { op++; }
;
%%

// Main function
#include <stdio.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;

int main() {
    FILE *myfile = fopen("sam_input.c", "r");
    if (!myfile) {
        printf("I can't open sam_input.c!\n");
        return -1;
    }
    yyin = myfile;

    do {
        yyparse();
    } while (!feof(yyin));

    printf("\nSummary:\n");
    printf("Numbers = %d\nKeywords = %d\nIdentifiers = %d\nOperators = %d\n", dig, key, id, op);
    return 0;
}

// Error handling
void yyerror() {
    printf("Error during parsing!\n");
    exit(-1);
}


