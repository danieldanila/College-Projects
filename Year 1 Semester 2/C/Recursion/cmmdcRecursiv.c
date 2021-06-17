/* 3.	Să se scrie subprogramul recursiv care determină cmmdc dintre două numere naturale. 
Se va oferi și un exemplu de apel.

4.	Să se scrie subprogramul recursiv care determină CMMDC dintr-un sir de numere naturale. 
Se va oferi și un exemplu de apel.
*/

#include <stdio.h>

int cmmdc1(int numar1, int numar2)
{
    int rezultat;

    if (numar1 % numar2 == 0)
    {
        rezultat = numar2;
    }
    else
    {
        rezultat = cmmdc1(numar2, numar1 % numar2);
    }
    return rezultat;
}

int cmmdc2(int vector[], int dimensiune)
{
    int rezultat;
    if (dimensiune == 1)
    {
        rezultat = vector[0];
    }
    else
    {
        rezultat = cmmdc1(cmmdc2(vector, dimensiune - 1), vector[dimensiune - 1]);
    }
    return rezultat;
}

int main()
{
    int numar1;
    int numar2;

    printf("numar1: ");
    scanf("%d", &numar1);

    printf("numar2: ");
    scanf("%d", &numar2);

    printf("cmmdc este: %d\n", cmmdc1(numar1, numar2));

    int vector[100];
    int dimensiune;

    printf("dimensiune: ");
    scanf("%d", &dimensiune);

    for (int pozitieVector = 0; pozitieVector < dimensiune; pozitieVector++)
    {
        printf("vector[%d]: ", pozitieVector);
        scanf("%d", &vector[pozitieVector]);
    }
    printf("cmmdc2 este %d\n", cmmdc2(vector, dimensiune));
    return 0;
}