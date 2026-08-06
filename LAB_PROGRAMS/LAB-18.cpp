#include <stdio.h>
int main()
{
    int n, i;
    char lhs, op1, opr, op2;
    printf("Enter the number of intermediate codes: ");
    scanf("%d", &n);
    printf("\nGenerated Assembly Code:\n");
    for(i = 0; i < n; i++)
    {
        printf("\nEnter the 3-address code %d (Example: a=b+c): ", i + 1);
        scanf(" %c=%c%c%c", &lhs, &op1, &opr, &op2);
        printf("MOV %c, R%d\n", op1, i);
        switch(opr)
        {
            case '+':
                printf("ADD %c, R%d\n", op2, i);
                break;
            case '-':
                printf("SUB %c, R%d\n", op2, i);
                break;
            case '*':
                printf("MUL %c, R%d\n", op2, i);
                break;
            case '/':
                printf("DIV %c, R%d\n", op2, i);
                break;
            default:
                printf("Invalid operator\n");
        }
        printf("MOV R%d, %c\n", i, lhs);
    }
    return 0;
}