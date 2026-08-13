%{
#include <stdio.h>
%}

%%

(https?|ftp):\/\/[a-zA-Z0-9.-]+\.[a-zA-Z]{2,} {
    printf("\nURL Valid\n");
}

.+ {
    printf("\nURL Invalid\n");
}

%%

int main()
{
    printf("\nEnter URL : ");
    yylex();
    printf("\n");
    return 0;
}

int yywrap()
{
    return 1;
}