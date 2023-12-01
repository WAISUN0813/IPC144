/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  :WaiSun Lam
Student ID#:146691225
Email      :wslam4@gmail.com
Section    :E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define maxitem 10
#define minitem 1
#include <stdio.h>

int main(void)
{
    int forecast, i, wants[4];
    const int maxNet = 400000.00, minNet = 500.00, minCost = 100.00;
    char financingOptions[3];
    double cost[10], income;

    printf("+--------------------------+\n+   Wish List Forecaster   |\n+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < minNet)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (income > maxNet)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }

    } while (income < minNet || income > maxNet);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &forecast);

        if (forecast < minitem || forecast > maxitem)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }

    } while (forecast < minitem || forecast > maxitem);

    for (i = 0; i < forecast; i++)
    {
        printf("\nItem-%d Details:", i + 1);


        do
        {
            printf("\n   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $100.00");
            }
        } while (cost[i] < minCost);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &wants[i]);
            if (wants[i] < 1 || wants[i]>3)

                printf("      ERROR: Value must be between 1 and 3\n");

        } while (wants[i] < 1 || wants[i]>3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financingOptions[i]);

            if (financingOptions[i] != 'y' && financingOptions[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        } while (financingOptions[i] != 'y' && financingOptions[i] != 'n');

    }
    
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    double sum = 0;
    
    for (i = 0; i < forecast; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, wants[i], financingOptions[i], cost[i]);
        sum += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sum);
    
    printf("Best of luck in all your future endeavours!\n\n");
    
    return 0;
}