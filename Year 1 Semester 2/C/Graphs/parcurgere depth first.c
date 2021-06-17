#include <stdio.h>

void inserare(int stiva[], int *dimensiuneStiva, int varf)
{
    for (int i = *dimensiuneStiva - 1; i > 0; i--)
    {
        stiva[i + 1] = stiva[i];
    }
    stiva[0] = varf;
    (*dimensiuneStiva)++;
}

int citire(int stiva[], int dimensiuneStiva)
{
    return stiva[0];
}

void stergere(int stiva[], int *dimensiuneStiva)
{
    for (int i = 0; i < *dimensiuneStiva - 1; i++)
    {
        stiva[i] = stiva[i + 1];
    }
    (*dimensiuneStiva)--;
}

void parcurgere(int matriceAdiacenta[10][10], int dimensiune, int varfStart)
{
    int vizitat[10];
    int dimensiuneStiva = 0;
    int stiva;
    int ok;
    int valoare;

    for (int i = 0; i < dimensiune; i++)
    {
        vizitat[i] = 0;
    }
    inserare(stiva, &dimensiuneStiva, varfStart);
    vizitat[varfStart] = 1;
    printf("%d ", varfStart + 1);

    int i;
    while (dimensiuneStiva != 0)
    {
        i = 0;
        valoare = citire(stiva, dimensiuneStiva);
        ok = 0;
        while (ok == 0 && i < dimensiune)
        {
            if (matriceAdiacenta[valoare][i] == 1 && vizitat[i] == 0)
            {
                inserare(stiva, &dimensiuneStiva, i);
                vizitat[i] = 1;
                printf("%d ", i);
                ok = 1;
            }
            i++;
        }
        if (ok == 0)
        {
            stergere(stiva, &dimensiuneStiva);
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