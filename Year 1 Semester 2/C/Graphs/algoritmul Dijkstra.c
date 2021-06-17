#include <stdio.h>
#include <malloc.h>

float MAX = 9999;

typedef struct
{
    float pondere;
    int varfAnterior;
} Eticheta;

void preia_graf(char *numeFisier, float ***matricePonderi, int *numarVarfuri, int *varfStart, float MAX)
{
    int i, j, m, ultimulVarf, v;
    float p;
    FILE *f = fopen(numeFisier, "rt");
    fscanf(f, "%i", numarVarfuri);
    float **matricePonderiAux = (float **)malloc(*numarVarfuri * sizeof(float *));
    for (i = 0; i < *numarVarfuri; i++)
        matricePonderiAux[i] = (float *)malloc(*numarVarfuri * sizeof(float));
    fscanf(f, "%i", &m);
    for (i = 0; i < *numarVarfuri; i++)
        for (j = 0; j < *numarVarfuri; j++)
            matricePonderiAux[i][j] = MAX;
    for (i = 0; i < m; i++)
    {
        fscanf(f, "%i", &ultimulVarf);
        fscanf(f, "%i", &v);
        fscanf(f, "%f", &p);
        matricePonderiAux[ultimulVarf - 1][v - 1] = matricePonderiAux[v - 1][ultimulVarf - 1] = p;
    }
    fscanf(f, "%i", varfStart);
    fclose(f);
    *matricePonderi = matricePonderiAux;
}

void Dijkstra(float **matricePonderi, int numarVarfuri, int varfStart, float MAX, Eticheta **rezultat)
{
    int i;
    int j;

    Eticheta *eticheta = (Eticheta *)malloc(numarVarfuri * sizeof(Eticheta));

    int *solutie = (int *)malloc(numarVarfuri * sizeof(int));

    int ultimulVarfAdaugat = varfStart;

    for (i = 0; i < numarVarfuri; i++)
    {
        eticheta[i].pondere = MAX;
        eticheta[i].varfAnterior = -1;
    }

    eticheta[varfStart - 1].pondere = 0;

    for (i = 0; i < numarVarfuri; i++)
    {
        solutie[i] = 0;
    }
    solutie[varfStart - 1] = 1;

    int pondereMinima;
    int varfMinim;

    for (i = 0; i < numarVarfuri - 1; i++)
    {
        pondereMinima = MAX;
        for (j = 1; j <= numarVarfuri; j++)
        {
            if (solutie[j - 1] == 0 && eticheta[j - 1].pondere > eticheta[ultimulVarfAdaugat - 1].pondere + matricePonderi[j - 1][ultimulVarfAdaugat - 1])
            {
                eticheta[j - 1].pondere = eticheta[ultimulVarfAdaugat - 1].pondere + matricePonderi[j - 1][ultimulVarfAdaugat - 1];
                eticheta[j - 1].varfAnterior = ultimulVarfAdaugat;
            }
            if (solutie[j - 1] == 0 && eticheta[j - 1].pondere < pondereMinima)
            {
                pondereMinima = eticheta[j - 1].pondere;
                varfMinim = j;
            }
        }
        ultimulVarfAdaugat = varfMinim;
        solutie[ultimulVarfAdaugat - 1] = 1;
    }

    *rezultat = eticheta;
    free(eticheta);
    free(solutie);
}

int main()
{
    float **matricePonderi;
    int numarVarfuri;
    int varfStart;
    Eticheta *eticheta;

    char numeFisier[20];
    printf("Numele fisierului: ");
    gets(numeFisier);

    preia_graf(numeFisier, &matricePonderi, &numarVarfuri, &varfStart, MAX);

    Dijkstra(matricePonderi, numarVarfuri, varfStart, MAX, &eticheta);

    for (int i = 1; i <= numarVarfuri; i++)
    {
        if (i != varfStart)
        {
            printf("Costul pentru cel mai ieftin drum de la %d la %d este %5.2f\n", i, varfStart, eticheta[i - 1].pondere);
            printf("Drumul de cost minim este %d, ", i);

            int ultimulVarfAdaugat = i;

            while (eticheta[ultimulVarfAdaugat - 1].varfAnterior != varfStart)
            {
                printf("%d, ", eticheta[ultimulVarfAdaugat - 1].varfAnterior);
                ultimulVarfAdaugat = eticheta[ultimulVarfAdaugat - 1].varfAnterior;
            }

            printf("%d\n", varfStart);
        }
    }

    return 0;
}