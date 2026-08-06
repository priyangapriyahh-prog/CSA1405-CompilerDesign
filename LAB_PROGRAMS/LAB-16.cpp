#include <stdio.h>
#include <string.h>
int main()
{
    char out[20], in1[20], op1[5], in2[20], op2[5], in3[20], op3[5], in4[20];
    FILE *f1, *f2;
    f1 = fopen("sum.txt", "r");
    f2 = fopen("out.txt", "w");
    if(f1 == NULL)
    {
        printf("Error opening sum.txt");
        return 0;
    }
    fscanf(f1, "%s %s %s %s %s %s %s %s %s",
           out, op1, in1, op2, in2, op3, in3, op1, in4);
    fprintf(f2, "t1=%s+%s\n", in1, in2);
    fprintf(f2, "t2=t1+%s\n", in3);
    fprintf(f2, "t3=t2-%s\n", in4);
    fprintf(f2, "%s=t3\n", out);
    fclose(f1);
    fclose(f2);
    printf("Three Address Code Generated Successfully.\n");
    printf("Check out.txt file.\n");
    return 0;
}