// sortare rapida sau quickSort

#include <stdio.h>

int pozitie(int vector[], int punctStart, int punctFinal)
{
    int i;
    int j;
    int k;
    int oki; // flag-uri
    int okj; // flag-uri
    int aux;

    i = punctStart;
    j = punctFinal;

    oki = 0;
    okj = -1; // pasi de incrementare

    while (i < j)
    {
        if (vector[i] > vector[j])
        {
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;

            aux = oki;
            oki = -okj;
            okj = -aux;
        }
        i += oki;
        j += okj;
    }
    return i;
}

void quickSort(int vector[], int punctStart, int punctFinal)
{
    int pozitieVector;

    if (punctFinal > punctStart)
    {
        pozitieVector = pozitie(vector, punctStart, punctFinal);
        quickSort(vector, punctStart, pozitieVector - 1);
        quickSort(vector, pozitieVector + 1, punctFinal);
    }
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

    quickSort(vector, 0, dimensiune - 1);

    printf("Vectorul dupa sortarea rapida:\n");
    for (int i = 0; i < dimensiune; i++)
    {
        printf("vector[%d]: %d\n", i, vector[i]);
    }
    return 0;
}