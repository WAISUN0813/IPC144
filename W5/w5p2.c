/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

#include <stdio.h>

int main(void)
{
    const int JAN = 1, DEC = 12;
    int YEAR, MONTH;
    double mrating, erating, totalMorningRating = 0, totalEveningRating = 0;
    
    printf("General Well-being Log\n======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d", &YEAR);
        scanf("%d", &MONTH);


        if (YEAR < MIN_YEAR || YEAR > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");

            if (MONTH < JAN || MONTH > DEC)
            {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }
        }

        else if (YEAR >= MIN_YEAR && YEAR <= MAX_YEAR)
        {
            if (MONTH < JAN || MONTH > DEC)
            {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }

        }
    } while (YEAR < MIN_YEAR || YEAR > MAX_YEAR || MONTH < JAN || MONTH > DEC);
    printf("\n*** Log date set! ***\n\n");

    int i;
    for (i = 1; i <= LOG_DAYS; i++)
    {
        if (MONTH == 1)
        {
            printf("%d-JAN-%02d\n", YEAR, i);
        }
        else if (MONTH == 2)
        {
            printf("%d-FEB-%02d\n", YEAR, i);
        }
        else if (MONTH == 3)
        {
            printf("%d-MAR-%02d\n", YEAR, i);
        }
        else if (MONTH == 4)
        {
            printf("%d-APR-%02d\n", YEAR, i);
        }
        else if (MONTH == 5)
        {
            printf("%d-MAY-%02d\n", YEAR, i);
        }
        else if (MONTH == 6)
        {
            printf("%d-JUN-%02d\n", YEAR, i);
        }
        else if (MONTH == 7)
        {
            printf("%d-JUL-%02d\n", YEAR, i);
        }
        else if (MONTH == 8)
        {
            printf("%d-AUG-%02d\n", YEAR, i);
        }
        else if (MONTH == 9)
        {
            printf("%d-SEP-%02d\n", YEAR, i);
        }
        else if (MONTH == 10)
        {
            printf("%d-OCT-%02d\n", YEAR, i);
        }
        else if (MONTH == 11)
        {
            printf("%d-NOV-%02d\n", YEAR, i);
        }
        else if (MONTH == 12)
        {
            printf("%d-DEC-%02d\n", YEAR, i);
        }

        do

        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &mrating);

            if (mrating < 0.0 || mrating> 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (mrating < 0.0 || mrating > 5.0);
        totalMorningRating += mrating;
 
        do

        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &erating);

            if (erating < 0.0 || erating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (erating < 0.0 || erating > 5.0);
        totalEveningRating += erating;
        printf("\n");
    }
    
    printf("Summary\n=======\n");
    printf("Morning total rating: %.3lf\n", totalMorningRating);
    printf("Evening total rating:  %.3lf\n", totalEveningRating);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", totalMorningRating + totalEveningRating);

    printf("\nAverage morning rating:  %.1f\n", totalMorningRating / LOG_DAYS);
    printf("Average evening rating:  %.1f\n", totalEveningRating / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1f\n", ((totalMorningRating / LOG_DAYS) + (totalEveningRating / LOG_DAYS)) / 2);
     
    return 0;
}