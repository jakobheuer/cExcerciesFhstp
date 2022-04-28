// Jakob Heigl-Auer, Uebung 1 - Aufgabe 3
// HeJ-U1-3.c

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	//Variablen
    int startX=0;
    int startY=0;
    int zielX=0;
    int zielY=0;
    int a=0;
    int b=0;
    double c=0;

    //User Abfrage
    printf("Start-X: ");
    scanf("%d", &startX);
    printf("Start-Y: ");
    scanf("%d", &startY);
    printf("Ziel-X: ");
    scanf("%d", &zielX);
    printf("Ziel-Y: ");
    scanf("%d", &zielY);

    a = abs(startX-zielX); //Berechnung der Distanz zwischen der Start und Ziel X Koordinate
    b = abs(startY-zielY); //Berechnung der Distanz zwischen der Start und Ziel Y Koordinate
    c = sqrt(pow(a,2)+pow(b,2)); //Berechnung der Distanz mit Pythagoras
    printf("Distanz: %.4lf\n",c);
    if(startX != zielY && startY != zielY) //Überprüfung ob Start- und Zielpunkt nicht auf den selben Koordinaten liegen
    {
        printf("Hauptbewegungsrichtung: nach");
        if(a>b) // X-Achse ist weiter
            {
                if(startX<zielX) // Bewegung nach rechts
                    printf(" rechts\n");
                else// Bewegung nach links
                    printf(" links\n");
            }
        else // Y-Achse ist weiter
        {
            if(startY<zielY) // Bewegung nach oben
               printf(" oben\n");
            else // Bewegung nach unten
                printf(" unten\n");
        }
    }
    else //Start und Ziel liegen auf dem selben Punkt
    {
        printf("Der Startpunkt liegt auf dem Zielpunkt\n");
    }
        

	return 0;
}