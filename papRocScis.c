#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int getUserInput();
int getComputerInput();
int startGame();

void red();
void green();
void cyan();
void blue();
void yellow();
void white();
void black();
void printChoice(int choice);
void printDottedLine();

int main()
{
    startGame();
    return 0;
}

int getUserInput()
{
    char *input = malloc(sizeof(char));

    printDottedLine();

    red();
    printf("\tRock, Paper, Scissors ?\n\t");
    white();
    cyan();
    scanf("%s", input);
    white();

    printDottedLine();
    if (strcmp("Rock", input) == 0 || strcmp("rock", input) == 0)
    {
        printf("\tYou chose ");
        printChoice(1);
        return 1;
    }
    else if (strcmp("Paper", input) == 0 || strcmp("paper", input) == 0)
    {
        printf("\tYou chose ");
        printChoice(2);
        return 2;
    }
    else if (strcmp(input, "Scissors") == 0 || strcmp(input, "scissors") == 0)
    {
        printf("\tYou chose ");
        printChoice(2);
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
        printf("\tComputer chose ");
        printChoice(1);
        printDottedLine();
        return 1;
    }
    else if (randNum < 6)
    {
        printf("\tComputer chose ");
        printChoice(2);
        printDottedLine();
        return 2;
    }
    else
    {
        printf("\tComputer chose ");
        printChoice(3);
        printDottedLine();
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

void red()
{
    printf("\033[1;31m");
}

void green()
{
    printf("\033[0;32m");
}

void yellow()
{
    printf("\033[0;33m");
}

void white()
{
    printf("\033[0m");
}

void black()
{
    printf("\033[0;30m");
}

void cyan()
{
    printf("\033[0;36m");
}

void blue()
{
    printf("\033[0;34m");
}

void printChoice(int choice)
{
    if (choice == 1)
    {
        yellow();
        printf("Rock\n");
        white();
    }
    else if (choice == 2)
    {
        cyan();
        printf("Paper\n");
        white();
    }
    else
    {
        blue();
        printf("Scissors\n");
        white();
    }
}

void printDottedLine()
{
    red();
    printf("----------------------------------------\n");
    white();
}