/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

#include <stdio.h>

#include "core.h"

#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS

#define MAX_LENGTH 50

// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer 
// Clear the standard input buffer 
void clearInputBuffer(void) 
{ 
    // Discard all remaining char's from the standard input buffer: 
    while (getchar() != '\n') 
    { ; 
    // do nothing! 
    } 
}

// Wait for user to input the "enter" key to continue 
void suspend(void) 
{ 
    printf("<ENTER> to continue..."); 
    clearInputBuffer(); 
    putchar('\n'); 
}

//return an integer value
int inputInt(void)
{
    char newline = 'x';
    int value = 0;

    scanf("%d%c", &value, &newline);

    while (newline != '\n')
    {
        clearInputBuffer();
        printf("Error! Input a whole number: ");
        scanf("%d%c", &value, &newline);
    }

    return value;
}

//return an positive integer value
int inputIntPositive(void)
{
    int answer;

    answer = inputInt();
    
    while (answer <= 0)
    {
        printf("ERROR! Value must be > 0: ");
        answer = inputInt();
    }

    return answer;
}

//return an integer value in desired range
int inputIntRange(const int lower, const int upper)
{
    int value;

    value = inputInt();

    while (value < lower || value > upper)
    {
        printf("ERROR! Value must be between %d and %d inclusive: ",lower, upper);
        value = inputInt();
    }

    return value;
}

//return a single character within the list of input characters
char inputCharOption(const char* chars)
{
    char input = 'x', newline = 'x';
    int i = 0, valid = 0;

    while (!valid)
    {
        scanf("%c%c", &input, &newline);

        if (newline != '\n') clearInputBuffer();

        for (i = 0; chars[i] != '\0'; i++)
        {
            if (chars[i] == input) valid = 1;
        }

        if (!valid) printf("ERROR: Character must be one of [%s]: ", chars);
    }

    return input;
}

//return a character string that have desired length
void inputCString(char* string, const int min, const int max)
{
    int i = 0, valid = 0, length = 0;
    char input[MAX_LENGTH+1];

    while (!valid)
    {
        scanf("%[^\n]", input);

        length = 0;

        for (i = 0; input[i] != '\0'; i++)
        {
            length++;
        }

        if (length >= min && length <= max)
        {
            valid = 1;
        }

        else if (min == max && length != max)
        {
            printf("ERROR: String length must be exactly %d chars: ", max);
        }

        else if (length > max)
        {
            printf("ERROR: String length must be no more than %d chars: ", max);
        }

        else if (length < min)
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }

        clearInputBuffer();
    }

    for (i = 0; i <= max; i++)
    {
        string[i] = input[i];
    }
}

//display formatted phone number only if its a vaild phone number
void displayFormattedPhone(const char* string)
{
    int i = 0, valid = 0;

    if (string != NULL)
    {
        for (i = 0; i <= 9; i++)
        {
            if (isdigit(string[i])) valid++;
        }
    }

    if (valid == 10 && string[10] == '\0')
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8], string[9]);
    }

    else
    {
        printf("(___)___-____");
    }
}