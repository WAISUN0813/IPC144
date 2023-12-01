/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  :WaiSun Lam
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

int main()
{
    int i;
    int iterations;
    char loopType;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+");

    do
    {
        printf("\n\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &iterations);

        if (loopType == 'D' || loopType == 'W' || loopType == 'F')
        {
            if (iterations < 3 || iterations > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
            else
            {
                if (loopType == 'D')
                {
                    i = 0;
                    printf("DO-WHILE: ");
                    do
                    {
                        printf("%c", loopType);
                        i++;
                    } while (i < iterations);
                }
                else if (loopType == 'W')
                {
                    i = 0;
                    printf("WHILE   : ");
                    while (i < iterations)
                    {
                        printf("%c", loopType);
                        i++;
                    }
                }
                else
                {
                    printf("FOR     : ");
                    for (i = 0; i < iterations; i++)
                    {
                        printf("%c", loopType);
                    }
                }
            }
        }
        if (loopType == 'Q' && iterations == 0)
        {
            printf("\n+--------------------+\n");
            printf("Loop application ENDED\n");
            printf("+--------------------+\n");
        }
        if (loopType == 'Q' && iterations != 0)
        {        
            printf("ERROR: To quit, the number of iterations should be 0!");
         
        }
        else if (loopType != 'D' && loopType != 'W' && loopType != 'F' && loopType !='Q')
        {
            printf("ERROR: Invalid entered value(s)!");
        }
    } while (!(loopType == 'Q' && iterations == 0));

    return 0;
}