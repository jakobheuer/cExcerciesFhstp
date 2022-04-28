// Jakob Heigl-Auer, Uebung 3 - Aufgabe 2
// HeJ-U3-2.c

// Includes
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int startKoordinateX = 0;
    int startKoordinateY = 0;
    int zielKoordinateX = 0;
    int zielKoordinateY = 0;
    int benoetigteSchritteX;
    int benoetigteSchritteY;
    bool vorzeichenBenoetigteSchritteX = 1; //0 = Negativ, 1 = Positiv
    bool vorzeichenBenoetigteSchritteY = 1; //0 = Negativ, 1 = Positiv
    int steps = 0;

    printf("Geben Sie die Startkoordinaten ein \"X,Y\": ");
    if(scanf("%d,%d", &startKoordinateX, &startKoordinateY)!=2)
    {
        printf("Fehlerhafte Eingabe!\n");
        return 0;
    }
    printf("Geben Sie die Zielkoordinaten ein \"X,Y\": ");
    if(scanf("%d,%d", &zielKoordinateX, &zielKoordinateY)!=2)
    {
        printf("Fehlerhafte Eingabe!\n");
        return 0;
    }

    benoetigteSchritteX = zielKoordinateX - startKoordinateX;
    benoetigteSchritteY = zielKoordinateY - startKoordinateY;
    vorzeichenBenoetigteSchritteX = benoetigteSchritteX>=0;
    vorzeichenBenoetigteSchritteY = benoetigteSchritteY>=0;

    while(benoetigteSchritteX != 0 || benoetigteSchritteY !=0) //Bewegung erforderlich, ansonsten Ziel erreicht
    {
        if(benoetigteSchritteX != 0 && benoetigteSchritteY != 0) //Seitliche Bewegung
        {
            if((vorzeichenBenoetigteSchritteX == 0) && (vorzeichenBenoetigteSchritteY == 0)) //Links unten
            {
                printf(" SW ");
                benoetigteSchritteX = benoetigteSchritteX + 1;
                benoetigteSchritteY = benoetigteSchritteY + 1;
            }
            else if((vorzeichenBenoetigteSchritteX == 0) && (vorzeichenBenoetigteSchritteY == 1)) //Links oben
            {
                printf(" NW ");
                benoetigteSchritteX = benoetigteSchritteX + 1;
                benoetigteSchritteY = benoetigteSchritteY - 1;
            }
            else if((vorzeichenBenoetigteSchritteX == 1) && (vorzeichenBenoetigteSchritteY == 0)) //Rechts unten
            {
                printf(" SO ");
                benoetigteSchritteX = benoetigteSchritteX - 1;
                benoetigteSchritteY = benoetigteSchritteY + 1;
            }
            else // (vorzeichenBenoetigteSchritteX == 1) && (vorzeichenBenoetigteSchritteY == 1)) //Rechts oben
            {
                printf(" NO ");
                benoetigteSchritteX = benoetigteSchritteX - 1;
                benoetigteSchritteY = benoetigteSchritteY - 1;
            }
            ++steps;
        }
        else //Nur mehr gerade Bewegung
        {
            //printf("Nötig X/Y: %d,%d",benoetigteSchritteX,benoetigteSchritteY);
            //printf("Vorzeichen X/Y: %d,%d",vorzeichenBenoetigteSchritteX,vorzeichenBenoetigteSchritteY);
            if((benoetigteSchritteX != 0) && (vorzeichenBenoetigteSchritteX == 0)) // Bewegung links
            {
                printf(" W ");
                benoetigteSchritteX = benoetigteSchritteX + 1;
            }
            else if((benoetigteSchritteX != 0) && (vorzeichenBenoetigteSchritteX == 1)) //Bewegung rechts
            {
                printf(" O ");
                benoetigteSchritteX = benoetigteSchritteX - 1;
            }
            else if((benoetigteSchritteY != 0) && (vorzeichenBenoetigteSchritteY == 0)) //Bewegung runter
            {
                printf(" S ");
                benoetigteSchritteY = benoetigteSchritteY + 1;
            }
            else //((benoetigteSchritteY != 0) && (vorzeichenBenoetigteSchritteX == 1)) //Bewegung rauf
            {
                printf(" N ");
                benoetigteSchritteY = benoetigteSchritteY - 1;
            }
            ++steps;
        }
        //printf("\nSleep\n");
        //sleep(1);
    }
    printf("\nBenötigte Schritte: %d\n",steps);
    return 0;
}
