/*
*****************************************************************************
                          Workshop - #2 (P1)
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
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    int product1_id = 111, product2_id = 222, product3_id = 111;
    double product1_price = 111.49, product2_price = 222.99, product3_price = 334.49, average_price = (product1_price + product2_price + product3_price) / 3;
    char product1_taxed = 'Y', product2_taxed = 'N', product3_taxed = 'N';

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", product1_id);
    printf("  Taxed: %c\n", product1_taxed);
    printf("  Price: $%.4lf\n\n", product1_price);
    printf("Product-2 (ID:%d)\n", product2_id);
    printf("  Taxed: %c\n", product2_taxed);
    printf("  Price: $%.4lf\n\n", product2_price);
    printf("Product-3 (ID:%d)\n", product3_id);
    printf("  Taxed: %c\n", product3_taxed);
    printf("  Price: $%.4lf\n\n", product3_price);
    printf("The average of all prices is: $%.4lf\n\n", average_price);
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", product1_taxed == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", product2_taxed == 'N' && product3_taxed == 'N');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, product3_price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", product3_price > (product1_price + product2_price));
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", product1_price >= (product3_price - product2_price), product3_price - product2_price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", product2_price >= average_price);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", product1_id != product2_id && product1_id != product3_id);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", product2_id != product1_id && product2_id != product3_id);
    printf("9. Based on product ID, product 3 is unique -> %d\n", product3_id != product1_id && product3_id != product2_id);

    return 0;
}