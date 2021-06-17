#include <stdio.h>

int verificare(int vectorSolutii[], int i)
{
    int rezultat = 1;
    for (int j = 0; j < i; j++)
    {
        if (vectorSolutii[j] == vectorSolutii[i])
        {
            rezultat = 0;
        }
    }
    return rezultat;
}

void permutari(int n)
{
    int vectorSolutii[10];
    int numarSolutii = 0;
    int i = 0;
    vectorSolutii[0] = 0;

    while (i >= 0)
    {
        int ok = 0;
        while (vectorSolutii[i] < n && !ok)
        {
            vectorSolutii[i]++;
            ok = verificare(vectorSolutii, i);
        }
        if (ok == 0)
        {
            i--;
        }
        else if (i == n - 1)
        {
            numarSolutii++;
            printf("Solutia numarul %d: ", numarSolutii);
            for (int j = 0; j < n; j++)
            {
                printf("%d", vectorSolutii[j]);
            }
            printf("\n");
        }
        else
        {
            vectorSolutii[++i] = 0;
        }
    }
}

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    permutari(n);
    return 0;
}