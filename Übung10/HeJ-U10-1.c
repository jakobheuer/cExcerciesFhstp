// Jakob Heigl-Auer, Uebung 10 - Aufgabe 1
// HeJ-U10-1.c

// Includes
#include <stdio.h>
#include <stdlib.h>
#include "HeJ_ValueTree.h"
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    t_HeJNode *head = NULL;
    bool unhappyHappy = 0; //1 = Happy
    if(argc>1)
    {
        for (int i = 1; i < argc; ++i)
        {
            if(atoi(argv[i])!=0)
            {
                HeJ_insertTree(&head, atoi(argv[i]));
                unhappyHappy =  HeJ_getIfHappy(&head, atoi(argv[i]));
                if(unhappyHappy==1)
                    printf("%d is happy :)\n",atoi(argv[i]));
                else
                    printf("%d is unhappy :(\n",atoi(argv[i]));
                HeJ_printTree(head);
                printf("\n\n");
                HeJ_freeTree(head);
                head = NULL;
            }
            else
                printf("Error: [%s] Invalid Input\n\n",argv[i]);
        }
    }
    return 0;
}