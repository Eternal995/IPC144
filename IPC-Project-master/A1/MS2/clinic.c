/*
*****************************************************************************
                        Assignment 1 - Milestone 2
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
#include <string.h>
#include <ctype.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0, count = 0;

    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            count++;
        }
        else
        {
            displayPatientData(&patient[i], fmt);
        }
    }

    if (count == max)
    {
        printf("*** No records found ***");
    }

    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Search Options\n"
                "==========================\n"
                "1) By patient number\n"
                "2) By phone number\n"
                "..........................\n"
                "0) Previous menu\n"
                "..........................\n"
                "Selection: ");

        selection = inputIntRange(0, 2);

        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
        }

        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
        }

    } while (selection);

    putchar('\n');
}


// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void addPatient(struct Patient patient[], int max)
{
    int empty = -1, i = 0;
    
    for (i = 0; i < max && empty == -1; i++)
    {
        if (patient[i].patientNumber == 0 && empty == -1) empty = i;
    }

    if (empty == -1)
    {
        printf("ERROR: Patient listing is FULL!\n");
    }

    else
    {
        patient[empty].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[empty]);
        printf("*** New patient record added ***\n");
    }

    putchar('\n');
}


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void editPatient(struct Patient patient[], int max)
{
    int ptnumber = 0, index = -1;

    printf("Enter the patient number: ");
    ptnumber = inputIntPositive();
    index = findPatientIndexByPatientNum(ptnumber, patient, max);


    putchar('\n');
    
    if (index == -1)
    {
        printf("*** No records found ***\n\n");
    }

    else
    {
        menuPatientEdit(&patient[index]);
    }
}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void removePatient(struct Patient patient[], int max)
{
    int ptnumber = 0, index = -1, selection = 1;

    printf("Enter the patient number: ");
    ptnumber = inputIntPositive();
    index = findPatientIndexByPatientNum(ptnumber, patient, max);

    putchar('\n');

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }

    else
    {
        displayPatientData(&patient[index], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        selection = !(inputCharOption("yn") == 'y');

        if (selection)
        {
            printf("Operation aborted.\n");
        }

        else
        {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n");
        }
    }

    putchar('\n');
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int ptnumber = 0, index = -1;

    printf("\nSearch by patient number: ");
    ptnumber = inputIntPositive();
    index = findPatientIndexByPatientNum(ptnumber, patient, max);

    putchar('\n');

    if (index == -1)
    {
        printf("*** No records found ***\n");
    }

    else
    {
        displayPatientData(&patient[index], FMT_FORM);
    }

    putchar('\n');
    suspend();
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i = 0, find = 0;
    char pnumber[PHONE_LEN+1];

    putchar('\n');
    printf("Search by phone number: ");
    inputCString(pnumber, PHONE_LEN, PHONE_LEN);
    putchar('\n');
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, pnumber) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            find++;
        }
    }

    if (!find)
    {
        printf("\n*** No records found ***\n");
    }

    putchar('\n');
    suspend();
}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int nextPatientNumber(const struct Patient patient[], int max)
{
    int maxnum = 0, i = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > maxnum) maxnum = patient[i].patientNumber;
    }

    return maxnum + 1;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i = 0, index = -1;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber) index = i;
    }

    return index;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n"
        "Number: %05d\n"
        "Name  : ", patient->patientNumber);
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}



// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone* phone)
{
    int selection = 0;
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    selection = inputIntRange(1, 4);
    
    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }

    if (selection == 4)
    {
        phone->number[0] = '\0';
    }

    else
    {
        char pnumber[PHONE_LEN + 1];
        putchar('\n');
        printf("Contact: %s\n"
            "Number : ", phone->description);
        inputCString(pnumber, PHONE_LEN, PHONE_LEN);
        strcpy(phone->number, pnumber);
    }

    putchar('\n');
}
