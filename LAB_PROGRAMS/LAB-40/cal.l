%{
#include <stdio.h>
#include <stdlib.h>

float op1, op2, ans;
char oper;

void eval();
%}

DIGIT [0-9]
NUM {DIGIT}+(\.{DIGIT}+)?
OP [+-/*]

%%

{NUM} {
    if (op1 == 0)
        op1 = atof(yytext);
    else
        op2 = atof(yytext);

    if (op2 != 0)
        eval();
}

{OP} {
    oper = yytext[0];
}

[ \t]+ ;

\n {
    op1 = 0;
    op2 = 0;
}

%%

int main()
{
    printf("Enter mathematical expression:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

void eval()
{
    switch(oper)
    {
        case '+':
            ans = op1 + op2;
            break;

        case '-':
            ans = op1 - op2;
            break;

        case '*':
            ans = op1 * op2;
            break;

        case '/':
            if(op2 == 0)
            {
                printf("Cannot divide by zero\n");
                return;
            }
            ans = op1 / op2;
            break;

        default:
            printf("Invalid operator\n");
            return;
    }

    printf("The answer is = %f\n", ans);
}