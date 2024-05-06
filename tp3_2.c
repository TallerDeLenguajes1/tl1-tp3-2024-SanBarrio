#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ANIO 5
#define MAX_MES 12
#define MAX_VAL 10000
#define MIN_VAL 50000

int main()
{
    srand(time(NULL));
    int maxprodu = MIN_VAL, minprodu = MAX_VAL, promedio = 0, ianio, imes;

    int produ[MAX_ANIO][MAX_MES];

    for (int i = 0; i < MAX_ANIO; i++)
    {
        for (int j = 0; j < MAX_MES; j++)
        {
            produ[i][j] = rand() % (MAX_VAL - MIN_VAL) + MIN_VAL;
            printf("%d|", produ[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------------------\n");

    for (int i = 0; i < MAX_ANIO; i++)
    {
        for (int j = 0; j < MAX_MES; j++)
        {

            promedio += produ[i][j];
        }
        printf("\n EL PROMEDIO del año %d es: %d \n", i + 1, promedio / MAX_MES);
    }
    printf("-------------------------------------------------\n");


    for (int i = 0; i < MAX_ANIO; i++)
    {
        for (int j = 0; j < MAX_MES; j++)
        {
            if (produ[i][j]<minprodu)
            {
                minprodu = produ[i][j];
                ianio = i;
                imes = j;
            }
        }
    }
    printf("\n EL VALOR MINIMO del año %d y mes %d es: %d \n", ianio + 1, imes + 1, produ[ianio][imes]);

    printf("-------------------------------------------------\n");

    for (int i = 0; i < MAX_ANIO; i++)
    {
        for (int j = 0; j < MAX_MES; j++)
        {
            if (produ[i][j] > maxprodu)
            {
                maxprodu = produ[i][j];
                ianio = i;
                imes = j;
            }
        }
    }
    printf("\n EL VALOR MAXIMO del año %d y mes %d es: %d \n", ianio + 1, imes + 1, produ[ianio][imes]);

    return 0;
}