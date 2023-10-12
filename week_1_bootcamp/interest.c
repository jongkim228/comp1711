#include <stdio.h>

int main()
{
    int p;
    float r;
    int y;
    float i;

    printf("insert principal : ");
    scanf("%d",&p);

    printf("insert rate : ");
    scanf("%f",&r);
    
    printf("insert year : ");
    scanf("%d",&y);
    i=p*r*y;


    printf("%f", i);
    return 0;

}