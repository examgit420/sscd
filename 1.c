%{
#include<stdio.h>
#include<stdlib.h>
int num = 0, op = 0, i = 0, j = 0, number[10], top = -1;
char opr[10], stack[10];
%}

%%

[0-9]+ {
    number[num++] = atoi(yytext);
}
"+" {
    opr[op++] = '+';
}
"*" {
    opr[op++] = '*';
}
"(" {
    stack[++top] = '(';
}
")" {
    if (stack[top] == '(' && top != -1) {
        top--;
    } else {
        printf("Invalid expression\n");
        exit(0);
    }
}

%%

void main() {
    printf("Enter Expression:\n");
    yylex();

    if (top == -1 && num == op + 1) {
        printf("Valid Expression:\n");
        printf("Number of identifiers = %d\n", num);
        printf("Identifiers are present:\n");
        for (i = 0; i < num; i++) {
            printf("%d\n", number[i]);
        }
        printf("Number of operators = %d\n", op);
        printf("Operators present are:\n");
        for (j = 0; j < op; j++) {
            printf("%c\n", opr[j]);
        }
    } else {
        printf("Invalid Expression\n");
    }
}
