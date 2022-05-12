/*
*****************************************************************************
                          Workshop - #2 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    char type1, type2, type3, gsize1, gsize2, gsize3, cream1, cream2, cream3;
    int weight1, weight2, weight3;
    double temp1, temp2, temp3;

    char strength, cream, maker;
    int serving;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf("%c%*c", &type1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf("%c%*c", &gsize1);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream1);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf%*c", &temp1);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf("%c%*c", &type2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf("%c%*c", &gsize2);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream2);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf%*c", &temp2);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf("%c%*c", &type3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf("%c%*c", &gsize3);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream3);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf%*c", &temp3);

    printf("\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
        type1 == 'l' || type1 == 'L', type1 == 'b' || type1 == 'B', gsize1 == 'c' || gsize1 == 'C', gsize1 == 'f' || gsize1 == 'F', 
        weight1, weight1 / GRAMS_IN_LBS, cream1 == 'y' || cream1 == 'Y', temp1, temp1 * 9. / 5. + 32.);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
        type2 == 'l' || type2 == 'L', type2 == 'b' || type2 == 'B', gsize2 == 'c' || gsize2 == 'C', gsize2 == 'f' || gsize2 == 'F', 
        weight2, weight2 / GRAMS_IN_LBS, cream2 == 'y' || cream2 == 'Y', temp2, temp2 * 9. / 5. + 32.);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
        type3 == 'l' || type3 == 'L', type3 == 'b' || type3 == 'B', gsize3 == 'c' || gsize3 == 'C', gsize3 == 'f' || gsize3 == 'F', 
        weight3, weight3 / GRAMS_IN_LBS, cream3 == 'y' || cream3 == 'Y', temp3, temp3 * 9. / 5. + 32.);
    printf("\n");

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf("%c%*c", &strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream);
    printf("Typical number of daily servings: ");
    scanf("%d%*c", &serving);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf("%c%*c", &maker);

    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((strength == 'm' || strength == 'M') && (type1 == 'l' || type1 == 'L')) || ((strength == 'r' || strength == 'R') && (type1 == 'b' || type1 == 'B')),
        ((maker == 'r' || maker == 'R') && (gsize1 == 'c' || gsize1 == 'C')) || ((maker == 'c' || maker == 'C') && (gsize1 == 'f' || gsize1 == 'F')),
        ((serving >= 1 && serving <= 4) && (weight1 <= 250)) || ((serving >= 5 && serving <= 9) && (weight1 == 500)) || (serving >= 10 && weight1 == 1000),
        ((cream == 'y' || cream == 'Y') && (cream1 == 'y' || cream1 == 'Y')) || ((cream == 'n' || cream == 'N') && (cream1 == 'n' || cream1 == 'N')),
        ((maker == 'r' || maker == 'R') && ((temp1 <= 69.9) && (temp1 >= 60.0))) || ((maker == 'c' || maker == 'C') && (temp1 >= 70.0)));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((strength == 'm' || strength == 'M') && (type2 == 'l' || type2 == 'L')) || ((strength == 'r' || strength == 'R') && (type2 == 'b' || type2 == 'B')),
        ((maker == 'r' || maker == 'R') && (gsize2 == 'c' || gsize2 == 'C')) || ((maker == 'c' || maker == 'C') && (gsize2 == 'f' || gsize2 == 'F')),
        ((serving >= 1 && serving <= 4) && (weight2 <= 250)) || ((serving >= 5 && serving <= 9) && (weight2 == 500)) || (serving >= 10 && weight2 == 1000),
        ((cream == 'y' || cream == 'Y') && (cream2 == 'y' || cream2 == 'Y')) || ((cream == 'n' || cream == 'N') && (cream2 == 'n' || cream2 == 'N')),
        ((maker == 'r' || maker == 'R') && ((temp2 <= 69.9) && (temp2 >= 60.0))) || ((maker == 'c' || maker == 'C') && (temp2 >= 70.0)));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((strength == 'm' || strength == 'M') && (type3 == 'l' || type3 == 'L')) || ((strength == 'r' || strength == 'R') && (type3 == 'b' || type3 == 'B')),
        ((maker == 'r' || maker == 'R') && (gsize3 == 'c' || gsize3 == 'C')) || ((maker == 'c' || maker == 'C') && (gsize3 == 'f' || gsize3 == 'F')),
        ((serving >= 1 && serving <= 4) && (weight3 <= 250)) || ((serving >= 5 && serving <= 9) && (weight3 == 500)) || (serving >= 10 && weight3 == 1000),
        ((cream == 'y' || cream == 'Y') && (cream3 == 'y' || cream3 == 'Y')) || ((cream == 'n' || cream == 'N') && (cream3 == 'n' || cream3 == 'N')),
        ((maker == 'r' || maker == 'R') && ((temp3 <= 69.9) && (temp3 >= 60.0))) || ((maker == 'c' || maker == 'C') && (temp3 >= 70.0)));

    printf("\n");
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf("%c%*c", &strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream);
    printf("Typical number of daily servings: ");
    scanf("%d%*c", &serving);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf("%c%*c", &maker);

    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((strength == 'm' || strength == 'M') && (type1 == 'l' || type1 == 'L')) || ((strength == 'r' || strength == 'R') && (type1 == 'b' || type1 == 'B')),
        ((maker == 'r' || maker == 'R') && (gsize1 == 'c' || gsize1 == 'C')) || ((maker == 'c' || maker == 'C') && (gsize1 == 'f' || gsize1 == 'F')),
        ((serving >= 1 && serving <= 4) && (weight1 <= 250)) || ((serving >= 5 && serving <= 9) && (weight1 == 500)) || (serving >= 10 && weight1 == 1000),
        ((cream == 'y' || cream == 'Y') && (cream1 == 'y' || cream1 == 'Y')) || ((cream == 'n' || cream == 'N') && (cream1 == 'n' || cream1 == 'N')),
        ((maker == 'r' || maker == 'R') && ((temp1 <= 69.9) && (temp1 >= 60.0))) || ((maker == 'c' || maker == 'C') && (temp1 >= 70.0)));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((strength == 'm' || strength == 'M') && (type2 == 'l' || type2 == 'L')) || ((strength == 'r' || strength == 'R') && (type2 == 'b' || type2 == 'B')),
        ((maker == 'r' || maker == 'R') && (gsize2 == 'c' || gsize2 == 'C')) || ((maker == 'c' || maker == 'C') && (gsize2 == 'f' || gsize2 == 'F')),
        ((serving >= 1 && serving <= 4) && (weight2 <= 250)) || ((serving >= 5 && serving <= 9) && (weight2 == 500)) || (serving >= 10 && weight2 == 1000),
        ((cream == 'y' || cream == 'Y') && (cream2 == 'y' || cream2 == 'Y')) || ((cream == 'n' || cream == 'N') && (cream2 == 'n' || cream2 == 'N')),
        ((maker == 'r' || maker == 'R') && ((temp2 <= 69.9) && (temp2 >= 60.0))) || ((maker == 'c' || maker == 'C') && (temp2 >= 70.0)));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((strength == 'm' || strength == 'M') && (type3 == 'l' || type3 == 'L')) || ((strength == 'r' || strength == 'R') && (type3 == 'b' || type3 == 'B')),
        ((maker == 'r' || maker == 'R') && (gsize3 == 'c' || gsize3 == 'C')) || ((maker == 'c' || maker == 'C') && (gsize3 == 'f' || gsize3 == 'F')),
        ((serving >= 1 && serving <= 4) && (weight3 <= 250)) || ((serving >= 5 && serving <= 9) && (weight3 == 500)) || (serving >= 10 && weight3 == 1000),
        ((cream == 'y' || cream == 'Y') && (cream3 == 'y' || cream3 == 'Y')) || ((cream == 'n' || cream == 'N') && (cream3 == 'n' || cream3 == 'N')),
        ((maker == 'r' || maker == 'R') && ((temp3 <= 69.9) && (temp3 >= 60.0))) || ((maker == 'c' || maker == 'C') && (temp3 >= 70.0)));

    printf("\n");
    printf("Hope you found a product that suits your likes!\n");

    return 0;
}
