#include <stdio.h>
#include <string.h>
int main()
{
    char string[50];
    int i, flag = 0;
    printf("The grammar is:\n");
    printf("S -> aS\n");
    printf("S -> Sb\n");
    printf("S -> ab\n\n");
    printf("Enter the string to be checked: ");
    scanf("%s", string);
    if(string[0] != 'a')
    {
        printf("\nString not accepted");
        return 0;
    }
    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == 'b')
            flag = 1;
        if(flag == 1 && string[i] == 'a')
        {
            printf("\nThe string does not belong to the specified grammar");
            return 0;
        }
    }
    if(flag == 1)
        printf("\nString accepted");
    else
        printf("\nString not accepted");
    return 0;
}