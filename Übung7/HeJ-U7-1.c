// Jakob Heigl-Auer, Uebung 7 - Aufgabe 1
// HeJ-U7-1.c

// Includes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //Sleep
#include <termios.h>

#define gameFieldSize 8
#define definedObstacleAmount 5
#define moveGain 5
#define movesAtStart 40
#define moveCost 2
//#define gameDesign 2 //0 = Standard, 1=Flags, 2=Taxi

//Deklarationen
struct HeJ_robot{
    int x;
    int y;
    int direction; //0=Up,1=Right,2=Down,3=Left
};

struct GameState{
    int lvl;
    int points;
    int remainingMoves;
    int remainingObstacles;
    int gameDesign;
    bool lost;
};

void HeJ_CreateObstacles(bool HeJ_GameField[gameFieldSize][gameFieldSize],int obstacleAmount, struct HeJ_robot robot,struct GameState * currentGameState);
void HeJ_PrintGame(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot,struct GameState * currentGameState);
struct HeJ_robot HeJ_MoveOneStep(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot,struct GameState * currentGameState);
void initializeGame(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot * robot,struct GameState * currentGameState);
bool checkForObstacle(bool HeJ_GameField[gameFieldSize][gameFieldSize], int newRobotPositionX, int newRobotPositionY);
char getch(void);
struct HeJ_robot getDirectionFromInput(struct HeJ_robot robot);
int highscoreCheck(struct GameState * currentGameState);

int main(void)
{
    srand(time(NULL));
    //Variablen
    bool HeJ_GameField[gameFieldSize][gameFieldSize];
    struct HeJ_robot robot;
    struct GameState currentGameState;

    initializeGame(HeJ_GameField,&robot,&currentGameState);
    for(;;)
    {
        HeJ_PrintGame(HeJ_GameField,robot,&currentGameState);
        robot = getDirectionFromInput(robot);
        robot = HeJ_MoveOneStep(HeJ_GameField,robot,&currentGameState);
    }

    return 0;
}

char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%d\n", buf);
    return buf;
}

struct HeJ_robot getDirectionFromInput(struct HeJ_robot robot)
{
    char keyPress;
    keyPress = getch();
    switch (keyPress) {
        case 119: //Rauf
            robot.direction = 0;
            //printf("Rauf\n");
            break;
        case 100:
            robot.direction = 1;
            //printf("Rechts\n");
            break;
        case 115:
            robot.direction = 2;
            //printf("Runter\n");
            break;
        case 97:
            robot.direction = 3;
            //printf("Links\n");
            break;
    }
    return robot;
}

void initializeGame(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot * robot,struct GameState * currentGameState)
{
    int gameDesign=0;
    printf("Welchen Skin wollen Sie benutzen?\n");
    printf("1. Standard\n");
    printf("2. Capture the Flag\n");
    printf("3. Bus Simulator\nAuswahl: ");
    scanf("%d",&gameDesign);
    //Robot initialize
    robot->x = gameFieldSize/2;
    robot->y = gameFieldSize/2;
    robot->direction = 0;

    //Game state initialize
    currentGameState->lvl=1;
    currentGameState->points=0;
    currentGameState->remainingMoves=movesAtStart;
    currentGameState->lost = 0;
    if(gameDesign>=1 && gameDesign <= 3)
        currentGameState->gameDesign = gameDesign-1;
    else
    currentGameState->gameDesign = 0;

    for (int i = 0; i < gameFieldSize; ++i) {
        for (int j = 0; j < gameFieldSize; ++j) {
            HeJ_GameField[i][j]=0; //Initialisieren array
        }
    }

    HeJ_CreateObstacles(HeJ_GameField,definedObstacleAmount,*robot,currentGameState); //Obstacles generieren
}

