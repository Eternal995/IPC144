/*
*****************************************************************************
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012 
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year = 0, month = 0;

    printf("General Well-being Log\n======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");

        scanf("%d %d%*c", &year, &month);

        if (year > MAX_YEAR || year < MIN_YEAR) printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);

        if (month > DEC || month < JAN) printf("   ERROR: Jan.(1) - Dec.(12)\n");

    } while ((year > MAX_YEAR || year < MIN_YEAR) || (month > DEC || month < JAN));

    printf("\n*** Log date set! ***\n\n");
    printf("Log starting date: %d-", year);
    switch (month)
    {
    case 1:
        printf("JAN");
        break;
    case 2:
        printf("FEB");
        break;
    case 3:
        printf("MAR");
        break;
    case 4:
        printf("APR");
        break;
    case 5:
        printf("MAY");
        break;
    case 6:
        printf("JUN");
        break;
    case 7:
        printf("JUL");
        break;
    case 8:
        printf("AUG");
        break;
    case 9:
        printf("SEP");
        break;
    case 10:
        printf("OCT");
        break;
    case 11:
        printf("NOV");
        break;
    case 12:
        printf("DEC");
        break;
    }
    printf("-01\n");


    return 0;
}