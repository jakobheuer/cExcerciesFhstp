// Heigl-Auer Jakob
// HeJ-Fence_List.h

#ifndef __Jakob_h__
#define __Jakob_h__
/*
typedef struct st_HeJsector
{
    short HeJstart;
    short HeJend;
    struct st_HeJsector * nextFile;
} t_HeJsector;
*/

typedef struct st_HeJsector
{
    short HeJstart;
    short HeJend;
    struct st_HeJsector * pNext;
} t_HeJsector, *pt_HeJsector;

t_HeJsector * HeJ_ReadSectorsFromFile(t_HeJsector * HeJ_pSectors,int argc,char **argv, int *highestEndMeter);
pt_HeJsector HeJ_CreateNode(pt_HeJsector next, const int startMeter, const int endMeter);
pt_HeJsector HeJ_InsertSector(pt_HeJsector node, const int startMeter, const int endMeter);
void HeJ_PrintAllDoneSectors(t_HeJsector * HeJ_pSectors);

#endif