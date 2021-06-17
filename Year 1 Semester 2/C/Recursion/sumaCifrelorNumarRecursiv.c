/*
7.	Să se scrie subprogramul recursiv care determină suma cifrelor unui numar intreg.
*/

#include <stdio.h>

int sumaCifrelorNumarIntreg(int numarIntreg)
{
    int rezultat;

    if (numarIntreg == 0)
    {
        rezultat = 0;
    }
    else
    {
        rezultat = sumaCifrelorNumarIntreg(numarIntreg / 10) + numarIntreg % 10;
    }
    return rezultat;
}

int main()
{
    int numarIntreg;

    printf("Introduceti numarul intreg: ");
    scanf("%d", &numarIntreg);

    printf("Suma cifrelor numarului intreg %d este %d.\n", numarIntreg, sumaCifrelorNumarIntreg(numarIntreg));
    return 0;
}