/*
4.Să se scrie programul care listează, într-un fişier text, sub formă de tabel, 
conţinutul fişierului creat la problema 1. (expl. de consultare integrală)
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

    if (!numeFisierBinar)
    {
        printf("Fisierul nu a putut fi deschis.");
    }
    else
    {
        printf("Introduceti numele fisierului text (.txt): ");
        // fgets(numeFisierText, 20, stdin);
        gets(numeFisierText);

        binaryFile = fopen(numeFisierBinar, "rb");
        textFile = fopen(numeFisierText, "w");

        fprintf(textFile, "Numar matricol\tNume\t\tAn\tGrupa\tNote\n");

        fread(&student, sizeof(Student), 1, binaryFile);

        while (!feof(binaryFile))
        {
            fprintf(textFile, "%d\t\t\t%s\t\t%d\t%d\t", student.numarMatricol, student.nume, student.an, student.grupa);

            for (int i = 0; i < student.numarNote; i++)
            {
                fprintf(textFile, "%d ", student.note[i]);
            }

            fprintf(textFile, "\n");

            fread(&student, sizeof(Student), 1, binaryFile);
        }
        fclose(binaryFile);
        fclose(textFile);
    }
    return 0;
}