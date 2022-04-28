// Jakob Heigl-Auer, Uebung 2 - Aufgabe 4
// HeJ-U2-4.c

// Includes
#include <stdio.h>

int main()
{
    //Variablen und Konstanten
    const int NUMBER_OF_MS = 1;
    int targetNumberOfRows, growth;
    int currentRow, numberOfWhitespaces, numberOfHs;
    int targetNumberOfWhitespaces, targetNumberOfHs, maxNumberOfHs;

    printf("Geben Sie \"Höhe/growth\" an: ");
    scanf("%d/%d/",&targetNumberOfRows, &growth);

    maxNumberOfHs=(targetNumberOfRows-1)*growth+1; // Berechnet Anzahl der H's in der untersten Zeile
    for(currentRow = 0; currentRow < targetNumberOfRows; currentRow++) //Itteriert bis targetNumberOfRows erreicht ist
    {
        targetNumberOfHs = growth*currentRow+1; //Wie viele H's sollen in diese Zeile stehen
        targetNumberOfWhitespaces=(maxNumberOfHs-targetNumberOfHs)/2; //Wie viele leerzeichen braucht diese Zeile

        for(numberOfWhitespaces = 0; numberOfWhitespaces<targetNumberOfWhitespaces; numberOfWhitespaces++)
        {
            printf(" ");
        }
        for(numberOfHs = 0; numberOfHs < targetNumberOfHs; numberOfHs++)
        {
            printf("H");
        }
        printf("\n");
    }

    targetNumberOfWhitespaces=(maxNumberOfHs-NUMBER_OF_MS)/2;
    for(numberOfWhitespaces=0; numberOfWhitespaces<targetNumberOfWhitespaces; numberOfWhitespaces++)
    {
        printf(" ");
    }
    printf("M");

    return 0;
}