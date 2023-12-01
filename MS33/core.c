/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

#include "core.h"

#include <ctype.h>
//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
int inputInt(void)
{
    int number;
    char c;
    do
    {
        scanf("%d%c", &number, &c);

        if (c != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    } while (c != '\n');

    return number;
}

int inputIntPositive(void)
{
    int number;
    char c;
    do
    {
        scanf("%d%c", &number, &c);

        if (c != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a number:  ");
        }

        else if (number <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }

    } while (number <= 0);

    return number;
}

int inputIntRange(int lowerBound, int upperBound)
{
    char c = ' ';
    int value;

    do
    {
        scanf("%d%c", &value, &c);

        if (c != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (value < lowerBound || value > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }

    } while (value < lowerBound || value > upperBound || c != '\n');

    return value;
}


char inputCharOption(char str[])
{
    int i;
    int count = 0;
    char value;

    do {
        scanf(" %c", &value);

        for (i = 0; str[i] != '\0' && count == 0; i++) {
            if (str[i] == value) {
                count++;
            }
        }

        if (count == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", str);
        }

    } while (count == 0);

    clearInputBuffer();

    return value;
}

/*void inputCString(char* str, int minLen, int maxLen)
{
    int len;
    int ch;
    do {
        len = 0; 
        printf("Enter a string of length between %d and %d characters: ", minLen, maxLen);

        while ((ch = getchar()) != '\n' && len <= maxLen) 
        {
            str[len++] = ch;
        }

        if (ch == '\n' && len <= (maxLen + 1)) 
        {
            len--;
            str[len] = '\0';
        }
 
        else 
        {
            str[maxLen] = '\0';
            clearInputBuffer();
        }

        if (minLen == maxLen && len != minLen) 
        {
            printf("ERROR: String length must be exactly %d chars: ", minLen);
        }
        else if (len < minLen || len > maxLen) 
        {
            if (len > maxLen) 
            {
                printf("ERROR: String length must be no more than %d chars: ", maxLen);
            }
            else if (len < minLen) 
            {
                printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
            }
        }
    } while (len < minLen || len > maxLen);
}
*/
void inputCString(char* str, int minLen, int maxLen) 
{
    int flag = 1;
    char ch = 'a';

    while (flag) 
    {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxLen) 
        {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxLen + 1)) 
        {
            len--;
            str[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maxLen] = '\0';
            clearInputBuffer();
        }

        if (minLen == maxLen && len != minLen) 
        {
            printf("Invalid 10-digit number! Number: ");
            ch = 'a';
        }
        else if (len < minLen || len > maxLen) 
        {
            if (len > maxLen) 
            {
                printf("ERROR: String length must be no more than %d chars: ", maxLen);
                ch = 'a';
            }
            else if (len < minLen) 
            {
                printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
                ch = 'a';
            }
        }
        else 
        {
            flag = 0;
        }
    }
}
/*void inputCString(char* str, int minLen, int maxLen) {
    int len = 0;
    char ch[30];
    int i;
    do {
        scanf("%[^\n]", ch);
        clearInputBuffer();
        len = strlen(ch);

        if (minLen == maxLen && len != minLen) 
        {
            printf("ERROR: String length must be exactly %d chars: ", minLen);
        }
        else if (len > maxLen) 
        {
            printf("ERROR: String length must be no more than %d chars: ", maxLen);
        }
        else if (len < minLen) 
        {
            printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
        }
        else 
        {
            strcpy(str, len);
        }

    } while (len < minLen || len > maxLen);
}
*/
void displayFormattedPhone(const char* str)
{
    int len = 0, i;
    int isValid = 1;

    while (str != NULL && str[len])
    {
        if (!isdigit(str[len]))
        {
            isValid = 0;
        }
        len++;
    }

    if (len != 10 || !isValid)
    {
        printf("(___)___-____");
    }
    else
    {
        i = 0;
        printf("(");
        while (i < 3)
        {
            printf("%c", str[i]);
            i++;
        }
        printf(")");
        while (i < 6)
        {
            printf("%c", str[i]);
            i++;
        }
        printf("-");
        while (i < 10)
        {
            printf("%c", str[i]);
            i++;
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////