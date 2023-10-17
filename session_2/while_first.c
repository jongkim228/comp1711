#include <stdio.h>

int main () {
    long int a=1;

    while(a>0){
        printf("a= %ld\n",a);
        a+=2;

    }
    printf("After exiting the loop a = %ld \n",a);
    return 0;


}