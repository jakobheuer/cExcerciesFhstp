// Jakob Heigl-Auer, Uebung 6 - Aufgabe 1
// HeJ-U6-1.c

// Includes
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //Sleep

#define lastMatrikel 7 // 1-5 Rechts, >5 Links, Gerade = Wände portal, ungerade wände hindernis
#define firstNameLetter 'K'
#define lastNameLetter 'H'
#define gameFieldSize 8
#define definedObstacleAmount 10

//Deklarationen
struct HeJ_robot{
    int x;
    int y;
    int direction; //0=Up,1=Right,2=Down,3=Left
};

void HeJ_CreateObstacles(bool HeJ_GameField[gameFieldSize][gameFieldSize],int obstacleAmount, struct HeJ_robot robot);
void HeJ_PrintGame(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot);
struct HeJ_robot HeJ_MoveOneStep(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot);
bool checkForObstacle(bool HeJ_GameField[gameFieldSize][gameFieldSize], int newRobotPositionX, int newRobotPositionY);
struct HeJ_robot HeJ_StepByStep(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot);
struct HeJ_robot HeJ_N_Steps(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot);

int main(void)
{
    srand(time(NULL));
    //Variablen
    bool HeJ_GameField[gameFieldSize][gameFieldSize];
    struct HeJ_robot robot;
    char line[50];
    robot.x = firstNameLetter % gameFieldSize;
    robot.y = lastNameLetter % gameFieldSize;
    robot.direction = lastMatrikel % 4;

    for (int i = 0; i < gameFieldSize; ++i) {
        for (int j = 0; j < gameFieldSize; ++j) {
            HeJ_GameField[i][j]=0; //Initialisieren
        }
    }

    HeJ_CreateObstacles(HeJ_GameField,definedObstacleAmount,robot);
    printf("Was wollen Sie benutzen? (Einzelschritt/AufEinmal): ");
    if (fgets(line, 50, stdin) != NULL) //Kein Fehler aufgetreten
    {
        if (!strcmp(line, "Einzelschritt\n")) //User hat einzelschritt eingegeben
            robot = HeJ_StepByStep(HeJ_GameField,robot);
        else if(!strcmp(line, "AufEinmal\n"))
           robot = HeJ_N_Steps(HeJ_GameField,robot);
        else
            printf("Falsche Eingabe\n");
    }

    return 0;
}

void HeJ_CreateObstacles(bool HeJ_GameField[gameFieldSize][gameFieldSize],int obstacleAmount, struct HeJ_robot robot)
{
    int randomXCoordinate,randomYCoordinate;

    for (int i = 0; i < obstacleAmount; ++i) {
        randomXCoordinate = rand()%gameFieldSize;
        randomYCoordinate = rand()%gameFieldSize;
        if((HeJ_GameField[randomYCoordinate][randomXCoordinate] == 0) && ((robot.x != randomXCoordinate) || (robot.y != randomYCoordinate))) //Wenn Feld noch nicht besetzt dann besetzen
            HeJ_GameField[randomYCoordinate][randomXCoordinate] = 1;
        else //Feld war schon besetzt, erneut probieren
            --i;
    }
}

void HeJ_PrintGame(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot)
{
    int iteratorX;
    int iteratorY;
    system("clear");
    for (iteratorY = 0; iteratorY < gameFieldSize; ++iteratorY) {
        for (iteratorX = 0; iteratorX < gameFieldSize; ++iteratorX) {
            /*if(robot.x == iteratorX && robot.y == iteratorY)
            {
                printf("O ");
            }
            else
            {
                if(HeJ_GameField[iteratorY][iteratorX] == 0)
                    printf("- ");
                else
                    printf("# ");
            }*/
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
                    printf("# ");
            }
        }
        printf("\n");
    }
}

struct HeJ_robot HeJ_MoveOneStep(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot)
{
    int newRobotPositionX=0;
    int newRobotPositionY=0;
    int newRobotDirection=robot.direction;
    int countTrapped=0;
    bool obstacleHit=0;

