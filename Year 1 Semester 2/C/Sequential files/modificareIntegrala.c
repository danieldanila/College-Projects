/*
Tema 2) Să se scrie programul care realizează o modificare integrală a articolelor din fișierul binar
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
    FILE *fisierBinar;
    Student student;

    char numeFisier[20];
    printf("Introduceti numele fisierului binar (.dat): ");
    gets(numeFisier);

    fisierBinar = fopen(numeFisier, "rb+");

    if (!fisierBinar)
    {
        printf("Fisier nu a putut fi deschis.");
    }
    else
    {
        fread(&student, sizeof(Student), 1, fisierBinar);

        while (!feof(fisierBinar))
        {
            printf("Persoana actuala asociata numarului matricol %d este %s din anul %d grupa %d si cu notele: ", student.numarMatricol, student.nume, student.an, student.grupa);
            for (int i = 0; i < student.numarNote; i++)
            {
                printf("%d ", student.note[i]);
            }
            printf("\n");

            printf("Introduceti noul nume: ");
            gets(student.nume);

            printf("Introduceti noul an: ");
            scanf("%d", &student.an);

            printf("Introduceti noua grupa: ");
            scanf("%d", &student.grupa);

            printf("Introduceti noul numar de note: ");
            scanf("%d", &student.numarNote);

            for (int i = 0; i < student.numarNote; i++)
            {
                printf("Nota %d: ", i + 1);
                scanf("%d", &student.note[i]);
            }

            fseek(fisierBinar, ftell(fisierBinar) - sizeof(Student), SEEK_SET);

            fwrite(&student, sizeof(Student), 1, fisierBinar);

            fseek(fisierBinar, 0, SEEK_CUR);

            fread(&student, sizeof(Student), 1, fisierBinar);

            if (!feof(fisierBinar))
            {
                getchar();
            }
        }
        fclose(fisierBinar);
    }
    return 0;
}