#include <stdio.h>
#include <malloc.h>

int MAX = 99999;

int Prim(int **matricePonderi, int numarVarfuri, int varfStart, int ***subarbore)
{
    int costTotal = 0;
    int indicatorVector[20];
    int **solutie;
    int varf1;
    int varf2;
    int i;
    int j;
    int k;
    int costMinim = MAX;

    for (int i = 0; i < numarVarfuri; i++)
    {
        indicatorVector[i] = 0;
    }

    indicatorVector[varfStart - 1] = 1;

    solutie = (int **)malloc(numarVarfuri * sizeof(int *));

    for (i = 0; i < numarVarfuri; i++)
    {
        solutie[i] = (int *)malloc(2 * sizeof(int)); // 2-ul vine de la nr de coloane
    }

    for (i = 0; i < numarVarfuri; i++)
    {
        costMinim = MAX;

        for (j = 1; j < numarVarfuri; j++)
        {
            if (indicatorVector[j - 1] == 1)
            {
                for (k = 1; k <= numarVarfuri; k++)
                {
                    if (indicatorVector[k - 1] == 0 && (matricePonderi[j - 1][k - 1] <= costMinim))
                    {
                        varf1 = j;
                        varf2 = k;
                        costMinim = matricePonderi[j - 1][k - 1];
                    }
                }
            }
        }
        costTotal += costMinim;
        solutie[i][0] = varf1;
        solutie[i][1] = varf2;
        indicatorVector[varf2 - 1] = 1;
    }

    *subarbore = solutie;
    return costTotal;
}

void main()
{
    int i, j, nv, nm, v, u, v0, **arb;
    int **w, cost, p;
    //graful este preluat de la tastatura
    //datele citite:numarul de virfuri, numarul de muchii si matricea ponderilor
    printf("Numarul de virfuri:");
    scanf("%i", &nv);
    printf("Numarul de muchii:");
    scanf("%i", &nm);

    //alocare memorie pentru matricea ponderilor
    w = (int **)malloc((nv) * sizeof(int *));
    for (i = 0; i < nv; i++)
        w[i] = (int *)malloc(nv * sizeof(int));

    printf("Matricea ponderilor\n");
    for (i = 0; i < nv; i++)
        for (j = 0; j < nv; j++)
            w[i][j] = MAX;
    for (i = 0; i < nm; i++)
    {
        printf("Muchia %i si ponderea:", i + 1);
        scanf("%i %i %d", &v, &u, &p);
        w[u - 1][v - 1] = w[v - 1][u - 1] = p;
    }
    printf("Introduceti varful de pornire:");
    scanf("%i", &v0);

    cost = Prim(w, nv, v0, &arb);
    printf("\nArborele partial de cost minim este:\n");
    for (i = 0; i < nv - 1; i++)
        printf("%i -> %i\n", arb[i][0], arb[i][1]);
    printf(" cu costul %d\n", cost);
}