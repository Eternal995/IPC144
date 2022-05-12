#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int Balance_Penny = 1234;
    double Balance;

    Balance = (double) (Balance_Penny / 100);

    printf("Balance = %lf", Balance);

    return 0;
}