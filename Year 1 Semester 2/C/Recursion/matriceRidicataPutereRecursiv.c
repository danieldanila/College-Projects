/* Tema 4) Să se scrie subprogramul recursiv care determină rezultatul ridicării 
unei matrice la o putere data, precum și programul apelator.
 */

#include <stdio.h>

float matriceRidicataPutere1(float matrice[100][100], int randuri, int coloane, int putere) // metoda reducerii
{
    float matricePutere[100][100];
    if (putere == 1)
    {
        for (int i = 0; i < randuri; i++)
        {
            for (int j = 0; j < coloane; j++)
            {
                matricePutere[i][j] = matrice[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < randuri; i++)
        {
            for (int j = 0; j < coloane; j++)
            {
                matricePutere[i][j] = matriceRidicataPutere1(matrice, randuri, coloane, putere - 1) * matrice[i][j];
            }
        }
    }
    return matricePutere[100][100];
}

int main()
{
    int randuri;
    int coloane;
    float matrice[100][100];

    printf("Introduceti numarul de randuri ale matricei: ");
    scanf("%d", &randuri);

    printf("Introduceti numarul de coloane ale matricei: ");
    scanf("%d", &coloane);

    for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            printf("Matrice[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrice[i][j]);
        }
    }

    int putere;

    printf("Introduceti la ce putere doriti sa ridicat matricea: ");
    scanf("%d", &putere);

    float matricePutere[100][100];

    for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            matricePutere[i][j] = 0;
        }
    }

    matricePutere[100][100] = matriceRidicataPutere1(matrice, randuri, coloane, putere);

    printf("Matricea ridicata la puterea %d este:\n");
    for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            printf("%.2f ", matricePutere[i][j]);
        }
        printf("\n");
    }
    return 0;
}