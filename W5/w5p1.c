/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#include <stdio.h>

int main(void)
{
    const int JAN = 1, DEC = 12;
    int YEAR, MONTH;

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

    if (MONTH == 1)
    {
        
        printf("Log starting date: %d-JAN-01\n", YEAR);
    }
    else if (MONTH == 2)
    {
        
        printf("Log starting date: %d-FEB-01\n", YEAR);
    }
    else if (MONTH == 3)
    {
        
        printf("Log starting date: %d-MAR-01\n", YEAR);
    }
    else if (MONTH == 4)
    {
        
        printf("Log starting date: %d-APR-01\n", YEAR);
    }
    else if (MONTH == 5)
    {
        
        printf("Log starting date: %d-MAY-01\n", YEAR);
    }
    else if (MONTH == 6)
    {
        
        printf("Log starting date: %d-JUN-01\n", YEAR);
    }
    else if (MONTH == 7)
    {
        
        printf("Log starting date: %d-JUL-01\n", YEAR);
    }
    else if (MONTH == 8)
    {
        
        printf("Log starting date: %d-AUG-01\n", YEAR);
    }
    else if (MONTH == 9)
    {
        
        printf("Log starting date: %d-SEP-01\n", YEAR);
    }
    else if (MONTH == 10)
    {
       
        printf("Log starting date: %d-OCT-01\n", YEAR);
    }
    else if (MONTH == 11)
    {
        
        printf("Log starting date: %d-NOV-01\n", YEAR);
    }
    else if (MONTH == 12)
    {
        printf("Log starting date: %d-DEC-01\n", YEAR);
    }

    return 0;
}

 