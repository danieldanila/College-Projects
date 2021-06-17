#include <stdio.h>
#include <malloc.h>

void citireGraf(char numeFisier[], int matriceAdiacenta[15][15], int *numarVarfuri)
{
    FILE *fisier;

    fisier = fopen(numeFisier, "r");

    if (!fisier)
    {
        printf("Eroare");
    }
    else
    {
        int numarMuchii;

        fscanf(fisier, "%d", numarVarfuri);
        fscanf(fisier, "%d", &numarMuchii);

        for (int i = 0; i < *numarVarfuri; i++)
        {
            for (int j = 0; j < *numarVarfuri; j++)
            {
                matriceAdiacenta[i][j] = 0;
            }
        }

        for (int i = 0; i < numarMuchii; i++)
        {
            int varf1;
            int varf2;
            fscanf(fisier, "%d", &varf1);
            fscanf(fisier, "%d", &varf2);

            matriceAdiacenta[varf1 - 1][varf2 - 1] = matriceAdiacenta[varf2 - 1][varf1 - 1] = 1;
        }
        fclose(fisier);
    }
}

int **RoyMarshall(int matriceAdiacenta[15][15], int numarVarfuri)
{
    int i;
    int j;
    int k;

    int **matriceDrumuri = (int **)malloc(numarVarfuri * sizeof(int *));

    for (i = 0; i < numarVarfuri; i++)
    {
        matriceDrumuri[i] = (int *)malloc(numarVarfuri * sizeof(int));
    }

    for (i = 0; i < numarVarfuri; i++)
    {
        for (j = 0; j < numarVarfuri; j++)
        {
            matriceDrumuri[i][j] = matriceAdiacenta[i][j];
        }
    }

    for (i = 0; i < numarVarfuri; i++)
    {
        for (j = 0; j < numarVarfuri; j++)
        {
            if (matriceDrumuri[i][j] == 1)
            {
                for (k = 0; k < numarVarfuri; k++)
                {
                    if (matriceDrumuri[j][k] == 1)
                    {
                        matriceDrumuri[i][k] = matriceDrumuri[k][i] = 1;
                    }
                }
            }
        }
    }

    return matriceDrumuri;
}

int main()
{
    char numeFisier[20];
    int matriceAdiacenta[15][15];
    int **matriceDrumuri;
    int numarVarfuri;

    printf("Introduceti nume fisier: ");
    gets(numeFisier);

    citireGraf(numeFisier, matriceAdiacenta, &numarVarfuri);

    printf("nr varf: %d\n", numarVarfuri);
    for (int i = 0; i < numarVarfuri; i++)
    {
        for (int j = 0; j < numarVarfuri; j++)
        {
            printf("%d ", matriceAdiacenta[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");

    matriceDrumuri = RoyMarshall(matriceAdiacenta, numarVarfuri);

    for (int i = 0; i < numarVarfuri; i++)
    {
        for (int j = 0; j < numarVarfuri; j++)
        {
            printf("%d ", matriceDrumuri[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numarVarfuri; i++)
    {
        free(matriceDrumuri[i]);
    }

    free(matriceDrumuri);

    return 0;
}