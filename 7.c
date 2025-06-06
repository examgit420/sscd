%{
#include <stdio.h>
#include <stdlib.h>

int comment = 0;  // Counter for comments
int state = 1;    // State variable to track multi-line comments
%}

%%
// Single-line comments
"//".*\n { 
    comment++;
}

// Multi-line comment start
"/*" { 
    state = 0; 
}

// Multi-line comment end
"*/" { 
    if (state == 0) {
        comment++;
        state = 1; 
    } 
}

// Other content or new lines
.|\n { 
    if (state == 1) {
        fprintf(yyout, "%s", yytext);
    } 
}

%%

void main() {
    char inpfile[500], outfile[500];

    printf("Enter input file name: ");
    scanf("%s", inpfile);

    printf("Enter output file name: ");
    scanf("%s", outfile);

    // Open input and output files
    yyin = fopen(inpfile, "r");
    if (yyin == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    yyout = fopen(outfile, "w");
    if (yyout == NULL) {
        printf("Error: Cannot open output file.\n");
        fclose(yyin);
        exit(1);
    }

    // Process the input
    yylex();

    // Output the total number of comments removed
    printf("Total number of comment lines/blocks removed: %d\n", comment);

    // Close files
    fclose(yyin);
    fclose(yyout);
}
