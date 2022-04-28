// Jakob Heigl-Auer, Uebung11 - Aufgabe 2
// HeJ-U11-2.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

#define headersize 2048
#define byteDistance 128
#define bitToChange 2

//Deklarationen

FILE * handleFileOpen(int argc, char **argv);

int main(int argc, char *argv[])
{
    FILE *filePointer = handleFileOpen(argc,argv);
    char singlebyte;
    char hiddenUserinput=0;
    bool bit=0;

    if(filePointer!=NULL)
    {
        fseek(filePointer,headersize,SEEK_SET); //Skip possible header
        printf("Retrieving Encoded Message\nMessage: [");
        for(;;)
        {
            for( int j = 0; j <=7; j++ ) { //Char to bit
                singlebyte = fgetc(filePointer); //Get byte

                bit=(singlebyte & 1 << bitToChange)?1:0;
                if(bit==1)
                    hiddenUserinput |= (1 << (7-j));
                else
                    hiddenUserinput &= ~(1 << (7-j));

                fseek(filePointer,-1,SEEK_CUR); //Go back one step
                fseek(filePointer,byteDistance,SEEK_CUR); //-1 weil fputc den pointer nach vorne setzt
            }
            if(hiddenUserinput==0)
                break;
            printf("%c",hiddenUserinput);
        }
        printf("]\n");
        fclose(filePointer);
    }

    return 0;
}

FILE * handleFileOpen(int argc, char **argv)
{
    FILE *filePointer;
    struct stat sb;

    if(argc==2)
    {
        if (stat(argv[1], &sb) == -1) {
            perror("Error: ");
            exit(EXIT_FAILURE);
        }

        if(sb.st_size < headersize) //Schauen ob File zu klein für Message
        {
            printf("ERROR: Input File [%s] is to small for even 1 bit\n",argv[1]);
            printf(" Input File: %lld bytes\n",sb.st_size);
            printf(" Needed for 1 bit: %d bytes\n", headersize+1);
            exit(0);
        }
        else //Kann nachricht enthalten
        {
            filePointer = fopen(argv[1],"rb"); //r+b = Open for reading, start at beginning, binary
            if(filePointer != NULL) //Wenn File gefönnet werden konnte
            {
                printf("File [%s] opened\n",argv[1]);
                return filePointer;
            }
            else
            {
                printf("FILE ERROR\n");
                exit(0);
            }
        }
    }
    else
    {
        if(argc<2)
            printf("Not enough Arguments\n");
        else
            printf("Too many Arguments\n");
    }
    return NULL;
}