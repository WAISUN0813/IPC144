/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
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

void inputCString(char* str, int minLen, int maxLen) {
    int len;
    char ch[30];
    int i;
    do {
        len = 0;
        scanf("%29[^\n]", ch);
        clearInputBuffer();

        while (ch[len] != '\0') {
            len++;
        }

        if (minLen == maxLen && len != minLen) {
            printf("ERROR: String length must be exactly %d chars: ", minLen);
        }
        else if (len > maxLen) {
            printf("ERROR: String length must be no more than %d chars: ", maxLen);
        }
        else if (len < minLen) {
            printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
        }
        else {
            for (i = 0; i < len; i++) {
                str[i] = ch[i];
            }
            str[len] = '\0';
            return;
        }

    } while (len < minLen || len > maxLen);
}

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