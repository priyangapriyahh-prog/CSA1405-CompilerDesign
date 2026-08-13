%{
int line_no = 0;
%}

%%

^(.*)\n {
    printf("%4d\t%s", ++line_no, yytext);
}

%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");
    yylex();

    fclose(yyin);
    return 0;
}