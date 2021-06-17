#include <stdio.h>
#include <malloc.h>

void sortare_numarare(int vector[], int dimensiune)
{
    int i;
    int j;
    int *vectorNumarare;
    int *vectorIntermediar;

    vectorNumarare = (int *)malloc(dimensiune * sizeof(int));
    vectorIntermediar = (int *)malloc(dimensiune * sizeof(int));

    for (i = 0; i < dimensiune; i++)
    {
        vectorNumarare[i] = 0;
    }

    for (i = 0; i < dimensiune - 1; i++)
    {
        for (j = i + 1; j < dimensiune; j++)
        {
            if (vector[i] > vector[j])
            {
                vectorNumarare[i]++;
            }
            else
            {
                vectorNumarare[j]++;
            }
        }
    }

    for (i = 0; i < dimensiune; i++)
    {
        vectorIntermediar[vectorNumarare[i]] = vector[i];
    }

    for (i = 0; i < dimensiune; i++)
    {
        vector[i] = vectorIntermediar[i];
    }

    free(vectorNumarare);
    free(vectorIntermediar);
}

int main()
{
    int vector[100];
    int dimensiune;

    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &dimensiune);

    for (int i = 0; i < dimensiune; i++)
    {
        printf("vector[%d]: ", i);
        scanf("%d", &vector[i]);
    }

    sortare_numarare(vector, dimensiune);

    printf("Vectorul dupa sortarea cu numarare:\n");
    for (int i = 0; i < dimensiune; i++)
    {
        printf("vector[%d]: %d\n", i, vector[i]);
    }
    return 0;
}