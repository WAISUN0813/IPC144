/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  :Wai Sun Lam
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffee_Type1;
    int coffee_Package_Weight1;
    char suggest_Serving_with_Cream1;
    char coffee_Type2;
    int coffee_Package_Weight2;
    char suggest_Serving_with_Cream2;
    char coffee_Type3;
    int coffee_Package_Weight3;
    char suggest_Serving_with_Cream3;
    char coffee_Strength;
    int daily_Servings;
    char like_Cream_with_Coffee;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\nEnter the coffee product information being sold today...\n");
    printf("\nCOFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee_Type1);
    printf("Bag weight (g): ");
    scanf("%d", &coffee_Package_Weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &suggest_Serving_with_Cream1);
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee_Type2);
    printf("Bag weight (g): ");
    scanf("%d", &coffee_Package_Weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &suggest_Serving_with_Cream2);
    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee_Type3);
    printf("Bag weight (g): ");
    scanf("%d", &coffee_Package_Weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &suggest_Serving_with_Cream3);

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffee_Type1 == 'l' || coffee_Type1 == 'L'), (coffee_Type1 == 'M' || coffee_Type1 == 'm'), (coffee_Type1 == 'R' || coffee_Type1 == 'r'), coffee_Package_Weight1, (coffee_Package_Weight1 / GRAMS_IN_LBS), (suggest_Serving_with_Cream1 == 'y' || suggest_Serving_with_Cream1 == 'Y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffee_Type2 == 'l' || coffee_Type2 == 'L'), (coffee_Type2 == 'M' || coffee_Type2 == 'm'), (coffee_Type2 == 'R' || coffee_Type2 == 'r'), coffee_Package_Weight2, (coffee_Package_Weight2 / GRAMS_IN_LBS), !(suggest_Serving_with_Cream2 == 'N' || suggest_Serving_with_Cream2 == 'n'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffee_Type3 == 'l' || coffee_Type3 == 'L'), (coffee_Type3 == 'M' || coffee_Type3 == 'm'), (coffee_Type3 == 'R' || coffee_Type3 == 'r'), coffee_Package_Weight3, (coffee_Package_Weight3 / GRAMS_IN_LBS), !(suggest_Serving_with_Cream3 == 'N' || suggest_Serving_with_Cream3 == 'n'));

    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffee_Strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &like_Cream_with_Coffee);
    printf("Typical number of daily servings: ");
    scanf("%d", &daily_Servings);

    printf("\nThe below table shows how your preferences align to the available products:\n");
    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (coffee_Strength == 'l' || coffee_Strength == 'L'), (daily_Servings >= 1 && daily_Servings <= 4), (like_Cream_with_Coffee == 'Y' || like_Cream_with_Coffee == 'y'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (coffee_Strength == 'R' || coffee_Strength == 'r'), (daily_Servings >= 5 && daily_Servings <= 9), (like_Cream_with_Coffee == 'N' || like_Cream_with_Coffee == 'n'));
    printf(" 3|       %d         |      %d      |   %d   |\n", (coffee_Strength == 'M' || coffee_Strength == 'm'), (daily_Servings >= 10), (like_Cream_with_Coffee == 'N' || like_Cream_with_Coffee == 'n'));

    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffee_Strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &like_Cream_with_Coffee);
    printf("Typical number of daily servings: ");
    scanf("%d", &daily_Servings);
    
    printf("\nThe below table shows how your preferences align to the available products:\n");
    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (coffee_Strength == 'l' || coffee_Strength == 'L'), (daily_Servings >= 1 && daily_Servings <= 4), (like_Cream_with_Coffee == 'Y' || like_Cream_with_Coffee == 'y'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (coffee_Strength == 'R' || coffee_Strength == 'r'), (daily_Servings >= 5 && daily_Servings <= 9), (like_Cream_with_Coffee == 'N' || like_Cream_with_Coffee == 'n'));
    printf(" 3|       %d         |      %d      |   %d   |\n", (coffee_Strength == 'M' || coffee_Strength == 'm'), (daily_Servings >= 10), (like_Cream_with_Coffee == 'N' || like_Cream_with_Coffee == 'n'));
    
    printf("\nHope you found a product that suits your likes!\n");
   
    return 0;

}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",
*/