    // STEP 1: Berechne neue Koordinate des Roboters je nach Richtung, Überprüfe ob dort Obstacle auftritt, überprüfe of dort Wand
    if(robot.direction==0) //Roboter Zeigt nach oben
    {
        newRobotPositionX=robot.x;      //X Unverändert
        newRobotPositionY=robot.y - 1;  //Y-1 => 1 schritt nach oben
        if(lastMatrikel%2==0) //Wand wäre Portal
        {
            if(newRobotPositionY<0) //Roboter steht zu weit oben, bewegung nach ganz unten
                newRobotPositionY=gameFieldSize-1;
            obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Ist dort ein Hindernis?
        }
        else //lastMatrikel%2==1, Wand wäre ein hindernis
        {
            obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Ist vor mir ein Hindernis?
            if(newRobotPositionY<0) //Obere Wand ist Obstacle
                obstacleHit=1;
        }
    }
    else if(robot.direction==1) //Roboter zeigt nach rechts
    {
        newRobotPositionX=robot.x + 1; //X+1 => 1 schritt nach rechts
        newRobotPositionY=robot.y;
        if(lastMatrikel%2==0) //Wand wäre ein Portal
        {
            if(newRobotPositionX>=gameFieldSize) //Roboter zu weit rechts, bewegung nach ganz links
                newRobotPositionX=0;
            obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Ist dort ein hindernis?
        }
        else //Wand wäre ein Hindernis
        {
            obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Ist vor mir ein Hindernis?
            if(newRobotPositionX>=gameFieldSize) //Wand ist ein Hindernis
                obstacleHit=1;
        }
    }
    else if(robot.direction==2) //Roboter zeigt nach unten
    {
        newRobotPositionX=robot.x;
        newRobotPositionY=robot.y + 1;
        if(lastMatrikel%2==0) //Wand wäre ein Portal
        {
            if(newRobotPositionY>=gameFieldSize) //Falls unterhalb des Felds
                newRobotPositionY = 0;  //Roboter nach ganz oben gesetzt
            obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Ist dort ein hindernis?
        }
        else //Wand wäre ein Hindernis
        {
            obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Ist vor mir ein Hindernis?
            if(newRobotPositionY>=gameFieldSize) //Wand vor mir ist ein Hindernis

                obstacleHit=1;
        }
    }
    else if(robot.direction==3) //Roboter Bewegung nach links
    {
        newRobotPositionX=robot.x - 1;
        newRobotPositionY=robot.y;
        if(lastMatrikel%2==0) //Wand wäre portal
        {
            if(newRobotPositionX<0)
                newRobotPositionX=gameFieldSize-1;
            obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
        }
        else //Wand wäre ein hindernis
        {
            obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
            if(newRobotPositionX<0)
                obstacleHit=1; //Wand ist hindernis
        }
    }

