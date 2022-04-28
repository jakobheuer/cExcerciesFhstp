// Heigl-Auer Jakob, Mario Holzer
// HeJ-Fence_List.h

//Includes
#include "HeJ_Fence_List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

t_HeJsector * HeJ_ReadSectorsFromFile(t_HeJsector * HeJ_pSectors,int argc,char **argv, int *highestEndMeter)
{
    FILE *filePointer;
    char readLine[50];
    int startMeter,endMeter;
    if(argc==2)
    {
        if( access( argv[1], F_OK ) == 0 ) { //File ist lesbar
            filePointer = fopen(argv[1],"r"); //File im Lesemodus öffnen //TODO: Fopen überprüfen, nicht access
            while(fgets(readLine,50,filePointer)) //Zeilenweise einlesen
            {
                if(sscanf(readLine, "%d:%d", &startMeter, &endMeter) != 2) //Wenn 2 Zahlen richtig gelesen wurden //TODO: Fscanf
                    printf("Error reading input\n");
                else //Zeile eingelesen, jetzt verarbeiten
                {
                    *highestEndMeter = (*highestEndMeter < endMeter) ? endMeter : *highestEndMeter;
                    HeJ_pSectors = HeJ_InsertSector(HeJ_pSectors, startMeter, endMeter);
                }
            }
            fclose(filePointer);
        }
    }
    return HeJ_pSectors;
}

pt_HeJsector HeJ_CreateNode(pt_HeJsector next, const int startMeter, const int endMeter) //Von Mario Holzer
{
    pt_HeJsector help = (pt_HeJsector)malloc(sizeof(t_HeJsector));
    help->HeJstart = startMeter;
    help->HeJend = endMeter;
    help->pNext = next;
    return help;
}

pt_HeJsector HeJ_InsertSector(pt_HeJsector node, const int startMeter, const int endMeter) //Von Mario Holzer
{
    if ((node == NULL) || !(node->HeJstart < startMeter))
    {
        return HeJ_CreateNode(node, startMeter, endMeter);
    }
    node->pNext = HeJ_InsertSector(node->pNext, startMeter, endMeter);
    return node;
}

void HeJ_PrintAllDoneSectors(t_HeJsector * HeJ_pSectors)
{
    do {
        printf("Start %d, End %d \n",HeJ_pSectors->HeJstart,HeJ_pSectors->HeJend);
        HeJ_pSectors = HeJ_pSectors->pNext;
    } while (HeJ_pSectors != NULL); //TODO: While statt do while
}





