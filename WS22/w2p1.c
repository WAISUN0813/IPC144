/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  :WAI SUN LAM
Student ID#:146691225
Email      :wslam4@myseneca.ca
Section    :E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double small_Shirt, medium_Shirt, large_Shirt, subTotal, total, taxes;
    int quantity;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &small_Shirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &medium_Shirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &large_Shirt);

    printf("\nShirt Store Price List");
    printf("\n======================\n");
    printf("SMALL  : $%.2lf\n", small_Shirt);
    printf("MEDIUM : $%.2lf\n", medium_Shirt);
    printf("LARGE  : $%.2lf\n", large_Shirt);

    printf("\nPatty\'s shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &quantity);

    subTotal = quantity * small_Shirt;
    taxes = TAX * subTotal;
    total = subTotal + taxes;
    
    printf("\nPatty\'s shopping cart...\n");
    printf("Contains : %d shirts\n", quantity);
    double val = subTotal;
    int valE = (val + 0.005) * 100;
    printf("Sub-total: $%8.4lf\n", valE / 100.0);
    double val1 = taxes;
    int valE1 = (val1 + 0.005) * 100;
    printf("Taxes    : $%8.4lf\n", valE1 / 100.0);
    double val2 = total;
    int valE2 = (val2 + 0.005) * 100;
    printf("Total    : $%8.4lf\n", valE2 / 100.0);

    return 0;  
}