    // STEP 2: Falls Hindernis erkannt berechne neue Richtung + Bewegung wo kein Hindernis ist
    while (obstacleHit) //Falls ein Hindernis erkannt ist, ausweichen
    {
        ++countTrapped;
        if(countTrapped>(gameFieldSize*definedObstacleAmount)) //Roboter hängt fest
            exit(0);

        if(lastMatrikel<5) //Roboter dreht nach links ab
        {
            newRobotDirection = robot.direction - 1;
            if(newRobotDirection<0) //Wechsel von Up zu left
                newRobotDirection=3;
        }
        else //lastMatrikel>=5 Roboter dreht nach rechts ab
        {
           // printf("View Direction changed from %d to ",robot.direction);
            newRobotDirection = robot.direction + 1;
            if(newRobotDirection>3) //Wechsel von Left zu Up
                newRobotDirection=0;
            //printf(" %d\n",newRobotDirection);
        }
        //printf("Robot Position before change: X: %d, Y:%d\n",robot.x,robot.y);

        if(newRobotDirection==0) //Roboter zeigt nach oben
        {
            newRobotPositionX=robot.x;
            newRobotPositionY=robot.y - 1;
            if(lastMatrikel%2==0) //Wand wäre ein Portal
            {
                if(newRobotPositionY<0) //Roboter steht zu weit oben, bewegung nach ganz unten
                    newRobotPositionY=gameFieldSize-1;
                obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Ist dort ein hindernois
            }
            else //lastMatrikel%2==1, Wand wäre ein hindernis
            {
                //printf("Wände sind ein Obstacle\n");
                obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Schau ob in Blickrichtung obstacle
                if(newRobotPositionY<0) //Wand ist Obstacle
                {
                    //printf("Changed Y to 0\n");
                    obstacleHit=1;
                    newRobotPositionY=0;
                }
                else
                    obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Nächster Step auch ein Obstacle?
            }
        }
        else if(newRobotDirection==1) //Move right
        {
            newRobotPositionX=robot.x + 1;
            newRobotPositionY=robot.y;
            if(lastMatrikel%2==0) //Move to other side
            {
                if(newRobotPositionX>=gameFieldSize) //Roboter zu weit rechts, bewegung nach ganz links
                    newRobotPositionX=0;
                obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
            }
            else
            {
                obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
                if(newRobotPositionX>=gameFieldSize) //Wand ist obstacle
                {
                    obstacleHit=1;
                    newRobotPositionX=gameFieldSize-1;
                }
                else
                    obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Nächster Step auch ein Obstacle?
            }
        }
        else if(newRobotDirection==2) //Move down
        {
            newRobotPositionX=robot.x;
            newRobotPositionY=robot.y + 1;
            if(lastMatrikel%2==0) //Move to other side
            {
                if(newRobotPositionY>=gameFieldSize)
                    newRobotPositionY = 0;
                obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
            }
            else
            {
                obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
                if(newRobotPositionY>=gameFieldSize) //Wand ist obstacle
                {
                    obstacleHit=1;
                    newRobotPositionY=gameFieldSize-1;
                }
                else
                    obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Nächster Step auch ein Obstacle?
            }

        }
        else if(newRobotDirection==3) //Move left
        {
            newRobotPositionX=robot.x - 1;
            newRobotPositionY=robot.y;
            if(lastMatrikel%2==0) //Move to other side
            {
                if(newRobotPositionX<0)
                    newRobotPositionX=gameFieldSize-1;
                obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
            }
            else
            {
                obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY);
                if(newRobotPositionX<0)
                {
                    obstacleHit=1;
                    newRobotPositionX=0;
                }
                else
                    obstacleHit = checkForObstacle(HeJ_GameField,newRobotPositionX,newRobotPositionY); //Nächster Step auch ein Obstacle?
            }
        }
        robot.direction=newRobotDirection;
    }

    robot.x=newRobotPositionX;
    robot.y=newRobotPositionY;
    robot.direction=newRobotDirection;
    return robot;
}

bool checkForObstacle(bool HeJ_GameField[gameFieldSize][gameFieldSize], int newRobotPositionX, int newRobotPositionY) // Überprüfe ob bei Koordinate ein Obstacle ist
{
    return HeJ_GameField[newRobotPositionY][newRobotPositionX]==1 ? 1 : 0;;
}

struct HeJ_robot HeJ_StepByStep(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot)
{
    char line[50];
    for (;;)
    {
        printf("quit für beenden: ");
        if (fgets(line, 50, stdin) != NULL) //Kein Fehler aufgetreten
        {
            if (!strcmp(line, "quit\n")) //User hat quit eingegeben
            {
                return robot;
            }
            else
            {
                robot = HeJ_MoveOneStep(HeJ_GameField,robot);
                HeJ_PrintGame(HeJ_GameField,robot);
            }
        }
    }
}

struct HeJ_robot HeJ_N_Steps(bool HeJ_GameField[gameFieldSize][gameFieldSize],struct HeJ_robot robot)
{
    int steps=0;
    printf("Wie viele Schritte soll der Roboter gehen: ");
    scanf("%d",&steps);
    for (int iterator = 0; iterator < steps; ++iterator)
    {
        robot = HeJ_MoveOneStep(HeJ_GameField,robot);
        HeJ_PrintGame(HeJ_GameField,robot);
        sleep(1);
    }
    return robot;
}