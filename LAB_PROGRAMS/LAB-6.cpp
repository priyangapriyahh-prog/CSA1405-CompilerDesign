#include <stdio.h>
#include <ctype.h>
int main()
{
    char a[20];
    int flag = 1, i = 1;
    printf("Enter an identifier: ");
    scanf("%s", a);
    if (isalpha(a[0]) || a[0] == '_')
    {
        while (a[i] != '\0')
        {
            if (!(isalnum(a[i]) || a[i] == '_'))
            {
                flag = 0;
                break;
            }
            i++;
        }
    }
    else
    {
        flag = 0;
    }
    if (flag == 1)
        printf("\nValid identifier\n");
    else
        printf("\nNot a valid identifier\n");
    return 0;
}