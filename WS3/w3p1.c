/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Section    : E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    int product1_ID = 111, product2_ID = 222, product3_ID = 111;
    char product1_Taxed ='Y', product2_Taxed = 'N', product3_Taxed = 'N';
    float product1_Price = 111.4900, product2_Price = 222.9900, product3_Price = 334.4900;
   
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", product1_ID);
    printf("  Taxed: %c\n", product1_Taxed);
    printf("  Price: $%.4f\n", product1_Price);

    printf("\nProduct-2 (ID:%d)\n", product2_ID);
    printf("  Taxed: %c\n", product2_Taxed);
    printf("  Price: $%.4f\n", product2_Price);

    printf("\nProduct-3 (ID:%d)\n", product3_ID);
    printf("  Taxed: %c\n", product3_Taxed);
    printf("  Price: $%.4f\n", product3_Price);

    float average_Price = (product1_Price + product2_Price + product3_Price) / 3;
    printf("\nThe average of all prices is: $%.4f\n", average_Price);
    

    printf("\nAbout Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");

    printf("\nSome Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", product1_Taxed == 'Y');
    printf("\n2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", product2_Taxed == 'N' && product3_Taxed == 'N');
    printf("\n3. Is product 3 less than testValue ($%.2f)? -> %d\n", testValue, product3_Price < testValue);
    printf("\n4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", product3_Price > (product1_Price + product2_Price));
    printf("\n5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n", product1_Price >= (product3_Price - product2_Price), product3_Price - product2_Price);
    printf("\n6. Is the price of product 2 equal to or more than the average price? -> %d\n", product2_Price >= average_Price);
    printf("\n7. Based on product ID, product 1 is unique -> %d\n", product1_ID != product2_ID && product1_ID != product3_ID);
    printf("\n8. Based on product ID, product 2 is unique -> %d\n", product2_ID != product1_ID && product2_ID != product3_ID);
    printf("\n9. Based on product ID, product 3 is unique -> %d\n", product3_ID != product1_ID && product3_ID != product2_ID);
   
    return 0;
}