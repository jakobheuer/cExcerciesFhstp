// Jakob Heigl-Auer, Uebung 1 - Aufgabe 4
// HeJ-U1-4.c

// Includes
#include <stdio.h>

int main()
{
    int sec, d, h, m, s; //Variablen

    printf("Geben Sie eine Zeitdauer in Sekunden ein: ");
    scanf("%d",&sec); //User abfrage
    d = (sec/86400); //Tage berechnen
    h = (sec-(86400*d))/3600; //Stunden berechnen
	m = (sec -(86400*d)-(3600*h))/60; //Minuten berechnen
	s = (sec -(86400*d)-(3600*h)-(m*60)); //Sekunden berechnen
	printf("\nDas sind %d Tage, %d Stunden, %d Minuten, %d Sekunden\n",d,h,m,s);
	return 0;
}