/*  Tema 1) Să se scrie programul care modifică o cantitate pentru produsele ale căror coduri se introduc de la tastatură. 
De la tastatură se va introduce luna (1-12) pentru care se modifica cantitatea. (exemplu de modificare cod unic) 
Să se modifice programul astfel încât să se realizeze operațiile de consultare și ștergere articol unic.
*/

#include <stdio.h>

typedef struct
{
    char denumire[20];
    float pret;
    int cantitate[12];
    char exista;
} Produs;

int numar_articole(FILE *fisierBinar, int lungime_articol)
{
    int numarArticole;
    long pozitiaCurenta;

    pozitiaCurenta = ftell(fisierBinar);

    fseek(fisierBinar, 0, SEEK_END);
    numarArticole = ftell(fisierBinar) / lungime_articol;

    fseek(fisierBinar, pozitiaCurenta, SEEK_SET);

    return numarArticole;
}

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
        FILE *fisierText;
        char numeFisierText[20];
        printf("Introduceti numele fisierului text (.txt): ");
        gets(numeFisierText);
        fisierText = fopen(numeFisierText, "w");

        int codProdus;

        printf("Introduceti codul produsului: ");
        scanf("%d", &codProdus);

        while (!feof(stdin))
        {
            int numarArticole = numar_articole(fisierBinar, sizeof(Produs));

            printf("nr articole: %d\n", numarArticole);
            if (codProdus > numarArticole)
            {
                printf("Produsul nu exista.\n");
            }
            else
            {
                fseek(fisierBinar, codProdus * sizeof(Produs), SEEK_SET);
                fread(&produs, sizeof(Produs), 1, fisierBinar);

                if (produs.exista)
                {

                    int numarLuna;
                    printf("Introduceti luna a carei cantitate doriti sa o modificati (0-11): ");
                    scanf("%d", &numarLuna);

                    if (numarLuna >= 12 || numarLuna < 0)
                    {
                        printf("Luna introdusa nu exista.\n");
                    }
                    else
                    {
                        int cantitateNouaProdus;
                        printf("Introduceti noua cantitate a produsului: ");
                        scanf("%d", &cantitateNouaProdus);

                        if (cantitateNouaProdus >= 0)
                        {
                            produs.cantitate[numarLuna] = cantitateNouaProdus;
                            produs.exista = 0;

                            fseek(fisierBinar, ftell(fisierBinar) - sizeof(Produs), SEEK_SET);
                            fwrite(&produs, sizeof(Produs), 1, fisierBinar);

                            fprintf(fisierText, "Produsul %s cu codul %d a fost modificat si sters.\n", produs.denumire, codProdus);
                        }
                        else
                        {
                            printf("Cantitatea trebuie sa fie pozitiva.\n");
                        }
                    }
                }
                else
                {
                    printf("Produsul cu codul introdus nu exista.\n");
                }
            }
            printf("Introduceti codul produsului (CTRL + Z pentru a inceta procesul): ");
            scanf("%d", &codProdus);
        }
        fclose(fisierBinar);
        fclose(fisierText);
    }
}