/*6 T1 = -B
T2 = C + D
T3 = T1 * T2
A = T3
   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char op[2], arg1[5], arg2[5], result[5];

void main() {
    FILE *fp1, *fp2;

    // Open input and output files
    fp1 = fopen("input.txt", "r");
    if (fp1 == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }
    fp2 = fopen("output.txt", "w");
    if (fp2 == NULL) {
        printf("Error: Cannot open output file.\n");
        fclose(fp1);
        exit(1);
    }

    // Process each line of the input file
    while (fscanf(fp1, "%s %s %s %s", result, arg1, op, arg2) != EOF) {
        if (strcmp(op, "+") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nADD R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        } else if (strcmp(op, "-") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nSUB R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        } else if (strcmp(op, "*") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMUL R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        } else if (strcmp(op, "/") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nDIV R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        } else if (strcmp(op, "=") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
    }

    // Close files
    fclose(fp1);
    fclose(fp2);

    printf("Assembly code has been generated in 'output.txt'.\n");
}