void HeJ_CreateObstacles(bool HeJ_GameField[gameFieldSize][gameFieldSize],int obstacleAmount, struct HeJ_robot robot,struct GameState * currentGameState)
{
    int randomXCoordinate,randomYCoordinate;

    for (int i = 0; i < obstacleAmount; ++i) {
        randomXCoordinate = rand()%gameFieldSize;
        randomYCoordinate = rand()%gameFieldSize;
        if((HeJ_GameField[randomYCoordinate][randomXCoordinate] == 0) && ((robot.x != randomXCoordinate) || (robot.y != randomYCoordinate))) //Wenn Feld noch nicht besetzt dann besetzen
        {
            HeJ_GameField[randomYCoordinate][randomXCoordinate] = 1;
            currentGameState->remainingObstacles += 1;
        }
        else //Feld war schon besetzt, erneut probieren
            --i;
    }
}

void HeJ_PrintGame(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot, struct GameState * currentGameState)
{
    int iteratorX;
    int iteratorY;
    int highscore = 0;

    system("clear");
    if(currentGameState->lost) //Spiel verloren
    {
        highscore= highscoreCheck(currentGameState);
        if(highscore<currentGameState->points) //NEW HIGSCORE
        {
            printf("   ┌────────────────────────────────┐\n");
            printf("   │            GAME OVER           │\n");
            printf("   ├────────────────────────────────┤\n");
            printf("   │          Level: %.3d            │\n",currentGameState->lvl);
            printf("   │          Score: %.3d            │\n",currentGameState->points);
            printf("   │   YOU HAVE THE NEW HIGHSCORE!  │\n");
            printf("   │      Old Highscore: %.3d        │\n",highscore);
            printf("   └────────────────────────────────┘\n");
        }
        else
        {
            printf("   ┌────────────────────────────────┐\n");
            printf("   │            GAME OVER           │\n");
            printf("   ├────────────────────────────────┤\n");
            printf("   │          Level: %.3d            │\n",currentGameState->lvl);
            printf("   │          Score: %.3d            │\n",currentGameState->points);
            printf("   │          Highscore: %.3d        │\n",highscore);
            printf("   └────────────────────────────────┘\n");
        }
    }
    else
    {
        printf("┌────────────┬───────────────┬───────────────────────┐\n");
        printf("│  Level %.3d │   Points %.3d  │   Remaining Moves %.3d │\n",currentGameState->lvl,currentGameState->points,currentGameState->remainingMoves);
        printf("└────────────┴───────────────┴───────────────────────┘\n\n");
        printf("  ┌");
        for (int boarder = 0; boarder < gameFieldSize*2; ++boarder) {
            printf("─");
        }
        printf("┐\n");
        for (iteratorY = 0; iteratorY < gameFieldSize; ++iteratorY) {
            printf("  │");
            for (iteratorX = 0; iteratorX < gameFieldSize; ++iteratorX) {
                if(currentGameState->gameDesign==0)
                {
                    if(robot.x == iteratorX && robot.y == iteratorY)
                    {
                        printf("O ");
                    }
                    else
                    {
                        if(HeJ_GameField[iteratorY][iteratorX] == 0)
                            printf("- ");
                        else
                            printf("# ");
                    }
                }
                else if(currentGameState->gameDesign==1)
                {
                    if(robot.x == iteratorX && robot.y == iteratorY)
                    {
                        if(robot.direction==0)
                            printf("↑ ");
                        else if(robot.direction==1)
                            printf("→ ");
                        else if(robot.direction==2)
                            printf("↓ ");
                        else if(robot.direction==3)
                            printf("← ");
                    }//printf("O ");
                    else
                    {
                        if(HeJ_GameField[iteratorY][iteratorX] == 0)
                            printf("· ");
                        else
                            printf("\U0001F6A9");
                    }
                }
                else if(currentGameState->gameDesign==2) //Taxi
                {
                    if(robot.x == iteratorX && robot.y == iteratorY)
                    {
                        printf("\U0001F68C"); //BUS
                    }
                    else
                    {
                        if(HeJ_GameField[iteratorY][iteratorX] == 0)
                            printf("· ");
                        else
                            printf("\U0001F64B"); //Person
                    }
                }
            }
            printf("│\n");
        }
        printf("  └");
        for (int boarder = 0; boarder < gameFieldSize*2; ++boarder) {
            printf("─");
        }
        printf("┘\n");
    }
}

