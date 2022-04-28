// Jakob Heigl-Auer, Uebung 8 - Aufgabe 1
// HeJ-U8-1.c

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define gameFieldSize 10

//Deklarationen
typedef struct st_Hecandle{
    short x,y;
    short L;
}t_Hecandle;

static t_Hecandle *HeCheckParams(int argc, char **argv,t_Hecandle *candles, int *candleCount);
static void HeIlluminate(t_Hecandle *candles, int candleCount, short HeGameField[gameFieldSize][gameFieldSize]);
static void HePrintGameField(short HeGameField[gameFieldSize][gameFieldSize]);
static void HePrintDarkFields(short HeGameField[gameFieldSize][gameFieldSize]);
static short toShort(char c);

int main(int argc, char *argv[])
{
    int candleCount = 0;
    t_Hecandle * candles = calloc(1,sizeof(t_Hecandle));
    //t_Hecandle * candles = NULL;
    static short HeGameField[gameFieldSize][gameFieldSize];

    candles = HeCheckParams(argc,argv,candles,&candleCount);
    HeIlluminate(candles,candleCount,HeGameField);
    HePrintGameField(HeGameField);
    HePrintDarkFields(HeGameField);
    free(candles);
    return 0;
}

static t_Hecandle *HeCheckParams(int argc, char **argv, t_Hecandle *candles, int *candleCount)
{
    t_Hecandle *save = candles;

    if(argc>1)
    {
        for (int i = 1; i < argc; ++i)
        {
            *candleCount = *candleCount + 1;
            if(strlen(argv[i])==7 && argv[i][0] == '-' && argv[i][3] == ',' && argv[i][5] == ':')
            {
                candles = realloc(save, i*sizeof(t_Hecandle)); //Array erweitern, Speicher holen
                candles[i-1].x = toShort(argv[i][2]);
                candles[i-1].y = toShort(argv[i][4]);
                candles[i-1].L = toShort(argv[i][6]);
            }
        }
    }

    return save;
}

static short toShort(char c)
{
    return c - '0';
}

static void HeIlluminate(t_Hecandle *candles, int candleCount, short HeGameField[gameFieldSize][gameFieldSize])
{
    int iteratorX;
    int iteratorY;
    int distanceX=0;
    int distanceY=0;
    int largestDistanceToCandle=0;
    int highestIllumination=0;

    for(iteratorY = 0; iteratorY < gameFieldSize; iteratorY++)
    {
        for(iteratorX = 0; iteratorX <gameFieldSize; iteratorX++)
        {
            for (int i = 0; i < candleCount; ++i) {
                distanceX=abs(candles[i].x - iteratorX);
                distanceY=abs(candles[i].y - iteratorY);
                largestDistanceToCandle = distanceX<distanceY ? distanceY : distanceX;
                if(i==0)
                    highestIllumination = candles[i].L - largestDistanceToCandle; //Erster Durchgang, Basiswert festgelegt
                else
                    highestIllumination = (highestIllumination < (candles[i].L - largestDistanceToCandle)) ? (candles[i].L - largestDistanceToCandle) : highestIllumination; //Neue Highest illumination?
            }
            HeGameField[iteratorX][iteratorY] = highestIllumination>0 ? highestIllumination : 0;
        }
    }
}
static void HePrintGameField(short HeGameField[gameFieldSize][gameFieldSize])
{
    printf("\n");
    for (int i = 0; i < gameFieldSize; ++i) {
        for (int j = 0; j < gameFieldSize; ++j) {
            printf("%d ", HeGameField[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

static void HePrintDarkFields(short HeGameField[gameFieldSize][gameFieldSize])
{
    int iteratorX;
    int iteratorY;

    for(iteratorY = 0; iteratorY < gameFieldSize; iteratorY++)
    {
        for(iteratorX = 0; iteratorX <gameFieldSize; iteratorX++)
        {
            if(HeGameField[iteratorY][iteratorX]==0)
                printf("(%d,%d) is dark\n",iteratorX,iteratorY);
        }
    }
}