/*
1.Să se scrie programul care creează un fişier secvenţial cu date despre studenţii unei facultăţi. 
Articolele au următoarea structură: număr matricol, nume, anul, grupa, numărul de note, notele (maxim 15). 
Datele se preiau de la tastatură, sfârşitul introducerii fiind marcat standard. (expl. de creare) 
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

    file = fopen(numeFisier, "wb");

    if (!file)
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

            fwrite(&student, sizeof(Student), 1, file);

            printf("Introduceti numarul matricol (CTRL + Z pentru a inceta procesul): ");
            scanf("%d", &student.numarMatricol);
        }
        fclose(file);
    }
    return 0;
}