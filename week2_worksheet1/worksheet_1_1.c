#include <stdio.h>

int num;


int main(){
    printf("insert a number : ");
    scanf("%d", &num);

    if (num > 0)
    printf("number is positve");

    else if (num < 0 )
    printf("number is negative");

    else
    printf("number is zero");


}