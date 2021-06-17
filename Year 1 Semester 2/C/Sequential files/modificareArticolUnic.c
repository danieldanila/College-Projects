/*
5.Să se scrie programul pentru adăugarea notei la disciplina algoritmi și 
tehnici de programare pentru studenul al cărui număr matricol este introdus de la tastatură. 
(expl. de modificare articol unic)
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
    FILE *binaryFile;
    Student student;

    char numeFisier[20];
    printf("Introduceti numele fisierului binar (.dat): ");
    // fgets(numeFisier, 20, stdin);
    gets(numeFisier);

    binaryFile = fopen(numeFisier, "rb+");

    if (!binaryFile)
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
            rewind(binaryFile);

            fread(&student, sizeof(Student), 1, binaryFile);

            int existaNumarulMatricol = 0;

            while (!feof(binaryFile) && existaNumarulMatricol == 0)
            {
                if (numarMatricolCautat == student.numarMatricol)
                {
                    existaNumarulMatricol = 1;
                    printf("Numarul matricol: %d Nume: %s An: %d Grupa: %d", student.numarMatricol, student.nume, student.an, student.grupa);

                    for (int i = 0; i < student.numarNote; i++)
                    {
                        printf(" Nota %d: %d", i + 1, student.note[i]);
                    }
                    printf("\n");

                    fseek(binaryFile, ftell(binaryFile) - sizeof(Student), SEEK_SET);

                    printf("Introduceti nota la ATP: ");
                    scanf("%d", &student.note[0]);

                    fwrite(&student, sizeof(Student), 1, binaryFile);
                }
                fread(&student, sizeof(Student), 1, binaryFile);
            }

            if (existaNumarulMatricol == 0)
            {
                printf("Numarul matricol nu a fost gasit.");
            }

            printf("Introduceti numarul matricol cautat (CTRL + Z pentru a incheia procesul): ");
            scanf("%d", &numarMatricolCautat);
        }
        fclose(binaryFile);
    }
    return 0;
}