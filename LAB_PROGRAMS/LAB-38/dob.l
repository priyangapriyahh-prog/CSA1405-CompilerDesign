%{
#include <stdio.h>
%}

%%

(0[1-9]|[12][0-9]|3[01])\/(0[1-9]|1[0-2])\/(19[0-9]{2}|2[0-9]{3}) {
    printf("Valid DoB\n");
}

.* {
    printf("Invalid DoB\n");
}

%%

int main()
{
    printf("Enter Date of Birth (DD/MM/YYYY): ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}