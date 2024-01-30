%{
    #include<stdio.h>
    int flag=0;
%}

%%
int|for|while|float|double|do|char {  printf(" Keyword:%s\n",yytext);}
=|>=|==|<= {  printf(" Operator:%s\n",yytext);}
[0-9]* { printf(" Number:%s\n",yytext);}
[_a-zA-Z0-9|a-zA-z0-9|a-z|A-Z]* {  printf(" Identifiers:%s\n",yytext);};
;|, {  printf(" Punctuations:%s\n",yytext);}
. {}
\n  { exit(0); }
%%

int yywrap( )
{
    return 1;
}
int main()
{
    printf("Enter the sentence:\n");
    yylex();
    
    return 0;
}

