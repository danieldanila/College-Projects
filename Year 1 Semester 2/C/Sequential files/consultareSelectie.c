/*
3.	Să se scrie programul care listează, în fişiere text, situaţia studenţilor din grupele ale 
căror numere se introduc de la tastatură. Sfârşitul introducerii este marcat standard. 
(expl. de consultare cu selecție)
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
    FILE *textFile;
    Student student;

    char numeFisierBinar[20];
    char numeFisierText[20];

    printf("Introduceti numele fisierului binar (.dat): ");
    // fgets(numeFisierBinar, 20, stdin);
    gets(numeFisierBinar);

    printf("Introduceti numele fisierului text (.txt): ");
    // fgets(numeFisierText, 20, stdin);
    gets(numeFisierText);

    binaryFile = fopen(numeFisierBinar, "rb");
    textFile = fopen(numeFisierText, "w");

    int numarGrupaCautata;

    printf("Introduceti numarul grupei: ");
    scanf("%d", &numarGrupaCautata);

    fread(&student, sizeof(Student), 1, binaryFile);

    while (!feof(stdin))
    {
        int existaGrupa = 0;
        while (!feof(binaryFile))
        {
            if (numarGrupaCautata == student.grupa)
            {
                fprintf(textFile, "Numarul matricol: %d Nume: %s An: %d Grupa: %d", student.numarMatricol, student.nume, student.an, student.grupa);

                for (int i = 0; i < student.numarNote; i++)
                {
                    fprintf(textFile, " %d", student.note[i]);
                }
                fprintf(textFile, "\n");

                existaGrupa = 1;
            }
            fread(&student, sizeof(Student), 1, binaryFile);
        }
        if (existaGrupa == 0)
        {
            printf("Grupa nu exista.\n");
        }

        printf("Introduceti numarul grupei (CTRL + Z pentru incetarea procesului): ");
        scanf("%d", &numarGrupaCautata);
    }
    fclose(binaryFile);
    fclose(textFile);
    return 0;
}