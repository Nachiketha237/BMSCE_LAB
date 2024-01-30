d[0-9] 
%{
#include<stdio.h>
%}

%%

({d})*00 {
    printf("%s rule A\n", yytext);
}

({d})*222({d})* {
    printf("%s rule B \n", yytext);
}

(1(0)*(11|01)(01*01|00*10(0)*(11|1))*0)(1|10(0)*(11|01)(01*01|00*10(0)*(11|1))*10)*  {
    printf("%s rule D \n", yytext);
}

({d})*1{d}{9} {
    printf("%s rule E \n", yytext);
}

{d}{4} {
    int sum = 0, i;
    for(i = 0; i < 4; i++) {
        sum = sum + yytext[i] - 48;
    }
    if(sum == 9) {
        printf("%s rule F \n", yytext);
    } else {
        sum = 1;
        for(i = 0; i < 3; i++) {
            if(yytext[i] > yytext[i + 1]) {
                sum = 0;
                break;
            }
        }
        if(sum == 1) {
            printf("%s rule G \n", yytext);
        } else {
            printf("%s doesn't match any rule\n", yytext);
        }
    }
}

({d})* {  
    int i, c = 0;
    if(yyleng < 5) {
        printf("%s doesn't match any rule\n", yytext);
    } else {
        for(i = 0; i < 5; i++) {
            if(yytext[i] == '5') {
                c++;
            }
        }
        if(c >= 2) {
            for(; i < yyleng; i++) {
                if(yytext[i - 5] == '5') {
                    c--;
                }
                if(yytext[i] == '5') {
                    c++;
                }
                if(c < 2) {
                    printf("%s doesn't match any rule\n", yytext);
                    break;
                }
            }
            if(yyleng == i) {
                printf("%s rule C\n", yytext);
            }
        } else {  
            printf("%s doesn't match any rule\n", yytext);
        }
    }
}

. { continue; }
\n { exit(0); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text\n");
    yylex();
    return 0;
}
