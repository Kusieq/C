#include <stdio.h>
int factorial(int x)
{
    if(x == 0)
    {
        return 1;
    }
    return x * factorial(x-1);
}
int main() {
    int liczba;
    int wynik;
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);
    if(liczba < 0)
    {
        printf("\nPodana bledna liczbe");
        return 0;
    }
    else if(liczba == 0 )
    {
        wynik = 1;
    }
    else
    {
        wynik = factorial(liczba);
    }
    printf("\nWynik wynosi: %d",wynik);
    return 0;
}
