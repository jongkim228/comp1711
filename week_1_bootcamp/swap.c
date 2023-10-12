#include <stdio.h>

int main()
{
    
    int value;
    int a = 3;
    int b = 2;
    value = a;
    a = b;
    b = value;
   


    printf("a: %d\n",a);
    printf("b: %d",b);
    return 0;
}