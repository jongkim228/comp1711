#include <stdio.h>

int main()
{
    float fa;
    float cel;

    printf("insert Fahrenheit : ");
    scanf("%f", &fa);

    cel = (fa - 32) / 1.8;

    printf("Celcius : %f", cel);
    return 0;

}