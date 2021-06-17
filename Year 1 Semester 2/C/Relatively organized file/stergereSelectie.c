/*3.	Să se scrie programul pentru stergerea produselor care au inregistrat 
productie zero în cel puţin trei luni. (exemplu de ștergere cu selecție)
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

    fisierBinar = fopen(numeFisierBinar, "rb+");

    if (!fisierBinar)
    {
        printf("Fisierul nu a putut fi deschis.");
    }
    else
    {
        int numarProduseSterse = 0;
        int numarLuniProductieZero;
        fread(&produs, sizeof(Produs), 1, fisierBinar);

        while (!feof(fisierBinar))
        {
            if (produs.exista)
            {
                numarLuniProductieZero = 0;
                for (int i = 0; i < 12 && numarLuniProductieZero < 3; i++)
                {
                    if (produs.cantitate[i] == 0)
                    {
                        numarLuniProductieZero++;
                    }
                }

                if (numarLuniProductieZero >= 3)
                {
                    printf("Se sterge produsul %s...\n", produs.denumire);
                    fseek(fisierBinar, ftell(fisierBinar) - sizeof(Produs), SEEK_SET);

                    produs.exista = 0;
                    fwrite(&produs, sizeof(Produs), 1, fisierBinar);

                    fseek(fisierBinar, 0, SEEK_CUR);
                    numarProduseSterse++;
                }
            }
            fread(&produs, sizeof(Produs), 1, fisierBinar);
        }
        fclose(fisierBinar);
        printf("Au fost sterse %d produse.\n", numarProduseSterse);
    }
}