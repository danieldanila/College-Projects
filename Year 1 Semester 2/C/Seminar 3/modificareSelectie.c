/*
6.Să se scrie programul pentru adăugarea punctului din oficiu la nota la ATP pentru studenţii 
din grupa al cărei număr este introdus de la tastatură. (expl. de modificare cu selecție)
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
        int numarulGrupeiCautate;
        printf("Introduceti numarul grupei cautate: ");
        scanf("%d", &numarulGrupeiCautate);

        while (!feof(stdin))
        {
            rewind(binaryFile);
            fread(&student, sizeof(Student), 1, binaryFile);
            int existaGrupa = 0;

            while (!feof(binaryFile))
            {
                if (numarulGrupeiCautate == student.grupa)
                {
                    existaGrupa = 1;
                    if (student.note[0] < 10)
                    {
                        student.note[0] = student.note[0] + 1;
                    }
                    fseek(binaryFile, ftell(binaryFile) - sizeof(Student), SEEK_SET);
                    fwrite(&student, sizeof(Student), 1, binaryFile);
                    fseek(binaryFile, 0, SEEK_CUR); // intre scriere si citire sau invers trebuie sa existe o comanda de deplasare
                }
                fread(&student, sizeof(Student), 1, binaryFile);
            }

            if (existaGrupa == 0)
            {
                printf("Grupa nu a fost gasita.\n");
            }

            printf("Introduceti numarul grupei cautate (CTRL + Z pentru incetarea procesului): ");
            scanf("%d", &numarulGrupeiCautate);
        }
        fclose(binaryFile);
    }
    return 0;
}