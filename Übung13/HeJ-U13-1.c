// Jakob Heigl-Auer, Uebung13 - Aufgabe 1
// HeJ-U13-1.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

//Deklarationen
void charToArray(bool *bitArray[8]);

int main(int argc, char *argv[])
{
    FILE *filePointer=NULL;
    FILE *filePointer2=NULL;
    char line[1000];
    char symbol;
    int countSameBits=0;
    bool firstTime=1;
    bool bitIs1=0;
    bool bit;

    if(argc==1) //Stdin to stdout
    {
        scanf("%s",line); //TODO: FGETS
        for (int i = 0; i < (strlen(line)-1); ++i) {
            symbol = line[i];
            for (int j = 0; j < 8; ++j) {
                bit = symbol & 1; //get single bit
                if(firstTime) //Init if first bit
                {
                    bitIs1 = (bit == 1) ? 1 : 0;
                    ++countSameBits;
                    firstTime=0;
                }
                else
                {
                    if(bit == bitIs1) //Check if bit is same
                        ++countSameBits; //increase count
                    else //Bit changed
                    {
                        //Ouput the bit change
                        if(bitIs1)
                            printf("0 ");
                        else
                            printf("00 ");
                        for (int k = 0; k < countSameBits; ++k) {
                            printf("0");
                        }
                        printf("|");

                        bitIs1 = bit; //Changed
                        countSameBits=1;
                    }
                }
                symbol >>= 1;
            }
        }
    }
    else if(argc==2) //File to stdout
    {
        filePointer = fopen(argv[1],"r");
        while(fgets(line, 1000, filePointer)) { //TODO: FGETC schleife
            for (int i = 0; i < strlen(line); ++i) {
                symbol = line[i];
                for (int j = 0; j < 8; ++j) {
                    bit = symbol & 1; //get single bit
                    if(firstTime) //Init if first bit
                    {
                        bitIs1 = (bit == 1) ? 1 : 0;
                        ++countSameBits;
                        firstTime=0;
                    }
                    else
                    {
                        if(bit == bitIs1) //Check if bit is same
                            ++countSameBits; //increase count
                        else //Bit changed
                        {
                            //Ouput the bit change
                            if(bitIs1)
                                printf("0 ");
                            else
                                printf("00 ");
                            for (int k = 0; k < countSameBits; ++k) {
                                printf("0");
                            }
                            printf("|");

                            bitIs1 = bit; //Changed
                            countSameBits=1;
                        }
                    }
                    symbol >>= 1;
                }
            }
        }
        fclose(filePointer);

        /* Prints bit for debug
         * filePointer = fopen(argv[1],"r");
        while(fgets(line, 1000, filePointer)) {
            for (int i = 0; i < strlen(line); ++i) {
                symbol = line[i];
                for (int j = 0; j < 8; ++j) {
                    bit = symbol & 1; //get single bit
                    printf("%d",bit);
                    symbol >>= 1;
                }
                printf(" ");
            }
        }
        fclose(filePointer);*/
    }
    else if(argc==3) //File to file
    {
        filePointer = fopen(argv[1],"r");
        filePointer2 = fopen(argv[2],"w");
        if(filePointer != NULL && filePointer2 != NULL) //Both files could be opened
        {
            while(fgets(line, 1000, filePointer)) {
                for (int i = 0; i < strlen(line); ++i) {
                    symbol = line[i];
                    for (int j = 0; j < 8; ++j) {
                        bit = symbol & 1; //get single bit
                        if(firstTime) //Init if first bit
                        {
                            bitIs1 = (bit == 1) ? 1 : 0;
                            ++countSameBits;
                            firstTime=0;
                        }
                        else
                        {
                            if(bit == bitIs1) //Check if bit is same
                                ++countSameBits; //increase count
                            else //Bit changed
                            {
                                //Ouput the bit change
                                if(bitIs1)
                                    fprintf(filePointer2,"%s","0 ");
                                else
                                    fprintf(filePointer2,"%s","00 ");
                                for (int k = 0; k < countSameBits; ++k) {
                                    fprintf(filePointer2,"%s","0");
                                }
                                fprintf(filePointer2,"%s","|");

                                bitIs1 = bit; //Changed
                                countSameBits=1;
                            }
                        }
                        symbol >>= 1;
                    }
                }
            }
            fclose(filePointer);
            fclose(filePointer2);
        }
    }
    return 0;
}