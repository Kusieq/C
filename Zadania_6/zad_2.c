#include <stdio.h>

int main() {

    int tab[10];
    for (int i = 0; i < 10; i++) {
        tab[i] = i;
    }

    int *wskaznik = tab;

    for (int i = 0; i < 10; i++) {
        printf("%d ", *wskaznik);
        wskaznik++;
    }

    return 0;
}
