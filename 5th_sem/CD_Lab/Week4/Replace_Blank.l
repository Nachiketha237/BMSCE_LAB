%{
#include <stdio.h>
%}

%%
[ \t]+ { putchar(' '); }  /* Replace whitespace sequences with a single blank */
\n    { putchar('\n'); }   /* Preserve newline characters */
.     { putchar(yytext[0]); }  /* Copy other characters as is */
%%

int main() {
    FILE *inputFile, *outputFile;

    inputFile = fopen("input.txt", "r");
    if (!inputFile) {
        perror("Error opening input.txt");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        perror("Error opening output.txt");
        fclose(inputFile);
        return 1;
    }

    yyin = inputFile;
    yyout = outputFile;

    yylex();

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
int yywrap() {
    return 1;
}
