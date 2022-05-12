/*
*****************************************************************************
                          Workshop - #4 (P1)
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
    char looptype = ' ';
    int looptimes = 0, running = 1, i = 0;

    printf("+----------------------+\nLoop application STARTED\n+----------------------+\n\n");

    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf("%c%d%*c", &looptype, &looptimes);

        if (looptype == 'Q' && looptimes == 0)
        {
            printf("\n+--------------------+\nLoop application ENDED\n+--------------------+\n");
            running = 0;
        }

        else if (looptype == 'Q' && looptimes != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            running = 1;
        }

        else if ((looptype != 'D') && (looptype != 'W') && (looptype != 'F') && (looptype != 'Q'))
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
            running = 1;
        }

        else if (looptimes < 3 || looptimes > 20)
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            running = 1;
        }

        else if ((looptype == 'Q') && (looptimes != 0))
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            running = 1;
        }

        else if (looptype == 'D' && (looptimes >= 3 && looptimes <= 20))
        {
            printf("DO-WHILE: ");
            do
            {
                looptimes--;
                printf("D");
            } while (looptimes > 0);
            running = 1;
            printf("\n\n");
        }

        else if (looptype == 'W' && (looptimes >= 3 && looptimes <= 20))
        {
            printf("WHILE   : ");
            while (looptimes > 0)
            {
                looptimes--;
                printf("W");
            }
            running = 1;
            printf("\n\n");
        }

        else if (looptype == 'F' && (looptimes >= 3 && looptimes <= 20))
        {
            printf("FOR     : ");
            for (i = looptimes; i > 0; --i)
            {
                printf("F");
            }
            running = 1;
            printf("\n\n");
        }


    } while (running != 0);

    return 0;
}