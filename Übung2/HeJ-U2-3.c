// Jakob Heigl-Auer, Uebung 2 - Aufgabe 3
// HeJ-U2-3.c

// Includes
#include <stdio.h>

int main()
{
    int inputMonth;
    char monatsnamen[12][50] = {{"Jänner"}, {"Februar"}, {"März"}, {"April"}, {"Mai"}, {"Juni"}, {"Juli"}, {"August"}, {"September"}, {"Oktober"}, {"November"}, {"Dezember"}};
    static const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(;;)
    {
        printf("Geben Sie ein Monat ein (0=Abbruch): ");
        scanf("%d",&inputMonth);

        if(inputMonth==0)
            return 0;
        else if(inputMonth < 0 || inputMonth > 12)
            printf("Eingabe Fehlerhaft!\n");
        else
            printf("%s hat %d Tage\n",monatsnamen[inputMonth-1],daysInMonth[inputMonth-1]);
    }
}