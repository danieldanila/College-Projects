/*
Tema 2) Să se scrie programul care listează într-un fişier text toate produsele 
realizate de societatea comercială. (exemplu de consultare integrală)
*/

#include <stdio.h>

typedef struct
{
    char denumire[20];
    float pret;
    int cantitate[12];
    char exista;
} Produs;

int main()
{
    FILE *fisierBinar;
    Produs produs;

    char numeFisierBinar[20];
    printf("Introduceti numele fisierului binar (.dat): ");
    gets(numeFisierBinar);

    fisierBinar = fopen(numeFisierBinar, "rb");

    if (!fisierBinar)
    {
        printf("Fisierul nu a putut fi deschis");
    }
    else
    {
        FILE *fisierText;
        char numeFisierText[20];
        printf("Introduceti numele fisierului text (.txt): ");
        gets(numeFisierText);

        fisierText = fopen(numeFisierText, "w");
        fprintf(fisierText, "Denumire produs\tPret\tCantitati\t\t\n");

        fread(&produs, sizeof(Produs), 1, fisierBinar);

        while (!feof(fisierBinar))
        {
            if (produs.exista)
            {
                fprintf(fisierText, "%s\t\t\t%0.2f\t", produs.denumire, produs.pret);
                for (int i = 0; i < 12; i++)
                {
                    fprintf(fisierText, "%d ", produs.cantitate[i]);
                }
                fprintf(fisierText, "\n");
            }
            fread(&produs, sizeof(Produs), 1, fisierBinar);
        }
        fclose(fisierBinar);
        fclose(fisierText);
    }
}