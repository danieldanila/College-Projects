/*
Tema 3) Să se scrie programul care realizează ștergerea unor articole din fișierul secvențial 
(simulare: copierea tuturor articolelor care nu trebuie şterse în alt fişier; 
ştergerea fişierului iniţial; redenumirea celui nou)
*/

#include <stdio.h>

typedef struct
{
    int numarMatricol;
    char nume[30];
    int an;
    int grupa;
    int numarNote;
    int note[15];
} Student;

int main()
{
    FILE *fisierBinarVechi;
    FILE *fisierBinarNou;
    Student student;

    char fisierTemporar[20] = "fisierTemporar.dat";

    char numeFisier[20];
    printf("Introduceti numele fisierului binar (.dat): ");
    gets(numeFisier);

    fisierBinarVechi = fopen(numeFisier, "rb+");

    if (!fisierBinarVechi)
    {
        printf("Fisierul nu s-a putut deschide.");
    }
    else
    {
        fisierBinarNou = fopen(fisierTemporar, "wb");

        int numarMatricolCautat;
        printf("Introduceti numarul matricol al persoanei pe care doriti sa o eliminati: ");
        scanf("%d", &numarMatricolCautat);

        fread(&student, sizeof(Student), 1, fisierBinarVechi);

        while (!feof(fisierBinarVechi))
        {
            fseek(fisierBinarVechi, 0, SEEK_CUR);

            if (numarMatricolCautat != student.numarMatricol)
            {
                fwrite(&student, sizeof(Student), 1, fisierBinarNou);
            }
            fread(&student, sizeof(Student), 1, fisierBinarVechi);
        }

        fclose(fisierBinarVechi);
        fclose(fisierBinarNou);

        int stareStergere = remove(numeFisier);

        if (stareStergere == -1)
        {
            printf("A aparut o problema in stergerea fisierului.\n");
        }

        int stareRedenumire = rename(fisierTemporar, numeFisier);

        if (stareRedenumire == -1)
        {
            printf("A aparut o problema in redenumirea fisierului.\n");
        }
    }
    return 0;
}