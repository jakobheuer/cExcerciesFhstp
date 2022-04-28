// Jakob Heigl-Auer, Uebung11 - Aufgabe 1
// HeJ-U11-1.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>
//Deklarationen

FILE * handleFileOpen(char *argv, int *fileSize);
void printDifferences(bool bit1Array[8], bool bit2Array[8],char **argv, int shortestFileName, int file1NameLength, int file2NameLength, int iterator);

int main(int argc, char *argv[]) {
    int file1size = 0;
    int file2size = 0;
    char charFromFile1 = 0;
    char charFromFile2 = 0;
    int found=0;
    bool bit1Array[8];
    bool bit2Array[8];
    FILE *filePointer = handleFileOpen(argv[1], &file1size);
    FILE *filePointer2 = handleFileOpen(argv[2], &file2size);
    int file1NameLength = strlen(argv[1]);
    int file2NameLength = strlen(argv[2]);
    int shortestFileName = strlen(argv[1]) < strlen(argv[2]) ? strlen(argv[1]) : strlen(argv[2]);
    double time_spent = 0.0;
    clock_t begin = clock();

    if (filePointer != NULL && filePointer2 != NULL) {
        if (file1size == file2size) //Filesize ist gleich
        {
            printf("Filesizes match! [%d] Bytes \nDifferences:\n",file1size);
            for (int iterator = 1; iterator <= file1size; ++iterator) //Byteweise durchgehen
            {
                charFromFile1 = fgetc(filePointer); //Get Char from File
                charFromFile2 = fgetc(filePointer2); //Get Char from File
                if (charFromFile1 != charFromFile2) { //Wenn chars unterschiedlich
                    found++;
                    for (int inputCharBitPosition = 7; inputCharBitPosition >= 0; inputCharBitPosition--) //Char to bit
                    {
                        bit1Array[inputCharBitPosition] = (charFromFile1 >> inputCharBitPosition) & 1 ? 1 : 0; //Get single bit
                        bit2Array[inputCharBitPosition] = (charFromFile2 >> inputCharBitPosition) & 1 ? 1 : 0; //Get single bit
                    }
                    printDifferences(bit1Array,bit2Array,argv,shortestFileName,file1NameLength,file2NameLength, iterator);
                }
            }
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            printf("\n┌─────────────────────────────────────┐\n│ Process finished in %.5f seconds │\n│     %.6d different Bytes found    │\n└─────────────────────────────────────┘\n",time_spent,found);
            fclose(filePointer);
            fclose(filePointer2);
        } else
            printf("File Error\n");
        return 0;
    }
}

FILE *handleFileOpen(char *argv, int *fileSize)
{
    FILE *filePointer;
    struct stat sb;
    printf("%s \n",argv);
    if (stat(argv, &sb) == -1) {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }
    *fileSize = sb.st_size;
    filePointer = fopen(argv, "r+b"); //r+b = Open for reading and writing, start at beginning, binary
    if (filePointer != NULL) //Wenn File gefönnet werden konnte
        return filePointer;
    else
    {
        printf("FILE ERROR\n");
        return NULL;
    }
}

void printDifferences(bool bit1Array[8], bool bit2Array[8],char **argv, int shortestFileName, int file1NameLength, int file2NameLength, int iterator)
{
    printf("\n───────────────────────────────────────┐\nDifference at Byte %d\n", iterator);
    printf("%s: ",argv[1]);
    /*for (int i = 0; i < (file2NameLength-shortestFileName); ++i) {
        printf(" ");
    }*/
    printf("%*c\b",(file2NameLength-shortestFileName)+1,' ');
    for (int inputCharBitPosition = 7; inputCharBitPosition >= 0; inputCharBitPosition--) //Char to bit
    {
        if(bit1Array[inputCharBitPosition]!=bit2Array[inputCharBitPosition])
            printf("|%d|",bit1Array[inputCharBitPosition]);
        else
            printf("%d",bit1Array[inputCharBitPosition]);
    }
    printf("\n%s: ",argv[2]);
    /*for (int i = 0; i < (file1NameLength-shortestFileName); ++i) {
        printf(" ");
    }*/
    printf("%*c\b",(file1NameLength-shortestFileName)+1,' ');
    for (int inputCharBitPosition = 7; inputCharBitPosition >= 0; inputCharBitPosition--) //Char to bit
    {
        if(bit1Array[inputCharBitPosition]!=bit2Array[inputCharBitPosition])
            printf("|%d|",bit2Array[inputCharBitPosition]);
        else
            printf("%d",bit2Array[inputCharBitPosition]);

    }
    printf("\n");
}