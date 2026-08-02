#include <stdio.h>
#include <string.h>
int main()
{
    char com[100];
    int len;
    printf("Enter comment: ");
    gets(com);
    len = strlen(com);
    if (com[0] == '/' && com[1] == '/')
    {
        printf("It is a comment");
    }
    else if (com[0] == '/' && com[1] == '*' &&
             com[len - 2] == '*' && com[len - 1] == '/')
    {
        printf("It is a comment");
    }
    else
    {
        printf("It is not a comment");
    }
    return 0;
}