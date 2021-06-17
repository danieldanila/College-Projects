/*
6.	Să se scrie subprogramul recursiv care determină produsul primelor n numere impare.
*/

#include <stdio.h>

int produsPrimeleNumereImpare(int numarElemente)
{
    int rezultat;

    if (numarElemente == 1)
    {
        rezultat = 1;
    }
    else
    {
        rezultat = produsPrimeleNumereImpare(numarElemente - 1) * (2 * numarElemente - 1);
    }
    return rezultat;
}

int main()
{
    int numarElemente;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &numarElemente);

    printf("Produsul primelor %d numere impare: %d", numarElemente, produsPrimeleNumereImpare(numarElemente));

    return 0;
}