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

// Clear the standard input buffer 
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue 
void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(const int lower, const int upper);

char inputCharOption(const char* chars);

void inputCString(char* string, const int min, const int max);

void displayFormattedPhone(const char* string);
