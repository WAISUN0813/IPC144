/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
    int forecast, i, wants[10], menu,  priority;
    const int maxNet = 400000.00, minNet = 500.00, minCost = 100.00;
    char financingOptions[10];
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
    printf("                      $%11.2lf\n", sum);
    
    sum = 0;
    int financeSelected = 0;
    do
    {
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &menu);
        if (menu == 1)
        {
            financeSelected = 0;

            for (i = 0; i < forecast; i++)
            {
                sum += cost[i];
                if (financingOptions[i] == 'y')
                    financeSelected = 1;
            }
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf", sum);
            printf("\nForecast: %d years, %d months\n", (int)sum / (int)income / 12, ((int)sum / (int)income % 12) + 1);
            if (financeSelected == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");
        }

        else if (menu == 2)
        {
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &priority);
            do
            {
                if (priority < 1 || priority >3)
                {
                    printf("\n ERROR: Value must be between 1 and 3");
                }
            } while (priority < 1 || priority >3);

            sum = 0;
            financeSelected = 0;
            for (i = 0; i < forecast; i++)
            {
                if (wants[i] == priority)
                {
                    sum = sum + cost[i];
                    if (financingOptions[i] == 'y')
                        financeSelected = 1;
                }
            }
            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", priority);
            printf("Amount:   $%1.2lf", sum);
            printf("\nForecast: %d years, %d months\n", (int)sum / (int)income / 12, ((int)sum / (int)income % 12) + 1);
            if (financeSelected == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");
        }

        else if (menu == 0)
        {
            printf("\nBest of luck in all your future endeavours!\n");          
        }
        else
        {
            printf("\nERROR: Invalid menu selection.\n");
        }
             

    } while (!(menu == 0));

    return 0;
}