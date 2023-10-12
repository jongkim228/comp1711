#include <stdio.h>

int main()
{
    float day;
    float light_day;
    printf("number of days: ");
    scanf("%f", &day);

    light_day = day * 299792458*60*60*24;
    printf("%fm", light_day);


}