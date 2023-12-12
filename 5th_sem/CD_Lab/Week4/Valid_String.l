%{
#include<stdio.h>
%}

%%
[0-9]*222[0-9]* {printf("%s:String acccepted",yytext);}
[0-9]* {printf("%s:String not Accepted",yytext);}

%%


int yywrap()
{}

int main() {
    printf("Enter String : ");
    yylex();
    return 0;
}
