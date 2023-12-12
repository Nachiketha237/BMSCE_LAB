%{
    #include<stdio.h>
%}


%%
[+|-]?[0-9]*[.][0-9]* { printf("%s is a floating point\n",yytext); }
.* { printf("%s is not a floating point\n",yytext); }


%%
int yywrap(){}

int main(){
    printf("Enter the input: ");
    yylex();
    return 0;
}
