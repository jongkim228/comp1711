#include <stdio.h>

float circleArea (float radius)
{
    float area;
    area = 3.14*radius*radius;
    return area;
}




int main ()
{
    float r;
    
    printf("insert radius : ");
    scanf("%f", &r);

    printf("Area : %f",circleArea(r));
    

}