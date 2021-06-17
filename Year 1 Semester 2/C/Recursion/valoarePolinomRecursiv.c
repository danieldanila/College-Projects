/* Tema 2) Să se scrie subprogramul recursiv care calculează valoarea 
unui polinom într-un punct dat, precum și programul apelator. */

#include <stdio.h>
#include <math.h>

float valoarePolinom1(int gradPolinom, float coeficientiPolinom[], float valoareNecunoscutaX) // metoda reducerii
{
    float valoarePolinom;
    if (!gradPolinom)
    {
        valoarePolinom = coeficientiPolinom[0];
    }
    else
    {
        valoarePolinom = valoarePolinom1(gradPolinom - 1, coeficientiPolinom, valoareNecunoscutaX) + coeficientiPolinom[gradPolinom] * pow(valoareNecunoscutaX, gradPolinom);
    }

    return valoarePolinom;
}

float valoarePolinom2(int gradPolinomInceput, int gradPolinomFinal, float coeficientiPolinom[], float valoareNecunoscutaX) // metoda descompunerii
{
    float valoarePolinom;

    if (gradPolinomInceput == gradPolinomFinal)
    {
        valoarePolinom = coeficientiPolinom[gradPolinomInceput];
    }
    else
    {
        valoarePolinom = valoarePolinom2(gradPolinomInceput, (gradPolinomInceput + gradPolinomFinal) / 2, coeficientiPolinom, valoareNecunoscutaX) + valoarePolinom2((gradPolinomInceput + gradPolinomFinal) / 2 + 1, gradPolinomFinal, coeficientiPolinom, valoareNecunoscutaX);
    }

    return valoarePolinom;
}

int main()
{
    int gradPolinom;
    float coeficientiPolinom[100];
    float valoareNecunoscutaX;

    printf("Introduceti gradul polinomului: ");
    scanf("%d", &gradPolinom);

    while (gradPolinom < 0)
    {
        printf("Gradul polinomului nu poate fi negativ!\n");
        printf("Introduceti gradul polinomului: ");
        scanf("%d", &gradPolinom);
    }

    for (int i = 0; i < gradPolinom + 1; i++)
    {
        printf("Introduceti coeficientul %d: ", i);
        scanf("%f", &coeficientiPolinom[i]);
    }

    printf("Introduceti valoarea necunoscutei X: ");
    scanf("%f", &valoareNecunoscutaX);

    float valoarePolinomMetodaReducerii = valoarePolinom1(gradPolinom, coeficientiPolinom, valoareNecunoscutaX);
    float valoarePolinomMetodaDescompunerii = valoarePolinom2(0, gradPolinom, coeficientiPolinom, valoareNecunoscutaX);

    printf("Valoarea polinomului este (metoda reducerii): %.2f\n", valoarePolinomMetodaReducerii);
    printf("Valoarea polinomului este (metoda descompunerii): %.2f\n", valoarePolinomMetodaReducerii);

    return 0;
}
