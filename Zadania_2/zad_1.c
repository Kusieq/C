#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5;
    int *xp = &x;
    *xp = 3;
    printf("Zmienna x: %d\nWskaznik: %d", x, *xp);
}
