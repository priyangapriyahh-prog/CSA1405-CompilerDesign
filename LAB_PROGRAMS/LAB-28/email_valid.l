%{
#include <stdio.h>
int flag = 0;
%}

%%

[a-z0-9.]+@[a-z0-9]+[.]com    { flag = 1; }
[a-z0-9.]+@[a-z0-9]+[.]in     { flag = 1; }
[ \t\n]+                       ;
.                              ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter email address: ");
    yylex();

    if(flag == 1)
        printf("Accepted\n");
    else
        printf("Not Accepted\n");

    return 0;
}