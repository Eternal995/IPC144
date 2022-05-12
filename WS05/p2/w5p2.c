/*
*****************************************************************************
                          Workshop - #5 (P2)
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

#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year = 0, month = 0, i;
    double Morning_rating, Evening_rating, total_morning = 0.0 , total_evening = 0.0;

    printf("General Well-being Log\n======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");

        scanf("%d %d%*c", &year, &month);

        if (year > MAX_YEAR || year < MIN_YEAR) printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);

        if (month > DEC || month < JAN) printf("   ERROR: Jan.(1) - Dec.(12)\n");

    } while ((year > MAX_YEAR || year < MIN_YEAR) || (month > DEC || month < JAN));

    printf("\n*** Log date set! ***\n\n");

    for (i = 1; i <= LOG_DAYS; i++)
    {

        printf("%d-", year);
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
        printf("-%02d\n", i);

        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf%*c", &Morning_rating);
            if (Morning_rating < 0.0 || Morning_rating >5.0) printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        } while (Morning_rating < 0.0 || Morning_rating >5.0);

        total_morning += Morning_rating;

        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf%*c", &Evening_rating);
            if (Evening_rating < 0.0 || Evening_rating >5.0) printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        } while (Evening_rating < 0.0 || Evening_rating >5.0);

        total_evening += Evening_rating;

        printf("\n");
    }

    printf("Summary\n=======\n");
    printf("Morning total rating: %6.3lf\n", total_morning);
    printf("Evening total rating: %6.3lf\n", total_evening);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", total_evening + total_morning);
    printf("Average morning rating:  %2.1lf\n", total_morning / LOG_DAYS);
    printf("Average evening rating:  %2.1lf\n", total_evening / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %2.1lf\n", (total_morning + total_evening) / 2 / LOG_DAYS);

    return 0;
}