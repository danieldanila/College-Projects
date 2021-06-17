/*
    Problema rucsacului, varianta continuă. 
Să se scrie subprogramul C pentru rezolvarea problemei rucsacului.  
Se consideră un mijloc de transport cu o capacitate dată (C). 
Cu acesta trebuie transportate obiecte dintr-o mulțime A={a_i | i=1,n}. 
Fiecare obiect ocupă o capacitate specifică c_i și aduce un câștig specific v_i – fiecare obiect luat separat 
încape în mijlocul de transport. 
Se cere să se determine o modalitate de încărcare care să maximizeze cîștigul obținut la un transport. 
Obiectele transportate pot fi fractionate. În acest caz se va utiliza întotdeauna întreaga capacitate de transport.

    Problema rucsacului, varianta întreagă. 
Să se scrie subprogramul C pentru rezolvarea problemei rucsacului.  
Se consideră un mijloc de transport cu o capacitate dată (C). 
Cu acesta trebuie transportate obiecte dintr-o mulțime A={a_i | i=1,n}. 
Fiecare obiect ocupă o capacitate specifică c_i și aduce un câștig specific v_i – fiecare obiect luat separat 
încape în mijlocul de transport. 
Se cere să se determine o modalitate de încărcare care să maximizeze cîștigul obținut la un transport. 
Obiectele transportate nu pot fi fractionate.
*/

#include <stdio.h>

void sortare(float venituri[], float capacitati[], int dimensiune)
{
    float aux;

    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            if (venituri[i] / capacitati[i] < venituri[j] / capacitati[j])
            {
                aux = venituri[i];
                venituri[i] = venituri[j];
                venituri[j] = aux;

                aux = capacitati[i];
                capacitati[i] = capacitati[j];
                capacitati[j] = aux;
            }
        }
    }
}

void rucsac(float capacitateTotala, int dimensiune, float venituri[], float capacitati[], float vectorSolutie[])
{
    int i = 0;
    float capacitateRamasa = capacitateTotala;

    while (i < dimensiune && capacitateRamasa != 0)
    {
        if (capacitateRamasa >= capacitati[i])
        {
            capacitateRamasa -= capacitati[i];
            vectorSolutie[i] = 1; // daca e 1 inseamna ca am pus tot obiectul
        }
        else
        {
            vectorSolutie[i] = capacitateRamasa / capacitati[i]; // am pus o parte fractionara din obiect
            capacitateRamasa = 0;

            for (int j = i + 1; j < dimensiune; j++)
            {
                vectorSolutie[j] = 0;
            }
        }
        i++;
    }
}

void rucsac2(int dimensiune, float venituri[], float capacitati[], float vectorSolutie2[], float capacitateTotala)
{
    float capacitateRamasa2 = capacitateTotala;

    for (int i = 0; i < dimensiune; i++)
    {
        if (capacitateRamasa2 >= capacitati[i])
        {
            vectorSolutie2[i] = 1;
            capacitateRamasa2 -= capacitati[i];
        }
        else
        {
            vectorSolutie2[i] = 0;
        }
    }
}

int main()
{
    int numarObiecte;
    float venituri[100];
    float capacitati[100];
    float vectorSolutie[100];
    float vectorSolutie2[100];
    float capacitateTotala;
    float castigTotal;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &numarObiecte);

    printf("Introduceti veniutrile si capacitatile:\n");

    for (int i = 0; i < numarObiecte; i++)
    {
        printf("venituri[%d]: ", i);
        scanf("%f", &venituri[i]);

        printf("capacitati[%d]: ", i);
        scanf("%f", &capacitati[i]);
    }

    printf("Introduceti capacitatea totala a rucsacului: ");
    scanf("%f", &capacitateTotala);

    sortare(venituri, capacitati, numarObiecte);
    rucsac(capacitateTotala, numarObiecte, venituri, capacitati, vectorSolutie);

    for (int i = 0; i < numarObiecte; i++)
    {
        castigTotal += vectorSolutie[i] * venituri[i];

        printf("Obiectul %d: capacitati[%d] = %.2f\tvenituri[%d] = %.2f\tsolutie vector: %.2f\n", i + 1, i + 1, capacitati[i], i + 1, venituri[i], vectorSolutie[i]);
    }
    printf("Castigul total este: %.2f\n", castigTotal);

    rucsac2(numarObiecte, venituri, capacitati, vectorSolutie2, capacitateTotala);

    castigTotal = 0;

    for (int i = 0; i < numarObiecte; i++)
    {
        castigTotal += vectorSolutie2[i] * venituri[i];

        printf("Obiectul %d: capacitati[%d] = %.2f\tvenituri[%d] = %.2f\tsolutie vector: %.2f\n", i + 1, i + 1, capacitati[i], i + 1, venituri[i], vectorSolutie2[i]);
    }
    printf("Castigul total este: %.2f\n", castigTotal);
    return 0;
}