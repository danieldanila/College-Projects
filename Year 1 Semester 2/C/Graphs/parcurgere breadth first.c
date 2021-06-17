#include <stdio.h>

void adaugareCoada(int coada[], int *dimensiuneCoada, int varf)
{
    coada[*dimensiuneCoada] = varf;
    (*dimensiuneCoada)++;
}

void extragereCoada(int coada[], int *dimensiuneCoada, int *varf)
{
    *varf = coada[0];
    for (int i = 0; i < *dimensiuneCoada - 1; i++)
    {
        coada[i] = coada[i + 1];
    }
    (*dimensiuneCoada)--;
}

void parcurgere(int matrice[10][10], int dimensiuneCoada, int varf)
{
    int varfAtins[10];
    int coada[10];
    int dim = 0;
    int vrf = 0;

    for (int i = 0; i < dimensiuneCoada; i++)
    {
        varfAtins[i] = 0;
    }

    adaugareCoada(coada, &dim, varf);
    varfAtins[varf] = 1;

    while (dimensiuneCoada != 0)
    {
        extragereCoada(coada, &dim, &vrf);
        printf("Parcurs: %d", varf + 1);

        for (int i = 1; i < dimensiuneCoada; i++)
        {
            if ((varfAtins[i] == 0) && (matrice[vrf][i] == 1))
            {
                adaugareCoada(coada, &dim, i);
                varfAtins[i] = 1;
            }
        }
    }
}

int main()
{
    int dimensiuneCoada;
    int varfStart;
    int varf1;
    int varf2;
    int muchii;
    int matrice[10][10];

    printf("Introduceti numarul de varfuri: ");
    scanf("%d", &dimensiuneCoada);
    printf("Introduceti numarul de muchii: ");
    scanf("%d", &muchii);

    for (int i = 0; i < dimensiuneCoada; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            matrice[i][j] = matrice[j][i] = 0;
        }
    }

    for (int i = 0; i < muchii; i++)
    {
        printf("Introduceti varful 1: ");
        scanf("%d", &varf1);
        printf("Introduceti varful 2: ");
        scanf("%d", &varf2);
        matrice[varf1 - 1][varf2 - 1] = matrice[varf2 - 1][varf1 - 1] = 1;
    }

    printf("Introduceti varful de start: ");
    scanf("%d", &varfStart);

    parcurgere(matrice, dimensiuneCoada, varfStart - 1);

    return 0;
}