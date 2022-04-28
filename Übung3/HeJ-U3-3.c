// Jakob Heigl-Auer, Uebung 3 - Aufgabe 3
// HeJ-U3-3.c

// Includes
#include <stdio.h>
#include "HeJ-RiverFkt.h"

#define sequenceLength 20

int main(void)
{
    int N=0;
    int iterator;
    printf("Geben Sie die Startnummer des Rivers an: ");
    if(scanf("%d", &N)!=1)
    {
        printf("Fehlerhafte Eingabe!\n");
        return 0;
    }
    for(iterator = 0; iterator < sequenceLength; iterator++)
    {
        printf("%d: %d\n",iterator+1, N);
        N = HeJ_NextRiverNum(N);
    }
    return 0;
}