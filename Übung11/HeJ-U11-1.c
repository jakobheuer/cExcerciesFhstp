// Jakob Heigl-Auer, Uebung11 - Aufgabe 1
// HeJ-U11-1.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

#define headersize 2048
#define byteDistance 128
#define bitToChange 2

#define CLEAR_BIT(value, pos) (value &= (~(1U<< pos)))

//Deklarationen

FILE * handleFileOpen(int argc, char **argv);

int main(int argc, char *argv[])
{
    FILE *filePointer = handleFileOpen(argc,argv);
    char userInputChar;
    char charFromFile;

    if(filePointer!=NULL)
    {
        fseek(filePointer,headersize,SEEK_SET); //Skip possible header
        printf("Encoding Message [%s] in File [%s]\n",argv[2],argv[1]);
        for (int inputStringPosition = 0; inputStringPosition < strlen(argv[2]); ++inputStringPosition)
        {
            userInputChar = argv[2][inputStringPosition]; //Get single char from input String
                for (int i = 0; i < 8; i++) {
                    charFromFile = fgetc(filePointer); //Get Char from File
                    fseek(filePointer,-1,SEEK_CUR); //Go back one step

                    if((userInputChar & 128 >> i) != 0)
                        charFromFile |= 1 << bitToChange;
                    else
                        charFromFile &= ~(1 << bitToChange);

                    fputc(charFromFile,filePointer); //Change byte
                    fseek(filePointer,-1,SEEK_CUR); //Go back one step
                    fseek(filePointer,byteDistance,SEEK_CUR);
                }
        }
        for (int i = 0; i < 8; i++) { //8x 0 schreiben
            charFromFile = fgetc(filePointer); //Get Char from File
            fseek(filePointer,-1,SEEK_CUR); //Go back one step
            charFromFile &= ~(1 << bitToChange);
            fputc(charFromFile,filePointer); //Change byte
            fseek(filePointer,-1,SEEK_CUR); //Go back one step
            fseek(filePointer,byteDistance,SEEK_CUR);
        }
        fclose(filePointer);
        printf("Encoding successful!\n");
    }

    return 0;
}

FILE * handleFileOpen(int argc, char **argv)
{
    FILE *filePointer;
    struct stat sb;

    if(argc==3)
    {
        if (stat(argv[1], &sb) == -1) {
            perror("Error: ");
            exit(EXIT_FAILURE);
        }

        if(sb.st_size < (headersize + byteDistance*strlen(argv[2]))) //Schauen ob File zu klein für Message
        {
            printf("ERROR: Input File [%s] is to small to convey the message [%s]\n",argv[1],argv[2]);
            printf(" Input File: %ld bytes\n",sb.st_size);
            printf(" Needed for Message: %lu bytes\n",(headersize + (byteDistance*strlen(argv[2]))));
            exit(0);
        }
        else
        {
            filePointer = fopen(argv[1],"r+b"); //r+b = Open for reading and writing, start at beginning, binary
            if(filePointer != NULL) //Wenn File gefönnet werden konnte
                return filePointer;
            else
            {
                printf("FILE ERROR\n");
                exit(0);
            }
        }
    }
    else
    {
        if(argc<3)
            printf("Not enough Arguments\n");
        else
            printf("Too many Arguments\n");
    }
    return NULL;
}