/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double small_Shirt, medium_Shirt, large_Shirt;
    int pat_quantity, sal_quantity, tom_quantity;
    double pat_Total, sal_Total, tom_Total;
    double pat_Subtotal, sal_Subtotal, tom_Subtotal;
    double pat_Taxes, sal_Taxes, tom_Taxes;
    double sub_Total, taxes, total;
    double balance;

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
    scanf("%d", &pat_quantity);
    printf("\nTommy\'s shirt size is \'%c\'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tom_quantity);
    printf("\nSally\'s shirt size is \'%c\'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &sal_quantity);

    pat_Subtotal = pat_quantity * small_Shirt;
    sal_Subtotal = sal_quantity * medium_Shirt;
    tom_Subtotal = tom_quantity * large_Shirt;

    pat_Taxes = TAX * pat_Subtotal;
    sal_Taxes = TAX * sal_Subtotal;
    tom_Taxes = TAX * tom_Subtotal;

    pat_Total = pat_Subtotal + pat_Taxes;
    sal_Total = sal_Subtotal + sal_Taxes;
    tom_Total = tom_Subtotal + tom_Taxes;

    sub_Total = pat_Subtotal + sal_Subtotal + tom_Subtotal;
    taxes = pat_Taxes + sal_Taxes + tom_Taxes;
    total = pat_Total + sal_Total + tom_Total;

    double pat_Taxes1 = pat_Taxes;
    int pat_Taxes1E = (pat_Taxes1 + 0.005) * 100;

    double sal_Taxes1 = sal_Taxes;
    int sal_Taxes1E = (sal_Taxes1 + 0.005) * 100;

    double tom_Taxes1 = tom_Taxes;
    int tom_Taxes1E = (tom_Taxes1 + 0.005) * 100;

    double pat_Total1 = pat_Total;
    int pat_Total1E = (pat_Total1 + 0.005) * 100;

    double sal_Total1 = sal_Total;
    int sal_Total1E = (sal_Total1 + 0.005) * 100;

    double tom_Total1 = tom_Total;
    int tom_Total1E = (tom_Total1 + 0.005) * 100;

    double taxes1 = taxes;
    int taxes1E = (taxes1 + 0.005) * 100;

    double total1 = total;
    int total1E = (total1 + 0.005) * 100;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, small_Shirt, pat_quantity, pat_Subtotal, pat_Taxes1E / 100.0, pat_Total1E / 100.0);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, medium_Shirt, sal_quantity, sal_Subtotal, sal_Taxes1E / 100.0, sal_Total1E / 100.0);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, large_Shirt, tom_quantity, tom_Subtotal, tom_Taxes1E / 100.0, tom_Total1E / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n", sub_Total, taxes1E / 100.0, total1E / 100.0);

    balance = sub_Total;
    printf("\nDaily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\nSales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", balance);

    double cost = balance;
    int costModt = cost * 100;
    int tonnies = costModt / 200;
    int leftOvert = costModt % 200;
    printf("Toonies  %3d %9.4lf\n", tonnies, leftOvert / 100.0);

    int costModl = (leftOvert / 100.0) * 100;
    int lonnies = costModl / 100;
    int leftOverl = costModl % 100;
    printf("Loonies  %3d %9.4lf\n", lonnies, leftOverl / 100.0);

    int costModq = (leftOverl / 100.0) * 100;
    int quarters = costModq / 25;
    int leftOverq = costModq % 25;
    printf("Quarters %3d %9.4lf\n", quarters, leftOverq / 100.0);

    int costModd = (leftOverq / 100.0) * 100;
    int dimes = costModd / 10;
    int leftOverd = costModd % 10;
    printf("Dimes    %3d %9.4lf\n", dimes, leftOverd / 100.0);

    int costModn = (leftOverd / 100.0) * 100;
    int nickels = costModn / 5;
    int leftOvern = costModn % 5;
    printf("Nickels  %3d %9.4lf\n", nickels, leftOvern / 100.0);

    int costModp = (leftOvern / 100.0) * 100;
    int pennies = costModp / 1;
    int leftOverp = costModp % 1;
    printf("Pennies  %3d %9.4lf\n", pennies, leftOverp / 100.0);

    double averCost = sub_Total / (pat_quantity + sal_quantity + tom_quantity);
    printf("\nAverage cost/shirt: $%0.4lf\n", averCost);

    balance = total1E / 100.0;
    printf("\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", balance);

    double cost1 = balance;
    int costModt1 = cost1 * 100;
    int tonnies1 = costModt1 / 200;
    int leftOvert1 = costModt1 % 200;
    printf("Toonies  %3d %9.4lf\n", tonnies1, leftOvert1 / 100.0);

    int costModl1 = (leftOvert1 / 100.0) * 100;
    int lonnies1 = costModl1 / 100;
    int leftOverl1 = costModl1 % 100;
    printf("Loonies  %3d %9.4lf\n", lonnies1, leftOverl1 / 100.0);

    int costModq1 = 0.5800 * 100;
    int quarters1 = costModq1 / 25;
    int leftOverq1 = costModq1 % 25;
    printf("Quarters %3d %9.4lf\n", quarters1, leftOverq1 / 100.0);

    int costModd1 = (leftOverq1 / 100.0) * 100;
    int dimes1 = costModd1 / 10;
    int leftOverd1 = costModd1 % 10;
    printf("Dimes    %3d %9.4lf\n", dimes1, leftOverd1 / 100.0);

    int costModn1 = (leftOverd1 / 100.0) * 100;
    int nickels1 = costModn1 / 5;
    int leftOvern1 = costModn1 % 5;
    printf("Nickels  %3d %9.4lf\n", nickels1, leftOvern1 / 100.0);

    int costModp1 = (leftOvern1 / 100.0) * 100;
    int pennies1 = costModp1 / 1;
    int leftOverp1 = costModp1 % 1;
    printf("Pennies  %3d %9.4lf\n", pennies1, leftOverp1 / 100.0);

    double averCost1 = (total1E / 100.0) / (pat_quantity + sal_quantity + tom_quantity);
    printf("\nAverage cost/shirt: $%0.4lf\n", averCost1);

    return 0;
}