#include <stdio.h>

void Permutacja(int tab[],int start,int end)
{
    if(start == end)
    {
        for(int i =0; i <= end; i++)
        {
            printf("%d ",tab[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i = start; i <= end; i++)
        {
            int a = tab[start];
            int b = tab[i];

            tab[start] = b;
            tab[i] = a;

            Permutacja(tab,start+1,end);

            tab[start] = a;
            tab[i] = b;
        }
    }
}

int main() {
    int tab[3] = {
            1,9,5
    };
    int dlugosc = sizeof(tab)/sizeof(tab[0]);
    Permutacja(tab,0,dlugosc-1);
    return 0;
}

