/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : IPC144NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LENGTH 70
#define MIN_MOVES 3
#define MAX_MOVES 26

struct PlayerInfo
{
    char Symbol;
    int Num_Lives;
    int Treasures_Found;
    int Pos_Visited[MAX_LENGTH];
};

struct GameInfo
{
    int Max_Moves;
    int Path_Length;
    int Treasure[MAX_LENGTH];
    int Bombs[MAX_LENGTH];
};

int main(void)
{
    struct GameInfo gameinfo = { 0,0,{0},{0} };
    struct PlayerInfo playerinfo = { ' ',0,0,{0} };
    int i, j;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf("%c%*c", &playerinfo.Symbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d%*c", &playerinfo.Num_Lives);

        if (playerinfo.Num_Lives < 1 || playerinfo.Num_Lives > 10) printf("     Must be between 1 and 10!\n");
    } while (playerinfo.Num_Lives < 1 || playerinfo.Num_Lives > 10);

    printf("Player configuration set-up is complete\n\nGAME Configuration\n------------------\n");

    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d%*c", &gameinfo.Path_Length);

        if (gameinfo.Path_Length < 10 || gameinfo.Path_Length>70 || gameinfo.Path_Length%5 != 0) printf("     Must be a multiple of 5 and between 10-70!!!\n");
    } while (gameinfo.Path_Length < 10 || gameinfo.Path_Length>70 || gameinfo.Path_Length % 5 != 0);

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d%*c", &gameinfo.Max_Moves);

        if (gameinfo.Max_Moves < MIN_MOVES || gameinfo.Max_Moves > MAX_MOVES) printf("    Value must be between %d and %d\n", MIN_MOVES, MAX_MOVES);
    } while (gameinfo.Max_Moves < MIN_MOVES || gameinfo.Max_Moves > MAX_MOVES);

    printf("\nBOMB Placement\n--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.Path_Length);

    for (i = 0; i < gameinfo.Path_Length; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        
        for (j = i; j < (i + 5); j++)
        {
            scanf("%d", &gameinfo.Bombs[j]);
        }
    }

    printf("BOMB placement set\n\nTREASURE Placement\n------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.Path_Length);

    for (i = 0; i < gameinfo.Path_Length; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

        for (j = i; j < (i + 5); j++)
        {
            scanf("%d", &gameinfo.Treasure[j]);
        }
    }

    printf("TREASURE placement set\n\nGAME configuration set-up is complete...\n\n");
    printf("------------------------------------\nTREASURE HUNT Configuration Settings\n------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", playerinfo.Symbol);
    printf("   Lives      : %d\n", playerinfo.Num_Lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", gameinfo.Path_Length);
    printf("   Bombs      : ");
    for (i = 0; i < gameinfo.Path_Length; i++)
    {
        printf("%d", gameinfo.Bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < gameinfo.Path_Length; i++)
    {
        printf("%d", gameinfo.Treasure[i]);
    }

    printf("\n\n====================================\n~ Get ready to play TREASURE HUNT! ~\n====================================\n");

    return 0;
}
