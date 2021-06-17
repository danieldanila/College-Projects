/* Tema: Fiind dat numărul natural k>1 să se scrie programul care determină 
cel mai mic număr natural n având exact k divizori naturali proprii (diferiți de 1 și de n).
Verificările vor începe de la k+2, dacă are k divizori proprii. 
Verificările vor continua până la determinarea primului număr natural care are exact k divizori proprii, 
care va reprezenta și cel mai mic număr natural cu proprietatea cerută. */

#include <stdio.h>

void kDivizori(int k, int *numarCautat)
{
    *numarCautat = k + 2;
    int impartitor;
    int numarDivizori = 0;

    while (numarDivizori != k)
    {
        numarDivizori = 0;
        for (impartitor = 2; impartitor <= *numarCautat / 2; impartitor++)
        {
            if (*numarCautat % impartitor == 0)
            {
                numarDivizori++;
            }
        }
        if (numarDivizori != k)
        {
            (*numarCautat)++;
        }
    }
}

int main()
{
    int k;
    int numarCautat;
    printf("Introduceti numarul natural k > 1: ");
    scanf("%d", &k);

    if (k <= 1)
    {
        printf("Numarul natural k trebuie sa fie mai mare de 1.");
    }
    else
    {
        kDivizori(k, &numarCautat);
        printf("Primul numar natural care are exact %d divizori propii este %d", k, numarCautat);
    }
    return 0;
}