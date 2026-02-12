#include <stdio.h>

/* Apuntadores y arreglos */

int main()
{
    int X = 5, Y = 8, V[5] = {1, 3, 5, 7, 9};
    int *AX, *AY;
    AX = &X;
    AY = &V[3];
    printf("\nX=%d Y=%d V[0]=%d V[1]=%d V[2]=%d V[3]=%d V[4]=%d", X, Y, V[0], V[1], V[2], V[3], V[4]);
    X = *AY;
    Y = *AX;
    V[2] = X + Y;
    printf("\nX=%d Y=%d V[0]=%d V[1]=%d V[2]=%d V[3]=%d V[4]=%d", X, Y, V[0], V[1], V[2], V[3], V[4]);
    AX = &V[0];
    AY = &V[4];
    *AX = *AY + 3;
    *(AX+1) = *AY - 5;
    printf("\nX=%d Y=%d V[0]=%d V[1]=%d V[2]=%d V[3]=%d V[4]=%d", X, Y, V[0], V[1], V[2], V[3], V[4]);
    
    return 0;
}