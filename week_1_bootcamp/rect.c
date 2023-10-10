#include <stdio.h>

int main()
{

    int length, height, area;
    printf("insert length ");
    scanf("%d", &length);

    printf("insert height  ");
    scanf("%d,",&height);

    area = length*height;
    printf("area : %d\n",area);
    
    return 0;
    

}