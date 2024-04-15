#include <stdio.h>

int dodawanie(int a, int b) {
    return a + b;
}

int mnozenie(int a, int b) {
    return a * b;
}

int odejmowanie(int a, int b) {
    return a - b;
}

int main() {
    int (*wskFunkcji)(int, int);

    int wybor;

    printf("1. Dodawanie\n");
    printf("2. Mnożenie\n");
    printf("3. Odejmowanie\n");
    scanf("%d", &wybor);

    switch (wybor) {
        case 1:
            wskFunkcji = dodawanie;
            break;
        case 2:
            wskFunkcji = mnozenie;
            break;
        case 3:
            wskFunkcji = odejmowanie;
            break;
        default:
            return 0;
    }


    int a, b;
    printf("Podaj liczby: ");
    scanf("%d %d", &a, &b);

    int wynik = (*wskFunkcji)(a, b);
    printf("Wynik: %d\n", wynik);

    return 0;
}