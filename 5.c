/* 5 Design, develop and implement YACC/C program to demonstrate Shift Reduce Parsing
technique for the grammar rules: E ->E+T | T, T ->T*F | F, F ->(E) | id and parse the
sentence: id + id * id.
    */




#include <stdio.h>
#include <string.h>

// Global variables
int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];

// Function declaration
void check();

// Main function
void main() {
    puts("GRAMMAR is:");
    puts("E -> E+E");
    puts("E -> E*E");
    puts("E -> (E)");
    puts("E -> id");

    puts("Enter input string:");
    gets(a); // Input string
    c = strlen(a); // Length of input string

    strcpy(act, "SHIFT->"); // Action message

    puts("Stack\tInput\tAction");
    for (i = 0; j < c; i++, j++) {
        if (a[j] == 'i' && a[j + 1] == 'd') { // Check for 'id'
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, a, act);
            check();
        } else { // For symbols
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%s symbols", stk, a, act);
            check();
        }
    }
}

// Function to perform reduction
void check() {
    strcpy(ac, "REDUCE TO E");

    // Reduce id to E
    for (z = 0; z < c; z++) {
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            j++;
        }
    }

    // Reduce E+E to E
    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
    }

    // Reduce E*E to E
    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
    }

    // Reduce (E) to E
    for (z = 0; z < c; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
    }
}
