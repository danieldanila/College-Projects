#include <stdio.h>

void interclasare(int vector[], int punctStart, int mijloc, int punctFinal)
{
    int i;
    int j;
    int k;
    int vectorIntermediar[100];

    i = punctStart;
    j = mijloc + 1;
    k = 0;

    while (i <= mijloc && j <= punctFinal)
    {
        if (vector[i] >= vector[j])
        {
            vectorIntermediar[k] = vector[j];
            j++;
            k++;
        }
        else
        {
            vectorIntermediar[k] = vector[i];
            i++;
            k++;
        }
    }

    while (i <= mijloc)
    {
        vectorIntermediar[k++] = vector[i++];
    }

    while (j <= punctFinal)
    {
        vectorIntermediar[k++] = vector[j++];
    }

    for (i = 0; i < k; i++)
    {
        vector[punctStart + i] = vectorIntermediar[i];
    }
}

void sortare_interclasare(int vector[100], int punctStart, int punctFinal)
{
    if (punctFinal > punctStart)
    {
        int mijloc = (punctStart + punctFinal) / 2;
        sortare_interclasare(vector, punctStart, mijloc);
        sortare_interclasare(vector, mijloc + 1, punctFinal);
        interclasare(vector, punctStart, mijloc, punctFinal);
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

    sortare_interclasare(vector, 0, dimensiune - 1);

    printf("Vectorul dupa sortarea cu interclasare:\n");
    for (int i = 0; i < dimensiune; i++)
    {
        printf("vector[%d]: %d\n", i, vector[i]);
    }
    return 0;
}