// Jakob Heigl-Auer, Uebung 3 - Aufgabe 4
// HeJ-U3-4.c

// Includes
#include <stdio.h>
#include "HeJ-RiverFkt.h"

#define sequenceLength 20

int main(void)
{
    int riverEnd=0;
    int currentRiverState=0; //An welcher Riverzahl bin ich gerade
    int iterator;
    printf("Geben Sie einen River an: ");
    if(scanf("%d", &riverEnd)!=1)
    {
        printf("Fehlerhafte Eingabe!\n");
        return 0;
    }

    for(iterator = 1; iterator <= riverEnd; iterator++)
    {
        currentRiverState = iterator;
        while(currentRiverState <= riverEnd)
        {
            if(currentRiverState==riverEnd)
            {
                printf("%d trifft %d\n",iterator,riverEnd);
            }
            currentRiverState = HeJ_NextRiverNum(currentRiverState);
        }
    }
    return 0;
}