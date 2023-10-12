#include <stdio.h>

int main()
{
    int number;
    printf("insert number : ");
    scanf("%d",&number);

    if (number % 2 == 1)
        printf("odd");
    
    else
        printf("even");

return 0;
}