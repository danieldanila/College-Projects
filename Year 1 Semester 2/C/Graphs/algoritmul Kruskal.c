#include <stdio.h>

int calculareRadacina(int varf, int vectorTata[])
{
    int i = varf;
    while (vectorTata[i] >= 0)
    {
        i = vectorTata[i];
    }
    return i;
}

int Kruskal(int matricePonderi[20][3], int numarVarfuri, int numarMuchii)
{
    int vectorTata[20];
    int i;
    int j;
    int varf1;
    int varf2;
    int radacina1;
    int radacina2;
    int costSubarbore = 0;

    for (int i = 0; i < numarVarfuri; i++)
    {
        vectorTata[i] = -1;
    }

    for (i = j = 0; i < numarVarfuri - 1; j++)
    {
        varf1 = matricePonderi[j][0];
        varf2 = matricePonderi[j][1];

        radacina1 = calculareRadacina(varf1, vectorTata);
        radacina2 = calculareRadacina(varf2, vectorTata);

        if (radacina2 - radacina1) // daca > 0 -> true
        {
            if (vectorTata[radacina2] < vectorTata[radacina1])
            {
                vectorTata[radacina2] += vectorTata[radacina1];
                vectorTata[radacina1] = radacina2;
            }
            else
            {
                vectorTata[radacina1] += vectorTata[radacina2];
                vectorTata[radacina2] = radacina1;
            }

            costSubarbore += matricePonderi[j][2];
            printf("Muchia = (%d %d) | Cost: %d\n", varf1 + 1, varf2 + 1, matricePonderi[j][2]);
            printf("Cost partial: %d\n", costSubarbore);
            i++;
        }
    }
    return costSubarbore;
}

int main()
{
    int numarVarfuri;
    int numarMuchii;
    int matricePonderi[20][3];

    printf("Numar varfuri: ");
    scanf("%d", &numarVarfuri);

    printf("Numar muchii: ");
    scanf("%d", &numarMuchii);

    for (int i = 0; i < numarMuchii; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("matricePonderi[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matricePonderi[i][j]);

            if (j != 2)
            {
                matricePonderi[i][j]--;
            }
        }
    }

    int cost = Kruskal(matricePonderi, numarVarfuri, numarMuchii);

    printf("Cost total = %d", cost);

    return 0;
}