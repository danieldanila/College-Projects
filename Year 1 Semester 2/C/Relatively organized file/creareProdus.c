/*
* 1.	Să se scrie programul care creează un fişier organizat relativ cu date despre produsele unei societăţi
comerciale. Datele care se reţin despre produse sunt: denumirea, pret, cantitate (maxim 12). 
Cheia relativă a fişierului este codul produsului. 
Datele se preiau de la tastatură, sfârşitul introducerii fiind marcat standard. 
(exemplu de creare). 
Să se modifice programul pentru a realiza și operația de adăugare.
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
    FILE *fiserBinar;
    Produs produs;

    char numeFisierBinar[20];
    printf("Introduceti numele fisierului binar (.dat): ");
    gets(numeFisierBinar);

    fiserBinar = fopen(numeFisierBinar, "wb+");

    if (!fiserBinar)
    {
        printf("Fisierul a putut fi deschis!");
    }
    else
    {
        int codProdus;
        printf("Introduceti codul produsului: ");
        scanf("%d", &codProdus);

        while (!feof(stdin))
        {
            int numarArticole = numar_articole(fiserBinar, sizeof(Produs));

            if (codProdus >= numarArticole)
            {
                produs.exista = 0;
                fseek(fiserBinar, 0, SEEK_END);

                for (int i = numarArticole; i <= codProdus; i++)
                {
                    fwrite(&produs, sizeof(Produs), 1, fiserBinar);
                }
            }

            fseek(fiserBinar, codProdus * sizeof(Produs), SEEK_SET);
            fread(&produs, sizeof(Produs), 1, fiserBinar);

            if (produs.exista)
            {
                printf("Exista deja un produs cu acest cod!");
            }
            else
            {
                getchar();

                printf("Denumire produs: ");
                gets(produs.denumire);

                printf("Pret produs: ");
                scanf("%f", &produs.pret);

                for (int i = 0; i < 12; i++)
                {
                    printf("Cantitatea %d: ", i + 1);
                    scanf("%d", &produs.cantitate[i]);
                }

                produs.exista = 1;
                fseek(fiserBinar, codProdus * sizeof(Produs), SEEK_SET);
                fwrite(&produs, sizeof(Produs), 1, fiserBinar);
            }
            printf("Introduceti codul produsului (CTRL + Z pentru a incetat operatia): ");
            scanf("%d", &codProdus);
        }
        fclose(fiserBinar);
    }
    return 0;
}