#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnt = 0;
struct symtab
{
    char label[20];
    int addr;
} sy[50];
void insert();
int search(char *);
void display();
void modify();
int main()
{
    int ch, val;
    char lab[20];
    do
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Search");
        printf("\n4. Modify");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the label: ");
                scanf("%s", lab);
                val = search(lab);
                if(val == 1)
                    printf("Label is found\n");
                else
                    printf("Label is not found\n");
                break;
            case 4:
                modify();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    } while(ch != 5);
    return 0;
}
void insert()
{
    int val;
    char lab[20];
    printf("Enter the label: ");
    scanf("%s", lab);
    val = search(lab);
    if(val == 1)
    {
        printf("Duplicate Symbol\n");
    }
    else
    {
        strcpy(sy[cnt].label, lab);
        printf("Enter the address: ");
        scanf("%d", &sy[cnt].addr);
        cnt++;
    }
}
int search(char *s)
{
    int i;
    for(i = 0; i < cnt; i++)
    {
        if(strcmp(sy[i].label, s) == 0)
            return 1;
    }
    return 0;
}
void modify()
{
    int val, ad, i;
    char lab[20];
    printf("Enter the label: ");
    scanf("%s", lab);
    val = search(lab);
    if(val == 0)
    {
        printf("No such symbol\n");
    }
    else
    {
        printf("Label is found\n");
        printf("Enter the new address: ");
        scanf("%d", &ad);
        for(i = 0; i < cnt; i++)
        {
            if(strcmp(sy[i].label, lab) == 0)
            {
                sy[i].addr = ad;
            }
        }
        printf("Address Modified Successfully\n");
    }
}
void display()
{
    int i;
    printf("\nLabel\tAddress\n");
    for(i = 0; i < cnt; i++)
    {
        printf("%s\t%d\n", sy[i].label, sy[i].addr);
    }
}