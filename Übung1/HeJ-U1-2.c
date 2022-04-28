// Jakob Heigl-Auer, Uebung 1 - Aufgabe 2
// HeJ-U1-1.c

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { //Anlegen einer Struktur mit den passenden Temperatur doubles
    double celsius, fahrenheit, kelvin, rankine;
}temperatures;

temperatures temperatureConversion (int temp, char einheit)
{
    temperatures temperatures;
    switch(einheit)
    {
        case 'c':
        case 'C': //Ist die angegebene Temperaur C berechne restliche Temperaturen
            temperatures.celsius = temp;
            temperatures.fahrenheit = temp * 1.8 + 32;
            temperatures.kelvin = temp + 273.15;
            temperatures.rankine = temp * 1.8 +32 + 459.67;
            break;
        case 'f':
        case 'F': //Ist die angegebene Temperaur F berechne restliche Temperaturen
            temperatures.celsius = (temp - 32) / 1.8;
            temperatures.fahrenheit = temp;
            temperatures.kelvin = (temp + 459.67) / 1.8;
            temperatures.rankine =  temp + 459.67;
            break;
        case 'k':
        case 'K': //Ist die angegebene Temperaur K berechne restliche Temperaturen
            temperatures.celsius = temp - 273.15;
            temperatures.fahrenheit = temp * 1.8 - 459.67;
            temperatures.kelvin = temp;
            temperatures.rankine = temp * 1.8;
            break;
        case 'r':
        case 'R': //Ist die angegebene Temperaur R berechne restliche Temperaturen
            temperatures.celsius = (temp - 32 - 459.67) / 1.8;
            temperatures.fahrenheit = temp - 459.67;
            temperatures.kelvin = temp / 1.8;
            temperatures.rankine =  temp;
            break;
        default:
            printf("\nFehler: Keine passende Einheit angegeben\n");
            exit(1);
    }
    return temperatures;
}

int main()
{
    //Variablen
    int temp;
    char einheit;
    temperatures temperatures;

    printf("Temperatur (Zahl): ");
    scanf("%d",&temp); //Einlesen der Temperatur
    printf("Einheit (C, F, K, R): ");
    scanf(" %c",&einheit); //Einlesen der Einheit, Leerzeichen vor %c wichtig da sonst das Enter vom vorherigen scanf gelesen wird
    temperatures = temperatureConversion(temp, einheit); //Aufruf der Funktion temperatureconversion
    printf("\nDas sind:\n");
    printf("%.2lf Celsius\n", temperatures.celsius);
    printf("%.2lf Kelvin\n", temperatures.kelvin);
    printf("%.2lf Fahrenheit\n", temperatures.fahrenheit);
    printf("%.2lf Rankine\n", temperatures.rankine);
}