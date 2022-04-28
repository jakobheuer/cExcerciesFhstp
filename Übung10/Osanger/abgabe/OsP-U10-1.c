/*
 * =====================================================================================
 *
 *       Filename:  UsP-U10-1.c
 *
 *    Description:  Get Input from Arguments and print if Number is happy or unhappy
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
#include "OsP_ValueTree.h"

int main(int argc, char *argv[])
{
    t_OsPTree *root = NULL;
    int num = 0;
    char c = 0;
    for(int i = 1; i <argc; ++i)
    {
        if(sscanf(argv[i], "%d%c", &num, &c) == 1 && num > 0)
        {
            OsP_insertTree(&root, num);
            printf("%d: %s\n", num, OsP_getIfHappy(&root, num) ? "Happy" : "Unhappy");
            OsP_printTree(root);
            OsP_freeTree(root);
            root = NULL;
        }
        else
            printf("Das %d. Argument ist keine ganzzahlige Positive Zahl!", i);
        putchar('\n');
    }
    return 0;
}
