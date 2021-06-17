/*
5.	Să se scrie subprogramul recursiv care determină suma elementelor impare dintr-un vector. 
Se va oferi un exemplu de apel.
*/

#include <stdio.h>

int sumaElementeImpare1(int vector[], int dimensiune)
{
    int rezultat;

    if (dimensiune == 0)
    {
        rezultat = 0;
    }
    else
    {
        rezultat = sumaElementeImpare1(vector, dimensiune - 1) + (vector[dimensiune - 1] % 2 * vector[dimensiune - 1]);
    }
    return rezultat;
}

int sumaElementeImpare2(int vector[], int pozitieInitiala, int pozitieFinala)
{
    int rezultat;
    if (pozitieInitiala == pozitieFinala)
    {
        rezultat = (vector[pozitieInitiala] % 2) * vector[pozitieInitiala];
    }
    else
    {
        rezultat = sumaElementeImpare2(vector, pozitieInitiala, (pozitieInitiala + pozitieFinala) / 2) + sumaElementeImpare2(vector, (pozitieInitiala + pozitieFinala) / 2 + 1, pozitieFinala);
    }
    return rezultat;
}

int main()
{
    int dimensiune;
    int vector[100];

    printf("Numar elemente: ");
    scanf("%d", &dimensiune);

    for (int pozitieVector = 0; pozitieVector < dimensiune; pozitieVector++)
    {
        printf("vector[%d]: ", pozitieVector);
        scanf("%d", &vector[pozitieVector]);
    }
    printf("Suma elemente impare folosind metoda 1: %d\n", sumaElementeImpare1(vector, dimensiune));
    printf("Suma elemente impare folosind metoda 2: %d\n", sumaElementeImpare2(vector, 0, dimensiune - 1));
    return 0;
}