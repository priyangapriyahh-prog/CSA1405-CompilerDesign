%{
int cons = 0;
%}

digit [0-9]

%%

{digit}+ {
    cons++;
    printf("%s is a constant\n", yytext);
}

.|\n { }

%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    FILE *f;
    char file[100];

    printf("Enter File Name : ");
    scanf("%s", file);

    f = fopen(file, "r");
    yyin = f;

    yylex();

    printf("Number of Constants : %d\n", cons);

    fclose(yyin);
    return 0;
}