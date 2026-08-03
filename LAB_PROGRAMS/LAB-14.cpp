#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ip_sym[20], stack[20];
int ip_ptr = 0, st_ptr = 0, len, i;
char temp[2], temp2[2], act[20];
void check();
int main()
{
    printf("\n\t\tSHIFT REDUCE PARSER\n");
    printf("\nGrammar");
    printf("\nE -> E+E");
    printf("\nE -> E/E");
    printf("\nE -> E*E");
    printf("\nE -> a/b\n");
    printf("\nEnter the input symbol: ");
    scanf("%s", ip_sym);
    printf("\nStack Implementation Table");
    printf("\n-----------------------------------------------");
    printf("\nStack\t\tInput\t\tAction");
    printf("\n-----------------------------------------------");
    printf("\n$\t\t%s$\t\t--", ip_sym);
    strcpy(act, "Shift ");
    temp[0] = ip_sym[ip_ptr];
    temp[1] = '\0';
    strcat(act, temp);
    len = strlen(ip_sym);
    for(i = 0; i < len; i++)
    {
        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr + 1] = '\0';
        ip_sym[ip_ptr] = ' ';
        ip_ptr++;
        printf("\n$%s\t\t%s$\t\t%s", stack, ip_sym, act);
        strcpy(act, "Shift ");
        temp[0] = ip_sym[ip_ptr];
        temp[1] = '\0';
        strcat(act, temp);
        check();
        st_ptr++;
    }
    st_ptr++;
    check();
    return 0;
}
void check()
{
    temp2[0] = stack[st_ptr];
    temp2[1] = '\0';
    if(strcmp(temp2, "a") == 0 || strcmp(temp2, "b") == 0)
    {
        stack[st_ptr] = 'E';
        if(strcmp(temp2, "a") == 0)
            printf("\n$%s\t\t%s$\t\tE -> a", stack, ip_sym);
        else
            printf("\n$%s\t\t%s$\t\tE -> b", stack, ip_sym);
    }
    if(strcmp(stack, "E+E") == 0 ||
       strcmp(stack, "E*E") == 0 ||
       strcmp(stack, "E/E") == 0)
    {
        strcpy(stack, "E");
        st_ptr = 0;
        if(strcmp(stack, "E") == 0)
            printf("\n$%s\t\t%s$\t\tE -> E+E", stack, ip_sym);
    }
    if(strcmp(stack, "E") == 0 && ip_ptr == len)
    {
        printf("\n$%s\t\t%s$\t\tACCEPT", stack, ip_sym);
        exit(0);
    }
}