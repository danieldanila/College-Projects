/* 2.	Să se scrie subprogramul recursiv care determină produsul scalar dintre doi vectori.
Se va scrie și programul apelator.
*/

#include <stdio.h>

float produsScalar1(float vector1[], float vector2[], int dimensiune)
{
    float rezultatProdusScalar;

    if (dimensiune == 0)
    {
        rezultatProdusScalar = 0;
    }
    else
    {
        rezultatProdusScalar = produsScalar1(vector1, vector2, dimensiune - 1) + vector1[dimensiune - 1] * vector2[dimensiune - 1];
    }
    return rezultatProdusScalar;
}

float produsScalar2(float vector1[], float vector2[], int pozitieInitiala, int pozitieFinala)
{
    float rezultatProdusScalar;

    if (pozitieInitiala == pozitieFinala)
    {
        rezultatProdusScalar = vector1[pozitieInitiala] * vector2[pozitieInitiala];
    }
    else
    {
        rezultatProdusScalar = produsScalar2(vector1, vector2, pozitieInitiala, (pozitieFinala + pozitieInitiala) / 2) + produsScalar2(vector1, vector2, (pozitieInitiala + pozitieFinala) / 2 + 1, pozitieFinala);
    }
    return rezultatProdusScalar;
}

int main()
{
    int dimensiune;
    float vector1[100];
    float vector2[100];
    float rezultatProdusScalar;

    printf("Introduceti dimensiunea vectorilor: ");
    scanf("%d", &dimensiune);

    for (int pozitieVector = 0; pozitieVector < dimensiune; pozitieVector++)
    {
        printf("vector1[%d]: ", pozitieVector);
        scanf("%f", &vector1[pozitieVector]);

        printf("vector2[%d]: ", pozitieVector);
        scanf("%f", &vector2[pozitieVector]);
    }

    printf("Produs scalar folosind metoda 1: %5.2f\n", produsScalar1(vector1, vector2, dimensiune));
    printf("Produs scalar folosind metoda 2: %5.2f\n", produsScalar2(vector1, vector2, 0, dimensiune - 1));
    return 0;
}