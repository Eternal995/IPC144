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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCT 3
#define GRAMS_IN_SERVING 64
#define LBS_IN_KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku_number;
    double price;
    int calories;
    double weight;
};

struct ReportData
{
    int sku;
    double price;
    int calories;
    double weight_lbs, weight_kg;
    int weight_g;
    double total_serving, cost_per_serving, cost_per_calories;
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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg

double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g

int convertLbsG(const double* lbs, int* g);

// 10. convert lbs: kg / g

void convertLbs(const double* lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ

double calculateServings(const int serving_size, const int total_gram, double* result);

// 12. calculate: cost per serving

double calculateCostPerServing(const double* price, const double* total_serving, double* result);

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, const int* cal, const double* serving, double* result);

// 14. Derive a reporting detail record based on the cat food product data{

struct ReportData calculateReportData(const struct CatFoodInfo info);

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData data, const int cheapest);

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo info);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start(void);
