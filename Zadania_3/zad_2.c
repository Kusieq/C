#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int rows = 0,columns = 0 ;
    while(1)
    {
        printf("Podaj liczbe wierszy: ");
        scanf("%d",&rows);
        printf("\nPodaj liczbe kolumn: ");
        scanf("%d",&columns);
        if(rows > 0 && columns > 0)
        {
            break;
        }
        else
        {
            printf("\n\nLiczba kolumn lub wierszy jest bledna! \n\n");
        }
    }

    int **matrix = (int **)malloc(rows * sizeof(int *));

    for(int i =0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }

    srand(time(NULL));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            int losowa = rand() % 101;
            matrix[i][j] = losowa;
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("%ld ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}
