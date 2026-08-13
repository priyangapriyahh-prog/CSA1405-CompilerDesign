%{
int tags = 0;
%}

%%

"<"[^>]*">" {
    tags++;
    printf("%s\n", yytext);
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

    printf("\nNumber of html tags: %d\n", tags);

    fclose(yyin);
    return 0;
}