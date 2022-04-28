// Jakob Heigl-Auer, Uebung 4 - Aufgabe 2
// HeJ-U4-2.c

// Includes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char * HeJstrcichr (const char *pointerString, char searchedCharacter);
const char * HeJstrrcichr (const char *pointerString, char searchedCharacter);
const char * HeJstrcipbrk (const char *pointerString, const char *searchedCharacters);

int main(void)
{
    char line[50];
    char searchedCharacters[50];
    //char *pointerAtCharacter = NULL;
    char searchedCharacter;
    for (;;)
    {
        printf("Geben Sie einen String ein: ");
        if (fgets(line, 50, stdin) != NULL) //Kein Fehler aufgetreten
        {
            if(!strcmp(line,"quit\n")) //User hat quit eingegeben
            {
                return 0;
            }
            printf("\nGeben Sie den/die Buchstaben ein: ");
            if (fgets(searchedCharacters, 50, stdin) != NULL) //Kein Fehler aufgetreten
            {
                if(strlen(searchedCharacters)==2) //Nur 1 Buchstabe
                {
                    searchedCharacter = *searchedCharacters;
                    const char *strcichrPointer = HeJstrcichr(line,searchedCharacter);
                    if(strcichrPointer==NULL)
                        printf("%c nicht im String enthalten\n",searchedCharacter);
                    else
                        printf("\nHeJstrcichr:\n Eingabe: %s Gesuchter,Buchstabe: %c \n Pointer: %p \n Zeigt auf: %c \n String ab Buchstabe: %s\n",line,searchedCharacter,&strcichrPointer,*strcichrPointer,strcichrPointer);

                    const char *strrcichrPointer = HeJstrrcichr(line, searchedCharacter);
                    if(strcichrPointer==NULL)
                        printf("%c nicht im String enthalten\n",searchedCharacter);
                    else
                        printf("\nHeJstrrcichr:\n Eingabe: %s Gesuchter Buchstabe: %c \n Pointer: %p \n Zeigt auf: %c \n String ab Buchstabe: %s\n",line,searchedCharacter,&strrcichrPointer,*strrcichrPointer,strrcichrPointer);
                }
                else
                {
                    const char *strcipbrkPointer = HeJstrcipbrk(line, searchedCharacters);
                    if(strcipbrkPointer==NULL)
                        printf("%s nicht im String enthalten\n",searchedCharacters);
                    else
                        printf("\nHeJstrcipbrk:\n Eingabe: %s Gesuchter Buchstabe: %c \n Pointer: %p \n Zeigt auf: %c \n String ab Buchstabe: %s\n",line,searchedCharacter,&strcipbrkPointer,*strcipbrkPointer,strcipbrkPointer);
                }
            }
        }
        else
            return 0;
    }
}

const char * HeJstrcichr (const char *pointerString, char searchedCharacter)
{
    while (*pointerString!='\0')
    {
        if(tolower(*pointerString)==tolower(searchedCharacter))
        {
            return (char *)pointerString;
        }
        ++pointerString; //Nächstes Element
    }
    return NULL;
}


const char * HeJstrrcichr (const char *pointerString, char searchedCharacter)
{
    int stringPosition;
    int stringLength=0;
    while(*pointerString != '\0') //Rutsche Pointer bis zum Ende des strings
    {
        ++pointerString;
        ++stringLength; //Zähle Länge des Inputs
    }
    if(searchedCharacter == '\0')
        return (char *)pointerString;

    pointerString = pointerString - 2;//Nun ist der Pointer am letzten vom Benutzer eingegebenen Zeichen
    --stringLength; //\0 ignorieren

    for(stringPosition=0;stringPosition<stringLength;stringPosition++) //Geh string von Hinten bis Vorne durch
    {
        if(tolower(*pointerString)==tolower(searchedCharacter))
        {
            return (char *)pointerString;
        }
        --pointerString; //Vorheriges Element
    }
    return NULL; //Not found
}

const char * HeJstrcipbrk (const char *pointerString, const char *searchedCharacters)
{
    int stringLenght = strlen(searchedCharacters) - 1;
    int stringPosition = 0;
    const char * startPointerSearchedCharacters = searchedCharacters;
    printf("Strlen: %d\n",stringLenght);

    while(*pointerString != '\0') //Rutsche Pointer bis zum Ende des strings
    {
        for(stringPosition = 0; stringPosition < stringLenght; stringPosition++)
        {
            if(tolower(*pointerString)==tolower(*searchedCharacters))
            {
                return (char *)pointerString;
            }
            ++searchedCharacters;
        }
        searchedCharacters = startPointerSearchedCharacters;
        ++pointerString;
    }
    return NULL;
}