/*
*****************************************************************************
                          Workshop - #8 (P1)
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

#define MAX_PRODUCT 3
#define GRAMS_IN_SERVING 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku_number;
    double price;
    int calories;
    double weight;
};


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* num);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int num);

// 4. Get user input for the details of cat food product

void getCatFoodInfo(struct CatFoodInfo* info, const int num);

// 5. Display the formatted table header

void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(int skull, double* price, double* weight, int calories);

// 7. Logic entry point

void start(void);
