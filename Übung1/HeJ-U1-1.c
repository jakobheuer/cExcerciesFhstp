// Jakob Heigl-Auer, Uebung 1 - Aufgabe 1
// HeJ-U1-1.c

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	//Variablen
	float euro;
	float schilling;
	int einheit;
	printf("Eurobetrag: ");
	; //Einlesen der Eingabe des Benutzer
	if(scanf("%f",&euro)) //Überprüft ob Eingabe %f entspricht
	{
		if(euro < 0) //Überprüft ob User keine negative Zahl eingegeben hat
		{
			euro = euro * -1; //Zahl invertieren
			printf("Fehler: Betrag war kleiner als 0, Wurde geändert zu %.2f€ \n",euro);
		}
		schilling = euro * 13.76; //Umrechnung zu Schilling
		printf("%.1f Euro entspricht ca. %.1f Schilling\n",euro,schilling); //Ausgabe
		euro = round(euro); //Euro runden
		printf("In Geldscheinen und Münzen: ");

		einheit = euro / 200; //Anzahl der 200 berechnen
		if (einheit >= 1) //Falls 200 mehr als 1x vorkommt ausgeben
		{
			printf("%d Schein(e) mit Wert 200", einheit);
			euro = euro - einheit * 200; //Restgeld berechnen
		}

		einheit = euro / 100; //Anzahl der 100 berechnen
		if (einheit >= 1) //Falls 100 mehr als 1x vorkommt ausgeben
		{
			printf(", %d Schein(e) mit Wert 100", einheit);
			euro = euro - einheit * 100; //Restgeld berechnen
		}

		einheit = euro / 50; // ---- || ----
		if (einheit >= 1)
		{
			printf(", %d Schein(e) mit Wert 50", einheit);
			euro = euro - einheit * 50;
		}

		einheit = euro / 20; // ---- || ----
		if (einheit >= 1)
		{
			printf(", %d Schein(e) mit Wert 20", einheit);
			euro = euro - einheit * 20;
		}

		einheit = euro / 10; // ---- || ----
		if (einheit >= 1)
		{
			printf(", %d Schein(e) mit Wert 10", einheit);
			euro = euro - einheit * 10;
		}

		einheit = euro / 5; // ---- || ----
		if (einheit >= 1)
		{
			printf(", %d Schein(e) mit Wert 5", einheit);
			euro = euro - einheit * 5;
		}

		einheit = euro / 2; // ---- || ----
		if (einheit >= 1)
		{
			printf(", %d Münze(n) mit Wert 2", einheit);
			euro = euro - einheit * 2;
		}

		einheit = euro / 1; // ---- || ----
		if (einheit >= 1)
		{
			printf(", %d Münze(n) mit Wert 1", einheit);
			euro = euro - einheit * 1;
		}

		printf("\n");
	}
	else
		printf("\nFehler: Eingabe war kein Integer\n");

	return 0;
}