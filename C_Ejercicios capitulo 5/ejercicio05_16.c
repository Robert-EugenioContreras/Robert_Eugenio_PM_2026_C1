#include <stdio.h>

/* Apuntadores y arreglos */

int main()
{
    int V1[3] = {5, 10, 15}, V2[3] = {20, 25, 30};
    int *AX, *AY;
    AX = &V1[0];
    AY = &V2[0];
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d", V1[0], V1[1], V1[2], V2[0], V2[1], V2[2]);
    *AX = *AY + 10;
    *(AX+1) = *(AY+1) + 10;
    *(AX+2) = *(AY+2) + 10;
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d", V1[0], V1[1], V1[2], V2[0], V2[1], V2[2]);
    AX = &V1[2];
    AY = &V2[2];
    *AX = *AY - 5;
    *(AX-1) = *(AY-1) - 5;
    *(AX-2) = *(AY-2) - 5;
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d", V1[0], V1[1], V1[2], V2[0], V2[1], V2[2]);
    
    return 0;
}