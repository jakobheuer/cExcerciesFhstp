// Jakob Heigl-Auer, Uebung 4 - Aufgabe 1
// HeJ-U4-1.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define maxLineLength 50
static const char lowerCaseLetters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
static const char upperCaseLetters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
static const char normalDigits[10]={'0','1','2','3','4','5','6','7','8','9'};
static const char shiftedDigits[10]={'9','0','1','2','3','4','5','6','7','8'};

void HelowerJ(char *pointerString)
{
    int iterator;
    while (*pointerString!='\0'){
        for(iterator=0;iterator<sizeof(lowerCaseLetters);iterator++) //Geht jeden Buchstaben durch
        {
            if(*pointerString==upperCaseLetters[iterator]) //Wenn Großbuchstabe mach klein
                *pointerString=lowerCaseLetters[iterator];
        }
        ++pointerString; //Nächstes Element
    }
}

void HeshiftDigitsJ(char *pointerString)
{
    int iterator;
    while (*pointerString!='\0'){
        for(iterator=0;iterator<sizeof(normalDigits);iterator++) //Geht jede Zahl durch
        {
            if(*pointerString==normalDigits[iterator]){ //Wenn Char eine Zahl dann austauschen mit geshifteter Zahl
                *pointerString=shiftedDigits[iterator];
                break; //Zahl geändert, Aufgabe erfüllt
            }
        }
        ++pointerString; //Nächstes Element
    }
}

void HeshortenJ(char *pointerString)
{
    int iterator;
    int arrayPosition;
    int arrayLength=0;
    bool isSpecialChar=1;
    while(*pointerString != '\0') //Rutsche Pointer bis zum Ende des Arrays
    {
        ++pointerString;
        ++arrayLength; //Zähle Länge des Inputs
    }
    pointerString = pointerString - 2;//Nun ist der Pointer am letzten vom Benutzer eingegebenen Zeichen
    --arrayLength; //\0 ignorieren

    for(arrayPosition=0;arrayPosition<arrayLength;arrayPosition++) //Geh Array von Hinten bis Vorne durch
    {
        for(iterator=0;iterator<sizeof(upperCaseLetters);iterator++)
        {
            if(iterator<=9) //Überprüfe auf Buchstaben und Zahlen
            {
                if(*pointerString==normalDigits[iterator] || *pointerString==lowerCaseLetters[iterator] || *pointerString==upperCaseLetters[iterator])
                {
                    isSpecialChar=0; //Kein Special Character gefunden
                    break;
                }
            }
            else //Nur mehr Buchtsaben überprüfen
            {
                if(*pointerString==lowerCaseLetters[iterator] || *pointerString==upperCaseLetters[iterator])
                {
                    isSpecialChar=0; //Kein Special Character gefunden
                    break;
                }
            }
        }
        if(isSpecialChar) //Zeichen ist ein Sonderzeichen, mit \0 überschreiben
            *pointerString='\0';
        else //Letzes Zeichen kein Sonderzeichen
            break;

        isSpecialChar=1; //Setzt Boolean auf 1, wird nur auf 0 geändert falls Zeichen kein Special Character ist
        --pointerString; //1 Schritt nach vorne
    }
}

void allManipulations(char *pointerString) //Ruft alle Funktionen auf
{
    HelowerJ(pointerString);
    HeshiftDigitsJ(pointerString);
    HeshortenJ(pointerString);
}

int main(void)
{
    char line[maxLineLength];
    printf("Geben Sie einen String ein, dann wird dieser Manipuliert. Mit \"quit\" wird das Programm beendet!\n");
    for (;;)
    {
        if (fgets(line, maxLineLength, stdin) != NULL) //Kein Fehler aufgetreten
        {
            if(!strcmp(line,"quit\n")) //User hat quit eingegeben
            {
                return 0;
            }
            allManipulations(line);
            printf("%s\n",line);
        }
    }
}
