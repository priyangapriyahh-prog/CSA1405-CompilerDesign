#include <stdio.h>
#include <string.h>
char stack[100];
char input[100];
int top = -1;
void push(char c)
{
    stack[++top] = c;
    stack[top + 1] = '\0';
}
void reduce()
{
    int change;
    do
    {
        change = 0;
        int len = strlen(stack);
        /* i -> E */
        if(len >= 1 && stack[len-1] == 'i')
        {
            stack[len-1] = 'E';
            printf("%-20s Reduce E->i\n", stack);
            change = 1;
            continue;
        }
        /* (E) -> E */
        len = strlen(stack);
        if(len >= 3 &&
           stack[len-3] == '(' &&
           stack[len-2] == 'E' &&
           stack[len-1] == ')')
        {
            stack[len-3] = 'E';
            stack[len-2] = '\0';
            top -= 2;
            printf("%-20s Reduce E->(E)\n", stack);
            change = 1;
            continue;
        }
        /* E*E, E/E, E+E, E-E -> E */
        len = strlen(stack);
        if(len >= 3 &&
           stack[len-3] == 'E' &&
           stack[len-1] == 'E' &&
          (stack[len-2]=='+' ||
           stack[len-2]=='-' ||
           stack[len-2]=='*' ||
           stack[len-2]=='/'))
        {
            stack[len-3]='E';
            stack[len-2]='\0';
            top-=2;
            printf("%-20s Reduce E->E%cE\n",stack,stack[len-2]);
            change=1;
        }
    }while(change);
}
int main()
{
    int i;
    printf("Operator Precedence Parser\n");
    printf("Grammar:\n");
    printf("E->E+E | E-E | E*E | E/E | (E) | i\n\n");
    printf("Enter expression: ");
    scanf("%s",input);
    stack[0]='\0';
    for(i=0;i<strlen(input);i++)
    {
        push(input[i]);
        printf("%-20s Shift %c\n",stack,input[i]);
        reduce();
    }
    reduce();
    if(strcmp(stack,"E")==0)
        printf("\nString Accepted\n");
    else
        printf("\nString Not Accepted\n");
    return 0;
}