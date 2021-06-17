/*
Se dă o mulțime de elemente reale A={a_1,a_2,〖…,a〗_n,}. 
Se cere să se scrie funcția care determină o submulțime S⊆A astfel încât 
suma elementelor submulțimii S să fie cea mai mare posibilă (problema sumei maxime).
*/

#include <stdio.h>

void suma(float vector[], int dimensiune, float vectorSolutie[], int *diumensiuneVectorSolutie)
{
    *diumensiuneVectorSolutie = 0;
    for (int i = 0; i < dimensiune; i++)
    {
        if (vector[i] >= 0)
        {
            vectorSolutie[*diumensiuneVectorSolutie] = vector[i];
            (*diumensiuneVectorSolutie)++;
        }
    }
}

int main()
{
    int dimensiune;
    int dimensiuneVectorSolutie;
    float vector[100];
    float vectorSolutie[100];
    float sumaTotala = 0;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &dimensiune);

    for (int i = 0; i < dimensiune; i++)
    {
        scanf("%f", &vector[i]);
    }

    suma(vector, dimensiune, vectorSolutie, &dimensiuneVectorSolutie);

    if (dimensiuneVectorSolutie == 0)
    {
        printf("Nu exista elemente pozitive.");
    }
    else
    {
        for (int i = 0; i < dimensiuneVectorSolutie; i++)
        {
            printf("Elementul %d cu valoarea %.2f\n", i, vectorSolutie[i]);
            sumaTotala += vectorSolutie[i];
        }
    }

    printf("Suma totala: %.2f", sumaTotala);
    return 0;
}