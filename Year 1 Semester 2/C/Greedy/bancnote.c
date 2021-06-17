/* 
Să se scrie subprogramul C care permite plata unei sume S∈N folosind cît mai puține bancnote 
din tipurile (valorile) a_i,i=1,n, știind că printre acestea se află și bancnota cu valoare unitate.
Sunt disponibile cantități nelimitate din fiecare tip de bancnotă.
*/

#include <stdio.h>

void interschimbare(int *bancnota1, int *bancnota2)
{
    if (*bancnota1 < *bancnota2)
    {
        int aux = *bancnota2;
        *bancnota2 = *bancnota1;
        *bancnota1 = aux;
    }
}

void sortare(int dimensiune, int vectorBancnote[])
{
    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            interschimbare(&vectorBancnote[i], &vectorBancnote[j]);
        }
    }
}

void suma_subprogram(int vectorBancnote[], int dimensiune, int suma, int vectorSolutie[])
{
    int sumaRamasa = suma;
    int i = 0;
    while (i < dimensiune && sumaRamasa != 0)
    {
        vectorSolutie[i] = sumaRamasa / vectorBancnote[i];
        sumaRamasa = sumaRamasa - vectorBancnote[i] * vectorSolutie[i]; // acelasi lucru ca si cum ai pune restul in suma Ramasa
        i++;
    }

    for (int j = i; j < dimensiune; j++)
    {
        vectorSolutie[j] = 0;
    }
}

int main()
{
    int suma;
    int dimensiune = 7;
    int vectorBancnote[] = {1, 5, 10, 50, 100, 200, 500};
    int vectorSolutie[7];
    sortare(dimensiune, vectorBancnote);
    printf("Introduceti suma: ");
    scanf("%d", &suma);

    suma_subprogram(vectorBancnote, dimensiune, suma, vectorSolutie);

    for (int i = 0; i < dimensiune; i++)
    {
        printf("bancnota %d * %d = %d\n", vectorBancnote[i], vectorSolutie[i], vectorBancnote[i] * vectorSolutie[i]);
    }

    return 0;
}