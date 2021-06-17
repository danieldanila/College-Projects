/*
7.	Să se scrie programul care listează, într-un fişier text, studenţii integralişti, pe ani şi grupe,
calculând media fiecărei grupe şi a fiecărui an.
(expl. de problemă cu grade de total)

Pentru problema cu grade de total, fisierul trebuie să fie ordonat după caracteristicile de control

a)	Să se scrie programul care sortează studenţii după anii de studiu şi grupe.
(se va apela apoi problema 4). Se vor verifica datele daca sunt sortate

b)	Să se scrie programul care listează, într-un fişier text, studenţii integralişti, pe ani şi grupe,
calculând media fiecărei grupe şi a fiecărui an. (fisierul rezultat se va numi stud3.txt si
se va verifica rezultatul comparand cu datele din stud2.txt)
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
    FILE *binaryFile;
    Student student1;
    Student student2;

    char numeFisierBinar[20];
    printf("Introduceti numele fisierului binar (.dat): ");
    //fgets(numeFisier, 20, stdin);
    gets(numeFisierBinar);

    binaryFile = fopen(numeFisierBinar, "rb+");

    if (!binaryFile)
    {
        printf("Fisierul nu a putut fi deschis.");
    }
    else
    {
        int numarArticole = numar_articole(binaryFile, sizeof(Student));
        int esteSortat = 0;

        while (esteSortat == 0)
        {
            rewind(binaryFile);
            esteSortat = 1;
            for (int i = 0; i < numarArticole - 1; i++)
            {
                fseek(binaryFile, i * sizeof(Student), SEEK_SET);

                fread(&student1, sizeof(Student), 1, binaryFile);
                fread(&student2, sizeof(Student), 1, binaryFile);

                if (student1.an > student2.an || (student1.an == student2.an && student1.grupa > student2.grupa))
                {
                    esteSortat = 0;

                    fseek(binaryFile, i * sizeof(Student), SEEK_SET);

                    fwrite(&student2, sizeof(Student), 1, binaryFile);
                    fwrite(&student1, sizeof(Student), 1, binaryFile);
                }
            }
        }
        fclose(binaryFile);
    }

    Student student;
    FILE *textFile;

    char numeFisierText[20];

    float mediaGrupa;
    float mediaAn;
    float mediaStudent;
    int esteIntegralist;
    int numarIntegralistiGrupa;
    int numarIntegralistiAn;
    int grupaCurenta;
    int anCurent;

    binaryFile = fopen(numeFisierBinar, "rb+");

    if (!binaryFile)
    {
        printf("Fisierul nu s-a putut deschide.");
    }
    else
    {
        printf("Numele fisierului text (.txt): ");
        // fgets()
        gets(numeFisierText);

        textFile = fopen(numeFisierText, "w");

        fread(&student, sizeof(Student), 1, binaryFile);

        while (!feof(binaryFile))
        {
            anCurent = student.an;
            fprintf(textFile, "\n\nAnul: %d", anCurent);
            mediaAn = 0;
            numarIntegralistiAn = 0;

            while (!feof(binaryFile) && anCurent == student.an)
            {
                mediaGrupa = 0;
                numarIntegralistiGrupa = 0;
                grupaCurenta = student.grupa;
                fprintf(textFile, "\n\tGrupa: %d", grupaCurenta);

                while (!feof(binaryFile) && anCurent == student.an && grupaCurenta == student.grupa)
                {
                    esteIntegralist = 1;
                    mediaStudent = 0;

                    for (int i = 0; i < student.numarNote; i++)
                    {
                        if (student.note[i] < 5)
                        {
                            esteIntegralist = 0;
                        }
                        else
                        {
                            mediaStudent = mediaStudent + student.note[i];
                        }
                    }

                    if (esteIntegralist)
                    {
                        mediaStudent = mediaStudent / student.numarNote;
                        mediaGrupa = mediaGrupa + mediaStudent;
                        numarIntegralistiGrupa++;
                        fprintf(textFile, "\n\t\t%4d %-30s Media %5.2f Note: ", student.numarMatricol, student.nume, mediaStudent);
                        for (int i = 0; i < student.numarNote; i++)
                        {
                            fprintf(textFile, "%2d ", student.note[i]);
                        }
                    }
                    fread(&student, sizeof(Student), 1, binaryFile);
                }

                if (numarIntegralistiGrupa > 0)
                {
                    fprintf(textFile, "\n\tGrupa %d, media: %5.2f", grupaCurenta, mediaGrupa / numarIntegralistiGrupa);
                    mediaAn = mediaAn + mediaGrupa;
                    numarIntegralistiAn = numarIntegralistiAn + numarIntegralistiGrupa;
                }
                else
                {
                    fprintf(textFile, "\nGrupa nu are integralisti");
                }
            }

            if (numarIntegralistiAn > 0)
            {
                fprintf(textFile, "\nMedia anului %d este: %5.2f", anCurent, mediaAn / numarIntegralistiAn);
            }
            else
            {
                fprintf(textFile, "\nAnul nu are integralisti");
            }
        }
        fclose(binaryFile);
        fclose(textFile);
    }
    return 0;
}