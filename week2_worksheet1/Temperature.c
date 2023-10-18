#include <stdio.h>

int main()
{
    int temperture;

    printf("Insert temperture : ");
    scanf("%d", &temperture);

    if (-10 < temperture && temperture < 40  )
    {
        printf("Celcius");
    }
    
    else
    {
        printf("Not Celsius");

    }

    return 0;
}