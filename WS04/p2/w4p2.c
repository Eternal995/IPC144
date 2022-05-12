/*
*****************************************************************************
                          Workshop - #4 (P2)
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

int main(void)
{
    int num_apple = -1, num_orange = -1, num_pear = -1, num_tomato = -1, num_cabbage = -1, num_buy = -1, another_shopping = 1;

    do
    {

        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d%*c", &num_apple);
            if (num_apple < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (num_apple < 0);

        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d%*c", &num_orange);
            if (num_orange < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (num_orange < 0);

        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d%*c", &num_pear);
            if (num_pear < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (num_pear < 0);

        printf("\n");

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d%*c", &num_tomato);
            if (num_tomato < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (num_tomato < 0);

        printf("\n");

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d%*c", &num_cabbage);
            if (num_cabbage < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (num_cabbage < 0);

        printf("\n--------------------------\nTime to pick the products!\n--------------------------\n\n");

        while (num_apple != 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d%*c", &num_buy);
            if (num_buy > num_apple)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", num_apple);
            }
            else if (num_buy <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (num_buy > 0 && num_buy < num_apple)
            {
                num_apple = num_apple - num_buy;
                printf("Looks like we still need some APPLES...\n");
            }
            else if (num_buy == num_apple)
            {
                num_apple = num_apple - num_buy;
                printf("Great, that's the apples done!\n\n");
            }
        }

        while (num_orange != 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d%*c", &num_buy);
            if (num_buy > num_orange)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", num_orange);
            }
            else if (num_buy <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (num_buy > 0 && num_buy < num_orange)
            {
                num_orange = num_orange - num_buy;
                printf("Looks like we still need some ORANGES...\n");
            }
            else if (num_buy == num_orange)
            {
                num_orange = num_orange - num_buy;
                printf("Great, that's the oranges done!\n\n");
            }
        }

        while (num_pear != 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d%*c", &num_buy);
            if (num_buy > num_pear)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", num_pear);
            }
            else if (num_buy <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (num_buy > 0 && num_buy < num_pear)
            {
                num_pear = num_pear - num_buy;
                printf("Looks like we still need some PEARS...\n");
            }
            else if (num_buy == num_pear)
            {
                num_pear = num_pear - num_buy;
                printf("Great, that's the pears done!\n\n");
            }
        }

        while (num_tomato != 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d%*c", &num_buy);
            if (num_buy > num_tomato)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", num_tomato);
            }
            else if (num_buy <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (num_buy > 0 && num_buy < num_tomato)
            {
                num_tomato = num_tomato - num_buy;
                printf("Looks like we still need some TOMATOES...\n");
            }
            else if (num_buy == num_tomato)
            {
                num_tomato = num_tomato - num_buy;
                printf("Great, that's the tomatoes done!\n\n");
            }
        }

        while (num_cabbage != 0)

        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d%*c", &num_buy);
            if (num_buy > num_cabbage)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", num_cabbage);
            }
            else if (num_buy <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (num_buy > 0 && num_buy < num_cabbage)
            {
                num_cabbage = num_cabbage - num_buy;
                printf("Looks like we still need some CABBAGES...\n");
            }
            else if (num_buy == num_cabbage)
            {
                num_cabbage = num_cabbage - num_buy;
                printf("Great, that's the cabbages done!\n\n");
            }
        }

        printf("All the items are picked!\n\nDo another shopping? (0=NO): ");
        scanf("%d%*c", &another_shopping);
        printf("\n");

    } while (another_shopping != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}