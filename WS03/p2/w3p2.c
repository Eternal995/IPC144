/*
*****************************************************************************
                          Workshop - #3 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    int price_S_1, price_S_2, price_M_1, price_M_2, price_L_1, price_L_2, Num_buying_Pat, Num_buying_Sal, Num_buying_Tom, Balance_penny, Qty;
    double Subtotal, Tax, Total, Subtotal_Sum = 0.0, Tax_Sum=0.0, Total_Sum=0.0, Balance;

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
    scanf("%d%*c", &Num_buying_Pat);
    printf("\nTommy's shirt size is \'%c\'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d%*c", &Num_buying_Tom);
    printf("\nSally's shirt size is \'%c\'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d%*c", &Num_buying_Sal);

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    Subtotal = (int)(((price_S_1 * 100 + price_S_2) * Num_buying_Pat) + 0.5) / 100.;
    Tax = ((int)(((price_S_1 * 100 + price_S_2) * Num_buying_Pat) * TAX + 0.5) / 100.);
    Total = ((int)(((price_S_1 * 100 + price_S_2) * Num_buying_Pat) * (1.0 + TAX) + 0.5) / 100.);
    Subtotal_Sum += Subtotal;
    Tax_Sum += Tax;
    Total_Sum += Total;
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, price_S_1 + price_S_2 / 100., Num_buying_Pat, Subtotal, Tax, Total);
    Subtotal = (int)(((price_M_1 * 100 + price_M_2) * Num_buying_Sal) + 0.5) / 100.;
    Tax = ((int)(((price_M_1 * 100 + price_M_2) * Num_buying_Sal) * TAX + 0.5) / 100.);
    Total = ((int)(((price_M_1 * 100 + price_M_2) * Num_buying_Sal) * (1.0 + TAX) + 0.5) / 100.);
    Subtotal_Sum += Subtotal;
    Tax_Sum += Tax;
    Total_Sum += Total;
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, price_M_1 + price_M_2 / 100., Num_buying_Sal, Subtotal, Tax, Total);
    Subtotal = (int)(((price_L_1 * 100 + price_L_2) * Num_buying_Tom) + 0.5) / 100.;
    Tax = ((int)(((price_L_1 * 100 + price_L_2) * Num_buying_Tom) * TAX + 0.5) / 100.);
    Total = ((int)(((price_L_1 * 100 + price_L_2) * Num_buying_Tom) * (1.0 + TAX) + 0.5) / 100.);
    Subtotal_Sum += Subtotal;
    Tax_Sum += Tax;
    Total_Sum += Total;
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, price_L_1 + price_L_2 / 100., Num_buying_Tom, Subtotal, Tax, Total);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", Subtotal_Sum, Tax_Sum, Total_Sum);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", Subtotal_Sum);
    Balance_penny = (int)(Subtotal_Sum * 100 + 0.5);
    Qty = Balance_penny / 200;
    Balance = (Balance_penny % 200) / 100.;
    printf("Toonies  %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 100;
    Balance = (Balance_penny % 100) / 100.;
    printf("Loonies  %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 25;
    Balance = (Balance_penny % 25) / 100.;
    printf("Quarters %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 10;
    Balance = (Balance_penny % 10) / 100.;
    printf("Dimes    %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 5;
    Balance = (Balance_penny % 5) / 100.;
    printf("Nickels  %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 1;
    Balance = (Balance_penny % 1) / 100.;
    printf("Pennies  %3d %9.4lf\n\n", Qty, Balance);
    printf("Average cost/shirt: $%.4lf\n\n", Subtotal_Sum / (Num_buying_Pat + Num_buying_Sal + Num_buying_Tom));
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", Total_Sum);
    Balance_penny = (int)(Total_Sum * 100 + 0.5);
    Qty = Balance_penny / 200;
    Balance = (Balance_penny % 200) / 100.;
    printf("Toonies  %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 100;
    Balance = (Balance_penny % 100) / 100.;
    printf("Loonies  %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 25;
    Balance = (Balance_penny % 25) / 100.;
    printf("Quarters %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 10;
    Balance = (Balance_penny % 10) / 100.;
    printf("Dimes    %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 5;
    Balance = (Balance_penny % 5) / 100.;
    printf("Nickels  %3d %9.4lf\n", Qty, Balance);
    Balance_penny = (int)(Balance * 100 + 0.5);
    Qty = Balance_penny / 1;
    Balance = (Balance_penny % 1) / 100.;
    printf("Pennies  %3d %9.4lf\n\n", Qty, Balance);
    printf("Average cost/shirt: $%.4lf\n", Total_Sum / (Num_buying_Pat + Num_buying_Sal + Num_buying_Tom));

    return 0;
}