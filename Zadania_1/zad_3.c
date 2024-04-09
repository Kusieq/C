#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for(int x = 0; x < sizeof(array)/sizeof(array[0]); x++) // petla o dlugosci ilosci elementow
    {
        int silnia = 1;
        for(int y = array[x]; y > 0; y--)
        {
            silnia = silnia * y; // obliczanie silni
        }
        printf("\nSilnia dla %d wynosi %d",(x+1),silnia);
    }
    return 0;
}
