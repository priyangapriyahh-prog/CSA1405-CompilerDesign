%{
#include <stdio.h>
%}

%%

[0-9]+    { printf("\nValid digit\n"); }

.*        { printf("\nInvalid digit\n"); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter input: ");
    yylex();
    return 0;
}