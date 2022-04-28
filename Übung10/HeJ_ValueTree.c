// Heigl-Auer Jakob (Hilfe durch Osanger Philipp)
// Main: HeJ-U10.c

//Includes
#include "HeJ_ValueTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void HeJ_insertTree(t_HeJNode **head, const int number)
{
    if(*head == NULL) //Noch kein Element an dieser Position, erstelle ein neues
    {
        t_HeJNode *newNode = (t_HeJNode *)malloc(sizeof(t_HeJNode)); //Neue Node erstellen
        newNode->number = number;
        newNode->pRightChild = NULL;
        newNode->pLeftChild = NULL;
        *head = newNode; //Head ist erste Node
    }
    else
    {
        if(number >= (*head)->number) //Zahl größer als Node => rechts entlang
            HeJ_insertTree(&(*head)->pRightChild, number); //&(*head)->pRightChild = Adresse des rechten Elements
        else    //Zahl kleiner als Node => Links entlang
            HeJ_insertTree(&(*head)->pLeftChild, number);
    }
}

bool HeJ_getIfHappy(t_HeJNode **head, int number)
{
    int tmp = 0;
    int erg = 0;
    for(; number != 0; number /= 10) //Ausrechnen und Addieren aller Quadrate der Digits
    {
        tmp = number % 10; //Digit finden
        erg += tmp * tmp; //Digit quadrieren und zum erg addieren
    }
    if(erg == 1) //Ergebnis ist 1 => HAPPY
        return true;
    else if(!HeJ_findValue(*head, erg)) //Wenn zahl nicht im Tree gefunden
    {
        HeJ_insertTree(head, erg); //Zahl im Tree einsetzen
        return HeJ_getIfHappy(head, erg); //Erneut funktion Durchlaufen
    }
    return false; //Zahl war schon im Tree obwohl ich sie jetzt erst ausgerechnet habe => Befinden sich in Loop, Zahl UNHAPPY
}

bool HeJ_findValue(t_HeJNode *head, const int number)
{
    if(head == NULL)
        return false;
    if(head->number == number) //Nummer ist in Tree => Gefunden
        return true;
    else if(number > head->number) //Suche im Rechten Teil, falls gefunden true, ansonsten false
        return HeJ_findValue(head->pRightChild, number);
    else //Suche im linken Teil, falls gefunden true, ansonsten false
        return HeJ_findValue(head->pLeftChild, number);
}

void HeJ_freeTree(t_HeJNode *head)
{
    if(head != NULL)
    {
        HeJ_freeTree(head->pLeftChild); //Linken Teil freen
        HeJ_freeTree(head->pRightChild); //Rechten Teil freen
        free(head);
    }
}

void HeJ_printTree(t_HeJNode *head)
{
    if(head == NULL)
        return;
    HeJ_printTree(head->pLeftChild); //Als erstes linker tree
    printf("%d ", head->number); //Beim letzten Element angefangen ausgeben
    HeJ_printTree(head->pRightChild);
}