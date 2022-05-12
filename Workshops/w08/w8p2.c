/*
*****************************************************************************
                          Workshop - #8 (P2)
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

// User-Defined Libraries

#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* lbs, double* kg)
{
    double value;
    value = *lbs / LBS_IN_KG;
    if (kg != NULL) *kg = value;
    return value;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* lbs, int* g)
{
    int value;
    value = (int)((*lbs / LBS_IN_KG) * 1000);
    if (g != NULL) *g = value;
    return value;
}

// 10. convert lbs: kg and g

void convertLbs(const double* lbs, double* kg, int* g)
{
    convertLbsKg(lbs, kg);
    convertLbsG(lbs, g);
}

// 11. calculate: servings based on gPerServ

double calculateServings(const int serving_size, const int total_gram, double* result)
{
    double value;
    value = (double)total_gram / (double)serving_size;
    if (result != NULL) *result = value;
    return value;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double* price, const double* total_serving, double* result)
{
    double value;
    value = *price / *total_serving;
    if (result != NULL) *result = value;
    return value;
}

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, const int* cal, const double* serving, double* result)
{
    double value;
    value = *price / ((double)*cal * *serving);
    if (result != NULL) *result = value;
    return value;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo info)
{
    struct ReportData data;
    data.sku = info.sku_number;
    data.price = info.price;
    data.calories = info.calories;
    data.weight_lbs = info.weight;
    convertLbs(&data.weight_lbs, &data.weight_kg, &data.weight_g);
    data.total_serving = calculateServings(GRAMS_IN_SERVING, data.weight_g, &data.total_serving);
    data.cost_per_serving = calculateCostPerServing(&data.price, &data.total_serving, &data.cost_per_serving);
    data.cost_per_calories = calculateCostPerCal(&data.price, &data.calories, &data.total_serving, &data.cost_per_calories);

    return data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_IN_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData data, const int cheapest)
{
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
        data.sku, data.price, data.weight_lbs, data.weight_kg, data.weight_g, data.calories, data.total_serving, data.cost_per_serving, data.cost_per_calories);
    if (cheapest) printf(" ***");
    printf("\n");
}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo info)
{
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n", info.sku_number, info.price);
    printf("\n");
    printf("Happy shopping!\n");
    printf("\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    const int num_product = MAX_PRODUCT;
    struct CatFoodInfo info[MAX_PRODUCT] = { {0,0.0,0,0.0} };
    struct ReportData data[MAX_PRODUCT];
    int i, cheapest = 0;

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

    displayReportHeader();

    for (i = 0; i < num_product; i++)
    {
        data[i] = calculateReportData(info[i]);
        if (data[i].cost_per_serving < data[cheapest].cost_per_serving) cheapest = i;
    }

    for (i = 0; i < num_product; i++)
    {
        if (i == cheapest) displayReportData(data[i], 1); else displayReportData(data[i], 0);
    }

    printf("\n");

    displayFinalAnalysis(info[cheapest]);
}
