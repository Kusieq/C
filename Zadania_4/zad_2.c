#include <stdio.h>

int Sort(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int WyszukiwanieBinarne(int tab[], int left, int right, int liczba)
{
    if(left <= right)
    {
        int srodek = left + (right - left)/2;
        if(tab[srodek]==liczba)
        {
            return srodek;
        }
        else if(tab[srodek] < liczba)
        {
            return WyszukiwanieBinarne(tab,srodek+1,right, liczba);
        }
        else
        {
            return WyszukiwanieBinarne(tab,left,srodek - 1,liczba);
        }
    }
    else
    {
        return -1;
    }
}
int main() {
    int tab[20] = {
            3,5,2,1,7,10,2,90,50,60,4,12,-1,-4,0,-20,8,-7,-64,43
    };

    int liczba;
    int size = sizeof(tab)/sizeof(tab[0]);

    qsort(tab,size,sizeof(int),Sort);

    for(int i = 0; i < size; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\nPodaj element do wyszukania: ");
    scanf("%d",&liczba);
    int resultat = WyszukiwanieBinarne(tab,0,size-1,liczba);

    if(resultat != -1)
    {
        printf("\nElement jest na indeksie: %d",resultat);
    }
    else
    {
        printf("\nBrak elementu w tablicy");
    }
    return 0;
}
