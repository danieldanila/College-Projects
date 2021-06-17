#include <stdio.h>
#include <stdlib.h>

void schimbareTermeni(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heapify(int vector[], int marimeVector, int pozitie)
{
    int maxim = pozitie;
    int stanga = 2 * pozitie + 1;
    int dreapta = 2 * pozitie + 2;

    if (stanga < marimeVector && vector[stanga] > vector[maxim])
    {
        maxim = stanga;
    }

    if (dreapta < marimeVector && vector[dreapta] > vector[maxim])
    {
        maxim = dreapta;
    }

    if (maxim != pozitie)
    {
        schimbareTermeni(&vector[pozitie], &vector[maxim]);
        heapify(vector, marimeVector, maxim);
    }
}

void sortare_Heap(int vector[], int marimeVector)
{
    for (int pozitie = marimeVector / 2 - 1; pozitie >= 0; pozitie--)
    {
        heapify(vector, marimeVector, pozitie);
    }

    for (int pozitie = marimeVector - 1; pozitie >= 0; pozitie--)
    {
        schimbareTermeni(&vector[0], &vector[pozitie]);

        heapify(vector, pozitie, 0);
    }
}

int main()
{
    int marimeVector;

    printf("Introduceti marimea vectorului: ");
    scanf("%d", &marimeVector);

    int *vector = malloc(marimeVector * sizeof(int));

    for (int i = 0; i < marimeVector; i++)
    {
        printf("vector[%d]: ", i);
        scanf("%d", &vector[i]);
    }

    sortare_Heap(vector, marimeVector);

    printf("Vectorul sortat prin metoda Heap este: \n");

    for (int i = 0; i < marimeVector; ++i)
    {
        printf("%d ", vector[i]);
    }

    free(vector);

    return 0;
}