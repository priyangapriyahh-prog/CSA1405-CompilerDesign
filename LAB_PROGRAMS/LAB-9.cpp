#include <stdio.h>
#include <string.h>
#define SIZE 20
int main()
{
    char non_terminal;
    char beta, alpha;
    int num;
    char production[10][SIZE];
    int index = 3;
    printf("Enter Number of Productions : ");
    scanf("%d", &num);
    printf("Enter the grammar as E->E-A :\n");
    for(int i = 0; i < num; i++)
    {
        scanf("%s", production[i]);
    }
    for(int i = 0; i < num; i++)
    {
        printf("\nGRAMMAR : %s", production[i]);
        non_terminal = production[i][0];
        if(non_terminal == production[i][index])
        {
            alpha = production[i][index + 1];
            printf(" is left recursive.\n");
            while(production[i][index] != '\0' &&
                  production[i][index] != '|')
            {
                index++;
            }
            if(production[i][index] != '\0')
            {
                beta = production[i][index + 1];
                printf("Grammar without Left Recursion:\n");
                printf("%c->%c%c'\n",
                       non_terminal,
                       beta,
                       non_terminal);
                printf("%c'->%c%c'|E\n",
                       non_terminal,
                       alpha,
                       non_terminal);
            }
            else
            {
                printf("Can't be reduced.\n");
            }
        }
        else
        {
            printf(" is not left recursive.\n");
        }
        index = 3;
    }
    return 0;
}