/*
Tema 1) Să se scrie programul care realizează adăugarea în fișierul binar creat la problema 1
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

    fisierBinar = fopen(numeFisier, "ab");

    if (!fisierBinar)
    {
        printf("Fisierul nu a putut fi deschis.");
    }
    else
    {
        printf("Introduceti numarul matricol: ");
        scanf("%d", &student.numarMatricol);

        while (!feof(stdin))
        {
            getchar();

            printf("Introduceti numele: ");
            gets(student.nume);

            printf("Introduceti anul: ");
            scanf("%d", &student.an);

            printf("Introduceti grupa: ");
            scanf("%d", &student.grupa);

            printf("Introduceti numarul de note: ");
            scanf("%d", &student.numarNote);

            for (int i = 0; i < student.numarNote; i++)
            {
                printf("Nota %d: ", i + 1);
                scanf("%d", &student.note[i]);
            }

            fseek(fisierBinar, 0, SEEK_END);

            fwrite(&student, sizeof(Student), 1, fisierBinar);

            printf("Introduceti numarul matricol (CTRL + Z pentru a inceta procesul): ");
            scanf("%d", &student.numarMatricol);
        }
        fclose(fisierBinar);
    }
    return 0;
}