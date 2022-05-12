/*
*****************************************************************************
                          Workshop - #3 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    int price_S_1, price_S_2, price_M_1,price_M_2, price_L_1, price_L_2, Num_buying;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%d.%d%*c", &price_S_1, &price_S_2);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%d.%d%*c", &price_M_1, &price_M_2);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%d.%d%*c", &price_L_1, &price_L_2);

    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%d.%d\n", price_S_1, price_S_2);
    printf("MEDIUM : $%d.%d\n", price_M_1, price_M_2);
    printf("LARGE  : $%d.%d\n\n", price_L_1, price_L_2);

    printf("Patty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d%*c", &Num_buying);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", Num_buying);
    printf("Sub-total: $%3.4lf\n", (int)(((price_S_1 * 100 + price_S_2) * Num_buying) + 0.5) / 100.);
    printf("Taxes    : $ %3.4lf\n", ((int)(((price_S_1 * 100 + price_S_2) * Num_buying) * TAX + 0.5) / 100.));
    printf("Total    : $%3.4lf\n", ((int)(((price_S_1 * 100 + price_S_2) * Num_buying) * (1.0 + TAX) + 0.5) / 100.));

    return 0;
}