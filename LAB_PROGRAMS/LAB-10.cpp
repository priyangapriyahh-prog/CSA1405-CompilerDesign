#include <stdio.h>
#include <string.h>
int main()
{
    char gram[50], part1[20], part2[20];
    char modifiedGram[20], newGram[30];
    int i, j = 0, k = 0, pos = 0;
    printf("Enter Production: S->");
    scanf("%s", gram);
    /* Extract first production */
    for(i = 0; gram[i] != '|'; i++, j++)
        part1[j] = gram[i];
    part1[j] = '\0';
    /* Extract second production */
    j = ++i;
    i = 0;
    while(gram[j] != '\0')
    {
        part2[i++] = gram[j++];
    }
    part2[i] = '\0';
    /* Find common prefix */
    for(i = 0; part1[i] == part2[i] && part1[i] != '\0'; i++)
    {
        modifiedGram[k++] = part1[i];
        pos = i + 1;
    }
    modifiedGram[k++] = 'X';
    modifiedGram[k] = '\0';
    /* Create new production */
    j = 0;
    for(i = pos; part1[i] != '\0'; i++)
        newGram[j++] = part1[i];
    newGram[j++] = '|';
    for(i = pos; part2[i] != '\0'; i++)
        newGram[j++] = part2[i];
    newGram[j] = '\0';
    printf("\nS->%s", modifiedGram);
    printf("\nX->%s", newGram);
    return 0;
}