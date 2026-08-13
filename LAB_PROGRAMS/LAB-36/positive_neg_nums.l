%{
#include <stdio.h>

int positive_no = 0;
int negative_no = 0;
%}

%%

-[0-9]+ {
    negative_no++;
    printf("negative number = %s\n", yytext);
}

[0-9]+ {
    positive_no++;
    printf("positive number = %s\n", yytext);
}

[ \t\n]+ ;

. ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter numbers:\n");
    yylex();

    printf("\nnumber of positive numbers = %d\n", positive_no);
    printf("number of negative numbers = %d\n", negative_no);

    return 0;
}