/*
2.Să se scrie programul care afişează datele despre studenţii ale căror numere matricole se introduc de la tastatură.
Sfârşitul introducerii este marcat standard. (expl.de consultare un articol)
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
    FILE *file;
    Student student;

    char numeFisier[20];
    printf("Introduceti numele fisierului binar (.dat): ");
    // fgets(numeFisier, 20, stdin);
    gets(numeFisier);

    file = fopen(numeFisier, "rb");

    if (!file)
    {
        printf("Fisierul nu a putut fi deschis.");
    }
    else
    {
        int numarMatricolCautat;
        printf("Introduceti numarul matricol cautat: ");
        scanf("%d", &numarMatricolCautat);

        while (!feof(stdin))
        {
            fread(&student, sizeof(Student), 1, file);
            rewind(file);

            int i = 0;

            while (!feof(file) && i == 0)
            {
                if (numarMatricolCautat == student.numarMatricol)
                {
                    i = 1;

                    printf("Numarul matricol: %d Nume: %s An: %d Grupa: %d", student.numarMatricol, student.nume, student.an, student.grupa);

                    for (int i = 0; i < student.numarNote; i++)
                    {
                        printf(" Nota %d: %d", i + 1, student.note[i]);
                    }
                    printf("\n");
                }
                fread(&student, sizeof(Student), 1, file);
            }

            if (i == 0)
            {
                printf("Numarul matricol nu a fost gasit.\n");
            }

            printf("\n");

            printf("Introduceti numarul matricol cautat (CTRL + Z pentru incetarea procesului): ");
            scanf("%d", &numarMatricolCautat);
        }
    }
    fclose(file);
    return 0;
}