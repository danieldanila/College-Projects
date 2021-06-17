/* Tema 1) Să se scrie subprogramul recursiv care determină 
un număr la o putere (xn), precum și programul apelator.
*/

#include <stdio.h>

float numarRidicatPutere1(float numar, int putere) // metoda reducerii
{
    float numarPutere;

    if (!putere)
    {
        numarPutere = 1;
    }
    else if (putere > 0)
    {
        numarPutere = numarRidicatPutere1(numar, putere - 1) * numar;
    }
    else
    {
        numarPutere = numarRidicatPutere1(numar, putere + 1) * numar;
    }

    return numarPutere;
}

float numarRidicatPutere2(float numar, int pozitieInitialaPutere, int pozitieFinalaPutere) // metoda descompunerii (divide et impera)
{
    float numarPutere;

    if (pozitieInitialaPutere == pozitieFinalaPutere)
    {
        numarPutere = 1;
    }
    else
    {
        numarPutere = numarRidicatPutere2(numar, pozitieInitialaPutere, (pozitieInitialaPutere + pozitieFinalaPutere) / 2) * numarRidicatPutere2(numar, (pozitieInitialaPutere + pozitieFinalaPutere) / 2 + 1, pozitieFinalaPutere) * numar;
    }

    return numarPutere;
}

int main()
{
    float numar;
    int putere;

    printf("Introduceti numarul: ");
    scanf("%f", &numar);

    printf("Introduceti puterea: ");
    scanf("%d", &putere);

    float numarPutere1 = numarRidicatPutere1(numar, putere);

    if (putere >= 0)
    {
        float numarPutere2 = numarRidicatPutere2(numar, 0, putere);

        printf("Numarul %.2f ridicat la puterea %d este: %.2f (metoda reducerii)\n", numar, putere, numarPutere1);
        printf("Numarul %.2f ridicat la puterea %d este: %.2f (metoda descompunerii)\n", numar, putere, numarPutere2);
    }
    else
    {
        printf("Numarul %.2f ridicat la puterea %d este: 1/%.2f (metoda reducerii)\n", numar, putere, numarPutere1);
    }

    return 0;
}