// Jakob Heigl-Auer, Uebung 5 - Aufgabe 2
// HeJ-U5-2.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#define maxLineLength 500
#define maxLineCount 1000

//Deklarationen

void readInput(char **inputArray, int * lineCount);
void readFiles(char **inputArray, int * lineCount, int argc, char **argv, bool sortDescending);
void printIt(char **inputArray, int lineCount, bool sortDescending);
int compareStringsAscending(const void *str1, const void *str2);
int compareStringsDescending(const void *str1, const void *str2);

int main(int argc, char *argv[])
{
    //Variablen
    bool sortDescending=(argc>=2 && (strcmp(argv[1],"-d")==0))? 1: 0;; //0 = Sort ascending, 1= Sort descending
    int lineCount = 0;
    char * userInputArray[1000];

    if((sortDescending==1 && argc>2) || (sortDescending==0 && argc > 1)) //Es wurden Dateien angegeben
    {
        readFiles(userInputArray,&lineCount,argc,argv,sortDescending);
        printIt(userInputArray,lineCount,sortDescending);
    }
    else //Userabfrage, keine Dateien
    {
        printf("Eingabe:\n");
        readInput(userInputArray,&lineCount);
        printIt(userInputArray,lineCount,sortDescending);
    }

    for (int i = 0; i < lineCount; ++i) {
        free(userInputArray[i]);
    }

    return 0;
}

void readInput(char **inputArray, int * lineCount)
{
    char inputString[maxLineLength];

    while(fgets(inputString,maxLineLength,stdin)) //fgets returniert NULL bei EOF, bis EOF Lesen
    {
        inputArray[*lineCount] = (char *)strdup(inputString);
        *lineCount += 1;
        if(*lineCount==maxLineCount)
            return;
    }
}

void readFiles(char **inputArray, int * lineCount, int argc, char **argv, bool sortDescending)
{
    FILE *filePointer;
    int iterator;
    char inputString[maxLineLength];
    for (iterator=sortDescending?2:1; iterator < argc; ++iterator) //Vom ersten file bis zum letzten alle durchgehen
    {
        if( access( argv[iterator], F_OK ) == 0 ) { //File ist lesbar
            filePointer = fopen(argv[iterator],"r"); //File im Lesemodus öffnen

            while(fgets(inputString,maxLineLength,filePointer))
            {
                inputArray[*lineCount] = (char *)strdup(inputString);
                *lineCount += 1;
                if(*lineCount==maxLineCount)
                {
                    fclose(filePointer);
                    return;
                }
            }
            fclose(filePointer);
        }
    }
}

void printIt(char **inputArray, int lineCount, bool sortDescending)
{
    sortDescending ? qsort(inputArray,lineCount,sizeof(*inputArray),compareStringsDescending) : qsort(inputArray,lineCount,sizeof(*inputArray),compareStringsAscending); //Absteigend oder Aufsteigend sortieren
    printf("%d Zeilen Sortiert: \n",lineCount);
    for (int i = 0; i < lineCount; ++i) {
        printf("%s\n",inputArray[i]);
    }
}

int compareStringsAscending(const void *str1, const void *str2)
{
    char *const *pp1 = str1;
    char *const *pp2 = str2;

    return strcmp(*pp1,*pp2);
}

int compareStringsDescending(const void *str1, const void *str2)
{
    char *const *pp1 = str1;
    char *const *pp2 = str2;

    return (strcmp(*pp1,*pp2) * (-1));
}
