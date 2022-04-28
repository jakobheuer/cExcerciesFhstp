// Jakob Heigl-Auer, Uebung 9 - Aufgabe 1
// HeJ-U9-1.c

// Includes
#include <stdio.h>
#include <stdlib.h>
#include "HeJ_Fence_List.h"
#include <string.h>

int * HeJ_PaintFence(int * HeJ_Fence, t_HeJsector * HeJ_pSectors);
void findLastPaintedMeter(int highestEndMeter);
void findMultiPaintedMeter(int * HeJ_Fence,int highestEndMeter);
void findUnpaintedMeter(int * HeJ_Fence,int highestEndMeter);

int main(int argc, char *argv[])
{
    t_HeJsector * HeJ_pSectors = NULL; //Pointer to first struct
    t_HeJsector * tmp = NULL;
    int highestEndMeter;
    int *HeJ_Fence;
    HeJ_pSectors = HeJ_ReadSectorsFromFile(HeJ_pSectors,argc,argv,&highestEndMeter);
    HeJ_Fence = (int *)calloc(highestEndMeter,sizeof (int ));

    HeJ_Fence = HeJ_PaintFence(HeJ_Fence,HeJ_pSectors);
    HeJ_PrintAllDoneSectors(HeJ_pSectors);
    findLastPaintedMeter(highestEndMeter);
    findMultiPaintedMeter(HeJ_Fence,highestEndMeter);
    findUnpaintedMeter(HeJ_Fence,highestEndMeter);

    //Free
    free(HeJ_Fence);
    while (HeJ_pSectors != NULL)
    {
        tmp = HeJ_pSectors;
        HeJ_pSectors = HeJ_pSectors->pNext;
        free(tmp);
    }
    return 0;
}

int * HeJ_PaintFence(int * HeJ_Fence, t_HeJsector * HeJ_pSectors)
{
    do {
        for (int i = HeJ_pSectors->HeJstart; i <= HeJ_pSectors->HeJend; ++i) { //Vom ersten bis zum letzten Meter im struct
            HeJ_Fence[i] += 1; //Wert im Array um 1 erhöhen
        }
        HeJ_pSectors = HeJ_pSectors->pNext; //Nächstes Struct
    } while (HeJ_pSectors != NULL);

    return HeJ_Fence;
}

void findLastPaintedMeter(int highestEndMeter)
{
    printf("Last painted Meter: %d\n",highestEndMeter);
}

void findMultiPaintedMeter(int * HeJ_Fence,int highestEndMeter)
{
    for (int i = 0; i < highestEndMeter; ++i) {
        if(HeJ_Fence[i]>1)
            printf("Meter %d was painted %d times\n",i,HeJ_Fence[i]);
    }
}

void findUnpaintedMeter(int * HeJ_Fence,int highestEndMeter)
{
    for (int i = 0; i < highestEndMeter; ++i) {
        if(HeJ_Fence[i] == 0)
            printf("Meter %d is unpainted\n",i);
    }
}