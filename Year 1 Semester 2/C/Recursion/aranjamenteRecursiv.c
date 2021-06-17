/* Tema 3) Scrieți un subprogram recursiv care calculează Akn
(aranjamente de n luate cîte k), precum și programul apelator.
*/

#include <stdio.h>

float aranjamente1(int n, int k)
{
    float aranjamente;

    if (!k)
    {
        aranjamente = 1;
    }
    else
    {
        aranjamente = aranjamente1(n - 1, k - 1) * n;
    }
    return aranjamente;
}

float aranjamente2(int n, int kInitial, int kFinal)
{
    float aranjamente;

    if (kInitial == kFinal)
    {
        aranjamente = n - kInitial + 1;
    }
    else
    {
        aranjamente = aranjamente2(n, kInitial, (kInitial + kFinal) / 2) * aranjamente2(n, (kInitial + kFinal) / 2 + 1, kFinal);
    }
    return aranjamente;
}

int main()
{
    int n;
    int k;

    printf("Introduceti valoarea n: ");
    scanf("%d", &n);

    printf("Introduceti valoarea k: ");
    scanf("%d", &k);

    while (k > n)
    {
        printf("Eroare: k trebuie sa fie mai mic sau egal decat n!\n");

        printf("Introduceti valoarea n: ");
        scanf("%d", &n);

        printf("Introduceti valoarea k: ");
        scanf("%d", &k);
    }

    float aranjamenteMetodaReducerii = aranjamente1(n, k);
    float aranjamenteMetodaDescompunerii = aranjamente2(n, 1, k);

    printf("Aranjamente de n luate cate k (metoda reducerii): %.2f\n", aranjamenteMetodaReducerii);
    printf("Aranjamente de n luate cate k (metoda descompunerii): %.2f\n", aranjamenteMetodaDescompunerii);

    return 0;
}