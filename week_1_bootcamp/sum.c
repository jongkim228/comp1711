#include <stdio.h>

int main()
{
    int first,second,result;
    printf("first integer : ");
    scanf("%d", &first);

    printf("second integer : ");
    scanf("%d", &second);
    result = first + second;

    printf("sum : %d\n", result);
}