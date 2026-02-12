#include <stdio.h>

/* Expresión y función.
El programa escribe los valores de T, P y Q que satisfacen una expresión. */

int expresion(int, int, int);

int main(void)
{
    int t, p, q, res;
    for (t = 1; t <= 10; t++)
        for (p = 1; p <= 10; p++)
            for (q = 1; q <= 10; q++)
            {
                res = expresion(t, p, q);
                if (res < 500)
                    printf("\nT: %d \tP: %d \tQ: %d \tResultado: %d", t, p, q, res);
            }
    return 0;
}

int expresion(int t, int p, int q)
{
    int res;
    res = 2 * (t * t) + 3 * (p * p * p) + 5 * (q * q * q * q);
    return res;
}