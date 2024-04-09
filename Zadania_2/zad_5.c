#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char imie[30];
    char nazwisko[30];
    char numer[10];  // Zwiêkszy³em rozmiar numeru, aby pomieœciæ null terminator

} Contact;

void Dodanie(Contact c[20])
{
    Contact c1;
    printf("\nPodaj imie : ");
    scanf("%s", c1.imie);
    printf("\nPodaj nazwisko : ");
    scanf("%s", c1.nazwisko);
    printf("\nPodaj numer : ");
    scanf("%s", c1.numer);

    for (int i = 0; i < 20; i++)
    {
        if (c[i].imie[0] == '\0')
        {
            c[i] = c1;
            break;
        }
    }
}

void WyszukanieNazwisko(Contact c[20])
{
    char naz[30];
    printf("\nPodaj nazwisko : ");
    scanf("%s", naz);
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(c[i].nazwisko, naz) == 0)
        {
            printf("\nDane: \nImie %s\nNazwisko %s\nNumer %s", c[i].imie, c[i].nazwisko, c[i].numer);
        }
    }
}

void UsowanieNazwisko(Contact c[20])
{
    char naz[30];
    printf("\nPodaj nazwisko : ");
    scanf("%s", naz);
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(c[i].nazwisko, naz) == 0)
        {
            memset(&c[i], 0, sizeof(Contact));
            break;  // Dodano przerwanie pêtli po usuniêciu kontaktu
        }
    }
}

void WszystkieKontakty(Contact c[20])
{
    for (int i = 0; i < 20; i++)
    {
        if (c[i].imie[0] == '\0') {
            continue;
        }
        printf("\n\nImie %s\nNazwisko %s\nNumer %s", c[i].imie, c[i].nazwisko, c[i].numer);
    }
}

int main()
{
    Contact c[20] = {0};
    Contact c1;
    strcpy(c1.imie, "Konrad");
    strcpy(c1.nazwisko, "Kus");
    strcpy(c1.numer, "123123123");
    c[0] = c1;
    int ilosc = 1;
    while (1)
    {
        printf("\n\n1. Dodaj nowy kontakt\n2. Wyszukaj kontakt po nazwisku\n3. Usuñ kontakt po nazwisku\n4. Wypisanie wszystkich kontaktów\n5. Wyjœcie\n");
        int x;
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            if (ilosc < 20)
            {
                ilosc++;
                Dodanie(c);
            }
            break;
        case 2:
            WyszukanieNazwisko(c);
            break;
        case 3:
            UsowanieNazwisko(c);
            ilosc--;
            break;
        case 4:
            WszystkieKontakty(c);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