struct HeJ_robot HeJ_MoveOneStep(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot, struct GameState * currentGameState)
{
    int newRobotPositionX=0;
    int newRobotPositionY=0;
    int newRobotDirection=robot.direction;
    bool obstacleHit=0;

    if(robot.direction==0) //Roboter Zeigt nach oben
    {
        newRobotPositionX=robot.x;      //X Unverändert
        newRobotPositionY=robot.y - 1;  //Y-1 => 1 schritt nach oben
        if(newRobotPositionY<0) //Roboter steht zu weit oben, bewegung nach ganz unten
            newRobotPositionY=gameFieldSize-1;
    }
    else if(robot.direction==1) //Roboter zeigt nach rechts
    {
        newRobotPositionX=robot.x + 1; //X+1 => 1 schritt nach rechts
        newRobotPositionY=robot.y;
        if(newRobotPositionX>=gameFieldSize) //Roboter zu weit rechts, bewegung nach ganz links
            newRobotPositionX=0;
    }
    else if(robot.direction==2) //Roboter zeigt nach unten
    {
        newRobotPositionX=robot.x;
        newRobotPositionY=robot.y + 1;
        if(newRobotPositionY>=gameFieldSize) //Falls unterhalb des Felds
            newRobotPositionY = 0;  //Roboter nach ganz oben gesetzt
    }
    else if(robot.direction==3) //Roboter Bewegung nach links
    {
        newRobotPositionX=robot.x - 1;
        newRobotPositionY=robot.y;
        if(newRobotPositionX<0)
            newRobotPositionX=gameFieldSize-1;
    }

    obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
    currentGameState->remainingMoves = currentGameState->remainingMoves - (moveCost * (currentGameState->lvl / 2)+1); //Berechnung was ein move kostet und dann abziehen

    if(obstacleHit)
    {
        HeJ_GameField[newRobotPositionY][newRobotPositionX] = 0; //Hindernis entfernen
        currentGameState->points = currentGameState->points + 1; //Punktestand erhöhen
        currentGameState->remainingMoves = currentGameState->remainingMoves + moveGain; //Verbleibende Moves erhöhen
        currentGameState->remainingObstacles -= 1; //Obstacle Anzahl reduzieren
    }

    robot.x=newRobotPositionX;
    robot.y=newRobotPositionY;
    robot.direction=newRobotDirection;

    if(currentGameState->remainingMoves<=0) //Check if GameOver
    {
        currentGameState->lost = 1;
        HeJ_PrintGame(HeJ_GameField,robot,currentGameState);
        exit(0);
    }
    if(currentGameState->remainingObstacles<=0) //Check if new obstacles are needed
    {
        HeJ_CreateObstacles(HeJ_GameField,definedObstacleAmount,robot,currentGameState);
        currentGameState->remainingMoves += 20;
        currentGameState->lvl += 1;
    }

    return robot;
}

bool checkForObstacle(bool HeJ_GameField[gameFieldSize][gameFieldSize], int newRobotPositionX, int newRobotPositionY) // Überprüfe ob bei Koordinate ein Obstacle ist
{
    return HeJ_GameField[newRobotPositionY][newRobotPositionX]==1 ? 1 : 0;
}

int highscoreCheck(struct GameState *currentGameState) {
    FILE *fptr;
    bool fileError = 0;
    int highscore = 0;

    system("clear");
    fptr = fopen("scores.txt", "r+");
    if (fptr == NULL) //if file does not exist, create it
    {
        fptr = fopen("scores.txt", "w+");
        if (fptr == NULL) {
            printf("FILE ERROR\n");
            fileError = 1;
        }
    }
    if (fileError == 0) //File offen
    {
        fscanf(fptr, "%d", &highscore);
        if (highscore < currentGameState->points) //Neuer Highscore
        {
            fptr = freopen(NULL, "w", fptr);
            fprintf(fptr, "%d", currentGameState->points); //Neuen Highscore speichern
        }
    }
    fclose(fptr);
    return highscore;
}