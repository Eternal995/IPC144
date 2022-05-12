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

#define _CRT_SECURE_NO_WARNINGS

// System Libraries

#include <stdio.h>

// User Libraries

#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* num)
{
    int value = 0;

    scanf("%d", &value);

    while (value <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf("%d", &value);
    }

    if (num != NULL) *num = value;

    return value;

}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* num)
{
    double value = 0.0;

    scanf("%lf", &value);

    while (value <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf("%lf", &value);
    }

    if (num != NULL) *num = value;

    return value;
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int num_product)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
    printf("NOTE: A 'serving' is %dg\n", GRAMS_IN_SERVING);

    return;
}

// 4. Get user input for the details of cat food product

void getCatFoodInfo(struct CatFoodInfo* info, const int num)
{
    printf("\nCat Food Product #%d\n--------------------\n", num + 1);
    printf("SKU           : ");
    getIntPositive(&info->sku_number);
    printf("PRICE         : $");
    getDoublePositive(&info->price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&info->weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&info->calories);
    

}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(int skull, double* price, double* weight, int calories)
{
    printf("%07d %10.2lf %10.1lf %8d\n", skull, *price, *weight, calories);
}

// 7. Logic entry point

void start(void)
{
    const int num_product = MAX_PRODUCT;
    struct CatFoodInfo info[MAX_PRODUCT] = { {0,0.0,0,0.0} };
    int i;

    openingMessage(num_product);

    for (i = 0; i < num_product; i++)
    {
        getCatFoodInfo(&info[i], i);
    }

    printf("\n");

    displayCatFoodHeader();

    for (i = 0; i < num_product; i++)
    {
        displayCatFoodData(info[i].sku_number, &info[i].price, &info[i].weight, info[i].calories);
    }

    printf("\n");

}
