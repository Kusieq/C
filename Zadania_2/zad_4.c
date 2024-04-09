#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char imie[30];
    float ocena;
}Student;

void sortujMalejaco(Student t[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (t[j].ocena < t[j + 1].ocena) {
                // Zamiana miejscami, jeœli warunek jest spe³niony
                Student temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

int main()
{
    Student t[5] =
    {
      {"Piotr",4.5},
      {"Adam",3.0},
      {"Stanislaw",5.0},
      {"Mateusz",2.5},
      {"Szymon",4.0}
    };
    sortujMalejaco(t, 5);

    for (int i = 0; i < 5; ++i)
    {
        printf("Student %d:\n", i + 1);
        printf("Imiê: %s\n", t[i].imie);
        printf("Ocena koñcowa: %.2f\n\n", t[i].ocena);
    }
    return 0;
}
