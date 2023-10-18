#include <stdio.h>

int main()
{
    int rank;
    printf("choose menu : ");
    scanf("%d",&rank);
    if (rank > 5)
    {
        printf("invalid choices");
    }

    switch (rank)
    {
        case 1:
        printf("You choose Americano");
        break;

        case 2:
        printf("You choose Capuccino");
        break;

        case 3:
        printf("You choose Latte");
        break;

        case 4:
        printf("You choose water");
        break;

        case 5:
        printf("You choose milk");
        break;
    }
}