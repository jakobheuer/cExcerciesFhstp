// Jakob Heigl-Auer, Uebung 2 - Aufgabe 1
// HeJ-U2-1.c

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int inputDay,inputMonth,inputYear;
    bool leapyear;
    static const int accumulativeDaysInMonth[2][12] = {
            { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
            { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
    };
    static const int daysInMonth[2][12] = {
            { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };


    printf("Geben Sie ein Datum ein (Tag.Monat.Jahr): ");
    scanf("%d.%d.%d",&inputDay,&inputMonth,&inputYear);

    if(inputMonth>=1 && inputMonth<=12) //Monat überprüfen
    {
        leapyear = ((inputYear%400==0 ||(inputYear%4==0 && inputYear%100!=0))) ? 1 : 0;
        if(inputDay < 0 || (inputDay > daysInMonth[leapyear][inputMonth-1]))
        {
            printf("Der Tag ist zu klein oder zu groß für das entsprechende Monat\n");
            exit(0);
        }
        else
            printf("Der Tag existiert.\n");
    }
    else
    {
        printf("Das Monat ist falsch.\n");
        exit(0);
    }

    printf("Der Tag ist der %d im Jahr.\n",accumulativeDaysInMonth[leapyear][inputMonth-1]+inputDay);
    return 0;
}