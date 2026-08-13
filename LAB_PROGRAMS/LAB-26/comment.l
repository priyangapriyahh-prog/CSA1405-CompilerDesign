%{
int com = 0;
%}

%s COMMENT

%%

"/*"                    { BEGIN COMMENT; }

<COMMENT>"*/"           { BEGIN INITIAL; com++; }

<COMMENT>\n             { com++; }

<COMMENT>.              { }

"//".*                  { com++; }

.|\n                    { fprintf(yyout, "%s", yytext); }

%%

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("usage : a.exe input.c output.c\n");
        exit(0);
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    yylex();

    printf("\nNumber of comments are = %d\n", com);

    fclose(yyin);
    fclose(yyout);

    return 0;
}

int yywrap(void)
{
    return 1;
}