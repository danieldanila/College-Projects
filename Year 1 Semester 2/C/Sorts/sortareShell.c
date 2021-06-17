#include <stdio.h>

void sortare_shell(int vector[], int dimensiune)
{
    int i, j, k;
    int aux;

    for (i = dimensiune / 2; i > 0; i /= 2)
    {
        for (j = i; j < dimensiune; j++)
        {
            for (k = j - 1; k >= 0; k -= i)
            {
                if (vector[k] > vector[k + 1])
                {
                    aux = vector[k];
                    vector[k] = vector[k + 1];
                    vector[k + 1] = aux;
                }
            }
        }
    }
}

int main()
{
    int vector[100];
    int dimensiune;

    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &dimensiune);

    for (int i = 0; i < dimensiune; i++)
    {
        printf("vector[%d]: ", i);
        scanf("%d", &vector[i]);
    }

    sortare_shell(vector, dimensiune);

    printf("Vectorul dupa sortarea shell:\n");
    for (int i = 0; i < dimensiune; i++)
    {
        printf("vector[%d]: %d\n", i, vector[i]);
    }
    return 0;
}