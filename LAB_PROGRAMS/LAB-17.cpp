#include <stdio.h>
int main()
{
    char str[1000];
    int words = 0, lines = 0, characters = 0;
    int i;
    printf("Enter the text (Press ~ to end):\n");
    scanf("%[^~]", str);
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' || str[i] == '\t')
        {
            words++;
        }
        else if(str[i] == '\n')
        {
            lines++;
            words++;
        }
        else
        {
            characters++;
        }
    }
    if(characters > 0)
    {
        words++;
        lines++;
    }
    printf("\nTotal number of words : %d", words);
    printf("\nTotal number of lines : %d", lines);
    printf("\nTotal number of characters : %d", characters);
    return 0;
}