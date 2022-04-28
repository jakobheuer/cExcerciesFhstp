// Jakob Heigl-Auer, Uebung 4 - Aufgabe 3
// HeJ-U4-3.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxArray 50

//Deklarationen
double * HeJ_einlesen(double *inputArray, int * pointerArrayLength);
double HeJ_mittelwertErmitteln(double inputArray[], int arrayLength);
void HeJ_sortieren(double inputArray[],int arrayLength);
void HeJ_benachbarteMitMinimalemAbstandErmitteln(double inputArray[], double nachbarn[],int arrayLength);
double HeJ_getMin(double inputArray[],int arrayLength);
double HeJ_getMax(double inputArray[],int arrayLength);
void swapElements(double *x, double *y);

int main(void)
{
    //Variablen
    int arrayLength = 0;
    double differenz=0;
    double mittelwert = 0;
    double nachbarn[2];
    double *array = calloc(1,sizeof(double));

    array = HeJ_einlesen(array,&arrayLength); //Funktionsaufruf, Userinput einlesen
    mittelwert = HeJ_mittelwertErmitteln(array,arrayLength); //Funktionsaufruf, Mittelwert ausrechnen
    printf("Mittelwert: %f\n",mittelwert);
    HeJ_benachbarteMitMinimalemAbstandErmitteln(array,nachbarn,arrayLength); //Nachbarn herausfinden
    printf("Nachbarn: 1: %f, 2: %f\n",nachbarn[0],nachbarn[1]);
    differenz = HeJ_getMax(array,arrayLength) - HeJ_getMin(array,arrayLength); //Differenz errechnen mithilfe von Funktion
    printf("Differenz zwischen Max(%.2f) und Min(%.2f) ist %.2f\n",HeJ_getMax(array,arrayLength), HeJ_getMin(array,arrayLength), differenz);
    free(array); //Speicher freigeben
    return 0;
}

double * HeJ_einlesen(double *inputArray, int * pointerArrayLength)
{
    //Variablen
    int iterator;
    int arrayLength=0;
    char continueInput[5];
    double inputNumber;

    for(iterator=0;iterator < maxArray;iterator++)
    {
        printf("Geben Sie eine Zahl ein: ");
        if(scanf("%lf", &inputNumber)!=1) //Scanf überprüfen
        {
            printf("Fehlerhafte Eingabe!\n");
            return 0;
        }
        else //Richtige eingabe
        {
            ++arrayLength; //Arraylänge anpassen
            inputArray = realloc(inputArray, arrayLength*sizeof(double)); //Array erweitern, Speicher holen
            inputArray[arrayLength-1]=inputNumber; //Eingegebenen zahl speichern
            printf("Wollen Sie eine Weitere Eingabe machen? Y/N: ");
            scanf("%c", (char *) stdin); //Catch trailing \n
            if(fgets(continueInput,sizeof(continueInput),stdin) != NULL)
            {
                if((strcmp(continueInput,"N\n") == 0) || (strcmp(continueInput,"n\n") == 0)) //Hat der benutzer N eingegeben abfrage beenden
                {
                    break;
                }
            }
            printf("\n");
        }
    }
    *pointerArrayLength = arrayLength; //Länge speichern

    return inputArray;
}

double HeJ_mittelwertErmitteln(double inputArray[],int arrayLength)
{
    int iterator;
    double sum=0;

    for(iterator=0;iterator<arrayLength;iterator++)
    {
        sum = sum + inputArray[iterator];
    }
    return sum/arrayLength;
}

void HeJ_sortieren(double inputArray[],int arrayLength) //Bubble sort
{
    int i, j;
    for (i = 0; i < arrayLength - 1; i++) //Bis zum vorletzen Element
        for (j = 0; j < arrayLength - i - 1; j++) //Von dem jetztigen Element bis zum letzten Element gehen
            if (inputArray[j] > inputArray[j + 1]) //Wenn das nächste Element kleiner ist
                swapElements(&inputArray[j], &inputArray[j + 1]); //Elemente tauschen
}

void swapElements(double* x, double* y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

void HeJ_benachbarteMitMinimalemAbstandErmitteln(double inputArray[], double nachbarn[],int arrayLength)
{
    double close1=0;
    double close2=0;
    double difference=0;
    double smallestDifference=0;

    HeJ_sortieren(inputArray,arrayLength);
    for (int i = 0; i < arrayLength-1; ++i)
    {
        if(i==0) //Noch keine "smallest difference" somit diese befüllen
        {
            smallestDifference = inputArray[i+1]-inputArray[i];
            close1=inputArray[i];
            close2=inputArray[i+1];
        }
        else
        {
            difference = inputArray[i+1]-inputArray[i];
            if(smallestDifference > difference) //Neues Paar mit kleinstem abstand gefunden
            {
                smallestDifference = difference;
                close1=inputArray[i];
                close2=inputArray[i+1];
            }
        }
    }

    nachbarn[0]=close1;
    nachbarn[1]=close2;
}

double HeJ_getMin(double inputArray[],int arrayLength)
{
    HeJ_sortieren(inputArray,arrayLength);
    return inputArray[0]; //Erstes Element des sortierten arrays ist das kleinste
}

double HeJ_getMax(double inputArray[],int arrayLength)
{
    HeJ_sortieren(inputArray,arrayLength);
    return inputArray[arrayLength-1]; //Letztes Element des sortierten arrays ist das größte
}