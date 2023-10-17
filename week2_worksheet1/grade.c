#include <stdio.h>

int grade;

int main(){

    printf("insert grade : ");
    scanf("%d",&grade);

    if (grade < 50)
    {
        printf("failed");

    }
    else if (50 < grade && grade < 70)
    {
        printf("passed");
    }
    else if (70<grade)
        printf("distinction");
    

}