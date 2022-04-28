/*
 * =====================================================================================
 *
 *       Filename:  OsP_ValueTree.c
 *
 *    Description:  Tree aufbau
 *
 *        Version:  1.0
 *        Created:  26/04/22 08:51:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Philipp Osanger (is211024), is211024@fhstp.ac.at
 *   Organization:  FH St. Poelten
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <malloc.h>
#include "OsP_ValueTree.h"

void OsP_insertTree(t_OsPTree **root, int value)
{
    if(*root == NULL)
    {
        t_OsPTree *q = (t_OsPTree *)malloc(sizeof(t_OsPTree));
		q->value = value;
		q->pright = NULL;
		q->pleft = NULL;
        *root = q;
    }
    else
    {
        if(value >= (*root)->value)
            OsP_insertTree(&(*root)->pright, value);
        else
            OsP_insertTree(&(*root)->pleft, value);
    }
}

void OsP_freeTree(t_OsPTree *root)
{
    if(root != NULL)
    {
        OsP_freeTree(root->pleft);
        OsP_freeTree(root->pright);
        free(root);
    }
}

void OsP_printTree(t_OsPTree *root)
{
    if(root == NULL)
        return;
    OsP_printTree(root->pleft);
    printf("%d ", root->value);
    OsP_printTree(root->pright);
}

bool OsP_findValue(t_OsPTree *root, int value)
{
    if(root == NULL)
        return false;
    if(root->value == value)
        return true;
    else if(value > root->value)
        return OsP_findValue(root->pright, value);
    else
        return OsP_findValue(root->pleft, value);
}

bool OsP_getIfHappy(t_OsPTree **root, int value)
{
    int tmp = 0;
    int erg = 0;
    for(; value != 0; value /= 10)
    {
        tmp = value % 10;
        erg = erg + tmp * tmp;
    }
    if(erg == 1)
        return true;
    else if(!OsP_findValue(*root, erg))
    {
        OsP_insertTree(root, erg);
        return OsP_getIfHappy(root, erg);
    }
    return false;

}