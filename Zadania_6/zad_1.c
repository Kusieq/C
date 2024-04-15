#include <stdio.h>

union Dane {
    int calkowita;
    float zmiennoprzecinkowa;
    char znak;
};

int main() {
    union Dane unia;

    unia.calkowita = 10;
    printf("Wartosc calkowita: %d\n", unia.calkowita);

    unia.zmiennoprzecinkowa = 2.50;
    printf("Wartosc zmiennoprzecinkowa: %.2f\n", unia.zmiennoprzecinkowa);

    unia.znak = 'a';
    printf("Znak: %c\n", unia.znak);

    return 0;
}