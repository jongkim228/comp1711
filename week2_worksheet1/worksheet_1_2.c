#include <stdio.h>

int num;

int main()
{
    printf("insert number : ");
    scanf("%d",&num);

    if (num % 4 == 0 || num % 5 == 0)
        printf("Number is divisible");

    else 
    printf("Number is not divisible");
    



}