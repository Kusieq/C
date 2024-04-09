#include <stdio.h>
#include <stdlib.h>

void podwojonaWartosc(float *wskaznik){
    *wskaznik = (*wskaznik) * 2;
}

int main()
{
    float x = 3.6;
    podwojonaWartosc(&x);
    printf("Nowa wartosc zmiennej %f",x);
    return 0;
}
