// Jakob Heigl-Auer, Uebung 2 - Aufgabe 2
// HeJ-U2-2.c

//Includes
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    float a, b, c;
    bool isDreieck; // 1 = Ist ein Dreieck, 0 = Ist kein Dreieck
    bool isGleichseitig; // 1 = Ist gleichseitig, 0 = Ist nicht gleichseitig
    bool isGleichschenkelig; // 1=True, 0=False
    bool isRechtwinkelig; // 1=True, 0=False
    float flaeche;
    float umfang;
}dreieck;

dreieck checkIfDreieck(dreieck inputDreieck)
{
    inputDreieck.isDreieck = (((inputDreieck.a + inputDreieck.b) > inputDreieck.c) && ((inputDreieck.a + inputDreieck.c) > inputDreieck.b) && ((inputDreieck.b + inputDreieck.c) > inputDreieck.a)) ? 1 : 0;
    return inputDreieck;
}

dreieck checkIfGleichseitig(dreieck inputDreieck)
{
    inputDreieck.isGleichseitig = (inputDreieck.a == inputDreieck.b && inputDreieck.b == inputDreieck.c) ? 1 : 0;
    return inputDreieck;
}

dreieck checkIfGleichschenklig(dreieck inputDreieck)
{
    inputDreieck.isGleichschenkelig = (inputDreieck.a == inputDreieck.b || inputDreieck.a == inputDreieck.c || inputDreieck.b == inputDreieck.c) ? 1 : 0;
    return inputDreieck;
}

dreieck checkIfRechtwinklig(dreieck inputDreieck)
{
    inputDreieck.isRechtwinkelig = (((pow(inputDreieck.a,2)+pow(inputDreieck.b,2))==pow(inputDreieck.c,2)) || ((pow(inputDreieck.a,2)+pow(inputDreieck.c,2))==pow(inputDreieck.b,2)) || ((pow(inputDreieck.b,2)+pow(inputDreieck.c,2))==pow(inputDreieck.a,2))) ? 1 : 0;
    return inputDreieck;
}

dreieck calculateDreieck(dreieck inputDreieck)
{
    float s;
    s = (inputDreieck.a + inputDreieck.b + inputDreieck.c) / 2;
    inputDreieck.flaeche = sqrt(s* (s - inputDreieck.a) * (s - inputDreieck.b) * (s - inputDreieck.c));
    inputDreieck.umfang = (inputDreieck.a + inputDreieck.b + inputDreieck.c);
    return inputDreieck;
}

void dreieckAusgabe(dreieck inputDreieck)
{
    inputDreieck = checkIfDreieck(inputDreieck);
    if(inputDreieck.isDreieck)
    {
        inputDreieck = checkIfGleichseitig(inputDreieck);
        inputDreieck = checkIfGleichschenklig(inputDreieck);
        inputDreieck = checkIfRechtwinklig(inputDreieck);
        inputDreieck = calculateDreieck(inputDreieck);
        printf("Es ist ein Dreieck");
        if(inputDreieck.isGleichschenkelig)
            printf(" & Gleichschenklig");
        if(inputDreieck.isGleichseitig)
            printf(" & Gleichseitig");
        if(inputDreieck.isRechtwinkelig)
            printf(" & Rechtwinklig");
        printf("\nDer Umfang ist %.2f und die Fläche %.2f\n",inputDreieck.umfang,inputDreieck.flaeche);
    }
    else
        printf("\nDie Eingabe ist kein Dreieck!\n");
}

int main()
{
    dreieck inputDreieck;
    printf("Geben Sie die drei Seiten des Dreiecks an (a/b/c): ");
    scanf("%f/%f/%f",&inputDreieck.a,&inputDreieck.b,&inputDreieck.c);
    dreieckAusgabe(inputDreieck);
    return 0;
}