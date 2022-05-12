/*
*****************************************************************************
                          Workshop - #7 (P2)
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
#define MAX_MOVES 15

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
    struct PlayerInfo playerinfo = { ' ',0,0,{0}};
    int i, j, next_move = -1, moves_remain = 0;

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

        if (gameinfo.Path_Length < 10 || gameinfo.Path_Length>70 || gameinfo.Path_Length % 5 != 0) printf("     Must be a multiple of 5 and between 10-70!!!\n");
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

    moves_remain = gameinfo.Max_Moves;

    while (playerinfo.Num_Lives != 0 && moves_remain != 0)
    {
        if (next_move < 1)
        {
            printf("\n");
        }

        else
        {
            printf(" ");
            for (i = 0; i < next_move; i++)
            {
                printf(" ");
            }
            printf("%c\n", playerinfo.Symbol);
        }

        printf("  ");

        for (i = 0; i < gameinfo.Path_Length; i++)
        {
            if (playerinfo.Pos_Visited[i] == 0)
            {
                printf("-");
            }
            else if (playerinfo.Pos_Visited[i] == 1 && gameinfo.Bombs[i] == 1 && gameinfo.Treasure[i] == 1)
            {
                printf("&");
            }
            else if (playerinfo.Pos_Visited[i] == 1 && gameinfo.Bombs[i] == 1)
            {
                printf("!");
            }
            else if (playerinfo.Pos_Visited[i] == 1 && gameinfo.Treasure[i] == 1)
            {
                printf("$");
            }
            else
            {
                printf(".");
            }
        }

        printf("\n  ");

        for (i = 0; i < gameinfo.Path_Length; i++)
        {
            j = i + 1;
            if (j % 10 == 0)
            {
                printf("%d", j / 10);
            }
            else
            {
                printf("|");
            }
        }

        printf("\n  ");

        for (i = 0; i < gameinfo.Path_Length; i++)
        {
            j = i + 1;
            printf("%d", j % 10);
        }

        printf("\n");

        printf("+---------------------------------------------------+\n"); 
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", playerinfo.Num_Lives, playerinfo.Treasures_Found, moves_remain);
        printf("+---------------------------------------------------+\n");

        do
        {

            printf("Next Move [1-%d]: ", gameinfo.Path_Length);
            scanf("%d%*c", &next_move);

            if (next_move < 1 || next_move>gameinfo.Path_Length) printf("  Out of Range!!!\n");

        } while (next_move < 1 || next_move>gameinfo.Path_Length);

        printf("\n");

        if (playerinfo.Pos_Visited[next_move - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n\n");
        }

        else if (gameinfo.Bombs[next_move - 1] == 1 && gameinfo.Treasure[next_move - 1] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            playerinfo.Num_Lives -= 1;
            playerinfo.Treasures_Found += 1;
            moves_remain -= 1;
        }

        else if (gameinfo.Bombs[next_move - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            playerinfo.Num_Lives -= 1;
            moves_remain -= 1;
        }

        else if (gameinfo.Treasure[next_move - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            playerinfo.Treasures_Found += 1;
            moves_remain -= 1;
        }

        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            moves_remain -= 1;
        }

        playerinfo.Pos_Visited[next_move - 1] = 1;
    }

    if (playerinfo.Num_Lives == 0) printf("No more LIVES remaining!\n");
    if (moves_remain == 0) printf("No more MOVES remaining!\n");

    printf("\n");

    if (next_move < 1)
    {
        printf("\n");
    }

    else
    {
        printf(" ");
        for (i = 0; i < next_move; i++)
        {
            printf(" ");
        }
        printf("%c", playerinfo.Symbol);
    }

    printf("\n  ");

    for (i = 0; i < gameinfo.Path_Length; i++)
    {
        if (playerinfo.Pos_Visited[i] == 0)
        {
            printf("-");
        }
        else if (playerinfo.Pos_Visited[i] == 1 && gameinfo.Bombs[i] == 1 && gameinfo.Treasure[i] == 1)
        {
            printf("&");
        }
        else if (playerinfo.Pos_Visited[i] == 1 && gameinfo.Bombs[i] == 1)
        {
            printf("!");
        }
        else if (playerinfo.Pos_Visited[i] == 1 && gameinfo.Treasure[i] == 1)
        {
            printf("$");
        }
        else
        {
            printf(".");
        }
    }

    printf("\n  ");

    for (i = 0; i < gameinfo.Path_Length; i++)
    {
        j = i + 1;
        if (j % 10 == 0)
        {
            printf("%d", j / 10);
        }
        else
        {
            printf("|");
        }
    }

    printf("\n  ");

    for (i = 0; i < gameinfo.Path_Length; i++)
    {
        j = i + 1;
        printf("%d", j % 10);
    }

    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", playerinfo.Num_Lives, playerinfo.Treasures_Found, moves_remain);
    printf("+---------------------------------------------------+\n");

    printf("\n##################\n#   Game over!   #\n##################\n\nYou should play again and try to beat your score!\n");

    return 0;
}
