#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int Rezultat(int turaKomputera, int turaUzytkownika) // rezultat czy uzytkownik wygral lub przegral 0 - remis, -1 - przegrana, 1 - wygrana
{

    if(turaKomputera == turaUzytkownika)
    {
        return 0;
    }
    else if((turaKomputera == 3 && turaUzytkownika == 1) || (turaKomputera == 2 && turaUzytkownika == 3 )|| (turaKomputera == 1 && turaUzytkownika == 2))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void WyswietlenieWyniku(int rezultat) // wyswietlenie wyniku dla uzytkownika
{
    switch(rezultat)
    {
        case -1:
            printf("Przegrana");
            break;
        case 0:
            printf("Remis");
            break;
        case 1:
            printf("Wygrana");
            break;
    }
}

void Wyniki(int wynikiWalk[][2],int ruchy) // wyswietlanie wynikow (opcja 4 w momencie wyboru)
{
    for(int i = 0; i < ruchy; i++)
    {
        int turaKomputera = wynikiWalk[i][1];
        int turaUzytkownika = wynikiWalk[i][0];
        char wynik[20] = "";

        printf("\nRezultat: %s", wynik);
        for(int j = 0; j < 2; j ++)
        {
            if(j == 1)
            {
                printf("  Komputer wybral: ");
            }
            else
            {
                printf("  Uzytkownik wybral: ");
            }
            switch(wynikiWalk[i][j])
            {
                case 1:
                    printf("Papier ");
                    break;
                case 2:
                    printf("Kamien ");
                    break;
                case 3:
                    printf("Nozyce ");
                    break;
            }
        }
        WyswietlenieWyniku(Rezultat(turaKomputera, turaUzytkownika));
    }
}

int main()
{
    int ruchy = 0;
    while(1) // pętla do wybrania ilosci ruchow
    {
        printf("Ile ruchow chcesz wykonac?\nWynik: ");
        scanf("%d",&ruchy);
        if(ruchy > 0)
        {
            break;
        }
    }
    int wynikiWalk[ruchy][2];
    int count = 0;
    for(int i = 0; i < ruchy; i++) // petla z iloscia ruchow
    {
        int turaKomputera = 0;
        int liczba = 0;
        while(1) // petla z wyborem opcji (bledna opcja = powtarzanie wyboru)
        {
            printf("\n\nWybierz jedna z opcji:\n1. Papier\n2. Kamien\n3. Nozyce\n4. Wynik\n5. Wyjscie\nWybor: ");
            scanf("%d", &liczba);
            if(liczba >=1 && liczba <=5)
            {
                break;
            }
        }

        if(liczba == 4)
        {
            Wyniki(wynikiWalk, i);
            i = i - 1;
        }
        else if (liczba == 5)
        {
            break;
        }
        else if(liczba == 1 || liczba == 2 || liczba == 3)
        {
            turaKomputera = rand() % 3 + 1;
            wynikiWalk[i][0] = liczba;
            wynikiWalk[i][1] = turaKomputera;
            WyswietlenieWyniku(Rezultat(turaKomputera, liczba));
        }
    }
    printf("\nWyniki ostateczne: ");
    Wyniki(wynikiWalk, ruchy);

    return 0;
}
