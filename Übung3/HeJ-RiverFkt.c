// Heigl-Auer Jakob
// HeJ-RiverFkt.c

//Includes
#include "HeJ-RiverFkt.h"

int HeJ_digitsum(int num)
{
    int sum = 0;
    int modulo = 0;
    while(num>0)
    {
        modulo=num%10;
        sum=sum+modulo;
        num=num/10;
    }
    return sum;
}

int HeJ_NextRiverNum(int num)
{
    num = num + HeJ_digitsum(num);
    return num;
}