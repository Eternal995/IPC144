/*
*****************************************************************************
                          Workshop - #6 (P1)
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
    const double Min_Income = 500.00, Max_Income = 400000.00;
    double income, cost[9], total = 0.0;
    int i, wish_list, importance[9];
    char financing[9];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf%*c", &income);

        if (income <= Min_Income) printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        else if (income >= Max_Income) printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");

    } while (income <= Min_Income || income >= Max_Income);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d%*c", &wish_list);

        if (wish_list < 1 || wish_list>10) printf("ERROR: List is restricted to between 1 and 10 items.\n");

    } while (wish_list < 1 || wish_list>10);

    for (i = 1; i <= wish_list; i++)
    {
        printf("\nItem-%d Details:\n", i);

        do
        {
            printf("   Item cost: $");
            scanf("%lf%*c", &cost[i - 1]);
            if (cost[i - 1] < 100.00) printf("      ERROR: Cost must be at least $100.00\n");
        } while (cost[i - 1] < 100.00);

        total += cost[i - 1];

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d%*c", &importance[i - 1]);

            if (importance[i - 1] != 1 && importance[i - 1] != 2 && importance[i - 1] != 3) printf("      ERROR: Value must be between 1 and 3\n");

        } while (importance[i - 1] != 1 && importance[i - 1] != 2 && importance[i - 1] != 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c%*c", &financing[i - 1]);

            if (financing[i - 1] != 'y' && financing[i - 1] != 'n') printf("      ERROR: Must be a lowercase 'y' or 'n'\n");

        } while (financing[i - 1] != 'y' && financing[i - 1] != 'n');

    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < wish_list; i++)
    {
        printf("%3d %6d %8c %14.2lf\n", i + 1, importance[i], financing[i], cost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total);
    printf("Best of luck in all your future endeavours!\n");



    return 0;
}