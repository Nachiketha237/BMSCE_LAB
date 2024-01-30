%{
#include<stdio.h>
int c = 0;
%}

%%
"\/\*"[^*]*\*+([^/*][^*]*\*+)*\/ { c++; }
"//" .* { c++; }
. ECHO;
%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    printf("The number of comments is: %d\n", c);
    fclose(yyin);
    fclose(yyout);
    return 0;
}
