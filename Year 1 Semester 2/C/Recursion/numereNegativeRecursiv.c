/* 1.	Să se scrie subprogramul recursiv care determină numărul de elemente negative dintr-un vector. 
Se va scrie și programul apelator.
*/

#include <stdio.h>

int numarElementeNegative(float vector[], int dimensiune) // metoda reducerii
{
    int rezultat;

    if (dimensiune == 0)
    {
        rezultat = 0;
    }
    else
    {
        rezultat = numarElementeNegative(vector, dimensiune - 1);
        if (vector[dimensiune - 1] < 0)
        {
            rezultat++;
        }
    }
    return rezultat;
}

int numarElementeNegative2(float vector[], int pozitieIniatiala, int pozitieFinala) // metoda descompunerii (divide et impera)
{
    int rezultat;
    if (pozitieIniatiala == pozitieFinala)
    {
        if (vector[pozitieIniatiala] < 0)
        {
            rezultat = 1;
        }
        else
        {
            rezultat = 0;
        }
    }
    else
    {
        rezultat = numarElementeNegative2(vector, pozitieIniatiala, (pozitieIniatiala + pozitieFinala) / 2) + numarElementeNegative2(vector, (pozitieIniatiala + pozitieFinala) / 2 + 1, pozitieFinala);
    }
    return rezultat;
}

int main()
{
    int dimensiune;
    int pozitieVector;
    int rezultat;
    float vector[100];

    printf("Numarul de elemente: ");
    scanf("%d", &dimensiune);

    for (pozitieVector = 0; pozitieVector < dimensiune; pozitieVector++)
    {
        printf("vector[%d]: ", pozitieVector);
        scanf("%f", &vector[pozitieVector]);
    }

    printf("Numarul elementelor negative folosind metoda reducerii: %d\n", numarElementeNegative(vector, dimensiune));
    printf("Numarul elementelor negative folosind metoda descompunerii: %d\n", numarElementeNegative2(vector, 0, dimensiune - 1));
    return 0;
}