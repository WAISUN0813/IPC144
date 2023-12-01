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
    int apples, oranges, pears, tomatoes, cabbages, pick, shopping;

    do
    {
		printf("Grocery Shopping\n================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }

        } while (apples < 0);

        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }

        } while (oranges < 0);

        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }

        } while (pears < 0);

        printf("\n");

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }

        } while (tomatoes < 0);

        printf("\n");

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }

        } while (cabbages < 0);

        printf("\n--------------------------\nTime to pick the products!\n--------------------------\n\n");

		while (apples > 0)
		{
			printf("Pick some APPLES... how many did you pick? : ");
			scanf("%d", &pick);
						
			if (pick > apples)
			{
				printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
			}
			else if (pick <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else 
			{
				apples = apples - pick;
				
				if (apples > 0)
				{
					printf("Looks like we still need some APPLES...\n");
				}
				else 
				{
					printf("Great, that's the apples done!\n\n");
				}
			}
		}

		while (oranges > 0)
		{
			printf("Pick some ORANGES... how many did you pick? : ");
			scanf("%d", &pick);
						
			if (pick > oranges)
			{
				printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
			}
			else if (pick <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else 
			{
				oranges = oranges - pick;
				
				if (oranges > 0)
				{
					printf("Looks like we still need some ORANGES...\n");
				}
				else 
				{
					printf("Great, that's the oranges done!\n\n");
				}
			}
		}

		while (pears > 0)
		{
			printf("Pick some PEARS... how many did you pick? : ");
			scanf("%d", &pick);
					
			if (pick > pears)
			{
				printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
			}
			else if (pick <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else 
			{
				pears = pears - pick;
				
				if (pears > 0)
				{
					printf("Looks like we still need some PEARS...\n");
				}
				else 
				{
					printf("Great, that's the pears done!\n\n");
				}
			}
		}

		while (tomatoes > 0)
		{
			printf("Pick some TOMATOES... how many did you pick? : ");
			scanf("%d", &pick);
			
			if (pick > tomatoes)
			{
				printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
			}
			else if (pick <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else 
			{
				tomatoes = tomatoes - pick;
				
				if (tomatoes > 0)
				{
					printf("Looks like we still need some TOMATOES...\n");
				}
				else 
				{
					printf("Great, that's the tomatoes done!\n\n");
				}
			}
		}

		while (cabbages > 0)
		{
			printf("Pick some CABBAGES... how many did you pick? : ");
			scanf("%d", &pick);
		
			if (pick > cabbages)
			{
				printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
			}
			else if (pick <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else 
			{
				cabbages = cabbages - pick;
				
				if (cabbages > 0)
				{
					printf("Looks like we still need some CABBAGES...\n");
				}
				else 
				{
					printf("Great, that's the cabbages done!\n\n");
				}
			}
		}

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shopping);
        printf("\n");

    }  while (!(shopping == 0));
		printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}