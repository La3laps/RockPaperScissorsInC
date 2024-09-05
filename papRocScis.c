#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int getUserInput();
int getComputerInput();
int startGame();

int main()
{
    startGame();
    return 0;
}

int getUserInput()
{
    char *input = malloc(sizeof(char));
    printf("----------------------------------------\n\tRock, Paper, Scissors ?\n\t");
    scanf("%s", input);

    if (strcmp("Rock", input) == 0 || strcmp("rock", input) == 0)
    {
        printf("----------------------------------------\n\tYou chose %s\n", input);
        return 1;
    }
    else if (strcmp("Paper", input) == 0 || strcmp("paper", input) == 0)
    {
        printf("----------------------------------------\n\tYou chose %s\n", input);
        return 2;
    }
    else if (strcmp(input, "Scissors") == 0 || strcmp(input, "scissors") == 0)
    {
        printf("----------------------------------------\n\tYou chose %s\n", input);
        return 3;
    }
    else
    {
        printf(" Please select a real choice instead of : \"%s\"\n", input);
        return getUserInput();
    }
}

int getComputerInput()
{
    srand(time(NULL));
    int randNum = rand() % 9;
    if (randNum < 3)
    {
        printf("\tComputer chose Rock\n");
        printf("----------------------------------------\n");
        return 1;
    }
    else if (randNum < 6)
    {
        printf("\tComputer chose Paper\n");
        printf("----------------------------------------\n");
        return 2;
    }
    else
    {
        printf("\tComputer chose Scissors\n");
        printf("----------------------------------------\n");
        return 3;
    }
}

int startGame()
{
    int userResult = getUserInput();
    int computerResult = getComputerInput();
    if (userResult == computerResult)
    {
        printf("\tIt's a TIE !\n");
    }
    else if (userResult < computerResult || userResult == 3 && computerResult == 1)
    {
        printf("\tYou LOST...\n");
    }
    else if (userResult > computerResult)
    {
        printf("\tYou WON!!!\n");
    }
}