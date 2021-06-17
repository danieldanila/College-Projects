/*
2.	Să se scrie programul care listează, într-un fişier text, produsele cu cea mai mare valoare pe an. 
(exemplu de consultare cu selecție)
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
    FILE *fisierText;
    Produs produs;

    char numeFisierBinar[20];
    printf("Introduceti numele fisierului binar (.dat): ");
    gets(numeFisierBinar);

    fisierBinar = fopen(numeFisierBinar, "rb");

    if (!fisierBinar)
    {
        printf("Fisierul nu a putut fi deschis.");
    }
    else
    {
        char numeFisierText[20];
        printf("Introduceti numele fisierului text (.txt): ");
        gets(numeFisierText);

        fisierText = fopen(numeFisierText, "w");

        float valoareMaximaProduse = 0;
        float valoareProdus;
        int codProdus = 0;

        fprintf(fisierText, "Produsele cu valoarea maxima %d sunt: ", valoareMaximaProduse);
        fread(&produs, sizeof(Produs), 1, fisierBinar);

        while (!feof(fisierBinar))
        {
            if (produs.exista)
            {
                valoareProdus = 0;
                for (int i = 0; i < 12; i++)
                {
                    valoareProdus += produs.pret * produs.cantitate[i];
                }

                if (valoareProdus > valoareMaximaProduse)
                {
                    fclose(fisierText);
                    fisierText = fopen(numeFisierText, "w");

                    valoareMaximaProduse = valoareProdus;
                    fprintf(fisierText, "Produsele cu valoarea maxima %0.2f sunt", valoareMaximaProduse);
                }
                if (valoareProdus == valoareMaximaProduse)
                {
                    fprintf(fisierText, "\nProdusul %s cu codul %d", produs.denumire, codProdus);
                }
            }
            codProdus++;
            fread(&produs, sizeof(Produs), 1, fisierBinar);
        }
        fclose(fisierText);
        fclose(fisierBinar);
    }
    return 0;
}