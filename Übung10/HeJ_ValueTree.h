// Heigl-Auer Jakob
// Main: HeJ-U10.c

#ifndef __Jakob_h__
#define __Jakob_h__

#include <stdbool.h>

typedef struct st_HeJnode
{
    int number;
    struct st_HeJnode * pLeftChild;
    struct st_HeJnode * pRightChild;
} t_HeJNode;

void HeJ_insertTree(t_HeJNode **head, const int number);
void HeJ_freeTree(t_HeJNode *head);
void HeJ_printTree(t_HeJNode *head);
bool HeJ_findValue(t_HeJNode *head, const int number);
bool HeJ_getIfHappy(t_HeJNode **head, int number);


#endif