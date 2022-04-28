#ifndef __OsP_VALUETREE__
#define __OsP_VALUETREE__
/*
 * =====================================================================================
 *
 *       Filename:  OsP_ValueTree.c
 *
 *    Description:  Funktionendeklaration Tree
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
#include <stdbool.h>
typedef struct st_OsPTree
{
    int value;
    struct st_OsPTree *pleft;
    struct st_OsPTree *pright;
}t_OsPTree;

void OsP_insertTree(t_OsPTree **root, int value);
void OsP_freeTree(t_OsPTree *root);
void OsP_printTree(t_OsPTree *root);
bool OsP_findValue(t_OsPTree *root, int value);
bool OsP_getIfHappy(t_OsPTree **root, int value);
#endif