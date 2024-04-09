#include <stdio.h>
#include <stdlib.h>

int main()
{
    short dane[][5] =
    {
        {3,4,5,3,3},
        {2,3,2,4,5}
    }; // tworzenie tablicy dwuwymiarowej z ocenami

    for(int x = 0; x < 2; x++)
    {
        double srednia = 0;
        for(int y = 0; y < 5; y++)
        {
            srednia = srednia + dane[x][y];
        }

        if(x == 0) // srednia ocena z matematyki
        {
            printf("Srednia z matemtyki wynosi: %.2lf", srednia/5.0);
        }
        else // srednia ocena z fizyki
        {
            printf("\nSrednia z fizyki wynosi: %.2lf", srednia/5.0);
        }
    }
    return 0;
}
