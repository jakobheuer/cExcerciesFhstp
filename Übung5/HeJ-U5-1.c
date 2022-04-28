// Jakob Heigl-Auer, Uebung 5 - Aufgabe 1
// HeJ-U5-1.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxArray 50

//Deklarationen
double * HeJ_einlesen(double *inputArray, int * pointerArrayLength);
double HeJ_mittelwertErmitteln(double *inputArray, int arrayLength);
void HeJ_sortieren(double *inputArray,int arrayLength);
void HeJ_benachbarteMitMinimalemAbstandErmitteln(double *inputArray, double *nachbarn,int arrayLength);
double HeJ_getMin(double *inputArray,int arrayLength);
double HeJ_getMax(double *inputArray,int arrayLength);
int cmpfunc (const void * a, const void * b);

int main(void)
{
    //Variablen
    int arrayLength = 0;
    double differenz=0;
    double mittelwert = 0;
    double nachbarn[2];
    double *array = calloc(1,sizeof(double));
    double *arraySafe = array; //Speichere erstes Element

    array = HeJ_einlesen(array,&arrayLength); //Funktionsaufruf, Userinput einlesen
    if(arrayLength>1){
        /*for (int i = 0; i < arrayLength; ++i) {
            printf("%f\n",*array);
            array++;
        }*/
        mittelwert = HeJ_mittelwertErmitteln(array,arrayLength); //Funktionsaufruf, Mittelwert ausrechnen
        printf("Mittelwert: %f\n",mittelwert);
        HeJ_benachbarteMitMinimalemAbstandErmitteln(array,nachbarn,arrayLength); //Nachbarn herausfinden
        printf("Nachbarn: 1: %f, 2: %f\n",nachbarn[0],nachbarn[1]);
        differenz = HeJ_getMax(array,arrayLength) - HeJ_getMin(array,arrayLength); //Differenz errechnen mithilfe von Funktion
        printf("Differenz zwischen Max(%.2f) und Min(%.2f) ist %.2f\n",HeJ_getMax(array,arrayLength), HeJ_getMin(array,arrayLength), differenz);
    }
    else
        printf("Zu wenige Zahlen eingegeben\n");
    free(arraySafe); //Speicher freigeben, muss erstes Element sein
    return 0;
}

double * HeJ_einlesen(double *inputArray, int * pointerArrayLength)
{
    //Variablen
    double *arraySafe = inputArray;
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
            inputArray = realloc(arraySafe, arrayLength*sizeof(double)); //Array erweitern, Speicher holen
            inputArray = inputArray + arrayLength;
            *inputArray=inputNumber; //Eingegebenen zahl speichern
            printf("%f\n",*inputArray);
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
    inputArray = inputArray - arrayLength + 1;
    return inputArray; //Erstes Element
}

double HeJ_mittelwertErmitteln(double *inputArray,int arrayLength)
{
    int iterator;
    double sum=0;

    for(iterator=0;iterator<arrayLength;iterator++)
    {
        sum = sum + *inputArray;
        ++inputArray;
    }
    return sum/arrayLength;
}

void HeJ_sortieren(double *inputArray,int arrayLength) //Bubble sort
{
    qsort(inputArray,arrayLength,sizeof(double),cmpfunc);
}

int cmpfunc (const void * a, const void * b)
{
    if (*(double*)a > *(double*)b)
        return 1;
    else if (*(double*)a < *(double*)b)
        return -1;
    else
        return 0;
}

void HeJ_benachbarteMitMinimalemAbstandErmitteln(double *inputArray, double *nachbarn,int arrayLength)
{
    double close1=0;
    double close2=0;
    double difference=0;
    double smallestDifference=0;
    double currentElement=0;
    double nextElement=0;

    HeJ_sortieren(inputArray,arrayLength);

    for (int i = 0; i < arrayLength-1; ++i)
    {
        currentElement = *inputArray;
        nextElement = *(inputArray+1);
        //printf("current: %f, next: %f\n",currentElement,nextElement);
        if(i==0) //Noch keine "smallest difference" somit diese befüllen
        {
            smallestDifference = nextElement-currentElement;
            close1=currentElement;
            close2=nextElement;
        }
        else
        {
            difference = nextElement-currentElement;
            if(smallestDifference > difference) //Neues Paar mit kleinstem abstand gefunden
            {
                smallestDifference = difference;
                close1=currentElement;
                close2=nextElement;
            }
        }
        ++inputArray;
    }

    nachbarn[0]=close1;
    nachbarn[1]=close2;
}

double HeJ_getMin(double *inputArray,int arrayLength)
{
    HeJ_sortieren(inputArray,arrayLength);
    return *inputArray; //Erstes Element des sortierten arrays ist das kleinste
}

double HeJ_getMax(double *inputArray,int arrayLength)
{
    HeJ_sortieren(inputArray,arrayLength);
    return *(inputArray+arrayLength-1); //Letztes Element des sortierten arrays ist das größte
}