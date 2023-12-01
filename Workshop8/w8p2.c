/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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
#include "w8p2.h"

// System Libraries


// User-Defined Libraries


// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
	int value;
	do {
		scanf("%d", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);

	if (number != NULL)
		*number = value;
	return value;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number)
{
	double value;
	do {
		scanf("%lf", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);

	if (number != NULL)
		*number = value;
	return value;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void)
{
	printf("Cat Food Cost Analysis");
	printf("\n======================\n");
	printf("\nEnter the details for %d dry food bags of product data for analysis.", max_Product);
	printf("\nNOTE: A 'serving' is %dg\n", num_Grams);
}

// 4. Get user input for the details of cat food product
double getCatFoodInfo(int* sku, double* price, double* lbs, int* cal_Serv, int s_num)
{
	printf("\nCat Food Product #%d", s_num);
	printf("\n--------------------\n");
	printf("SKU           : ");
	*sku = getIntPositive(NULL);
	printf("PRICE         : $");
	*price = getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");
	*lbs = getDoublePositive(NULL);
	printf("CALORIES/SERV.: ");
	*cal_Serv = getIntPositive(NULL);

	return 0;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodDate(int sku, double* price, double*
	lbs, int calServ)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *lbs, calServ);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg)
{
	double value; 
	value = *lbs / lbs_To_Kg;
	
	if (kg != NULL)  
		*kg = value;
	return value;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* g)
{
	int value;
	value = convertLbsKg(lbs, 0) * 1000;
	
	if (g != NULL)
		*g = value;
	return value;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kg, int* g)
{
	double value = convertLbsKg(lbs, kg); 
	int value1 = convertLbsG(lbs, g);
	*kg = value;
	*g = value1;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int size_Gram, const int total_Grams, double* serving_result)
{
	double value; 
	value = (double)total_Grams / (double)size_Gram;
	
	if (serving_result != NULL)
		*serving_result = value;
	return value;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* total_Servings, double* cost_Serving_Result)
{
	double value; 
	value = *price / *total_Servings;
	
	if (cost_Serving_Result != NULL)
		*cost_Serving_Result = value;
	return value;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* total_Calories, double* Cost_Calories_Result)
{
	double value;
	value = *price / *total_Calories;
	
	if (Cost_Calories_Result != NULL)
		*Cost_Calories_Result = value;
	return value;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo data)
{
	struct ReportData reportData;
	double total_calorie;
	reportData.sku = data.sku;
	reportData.price = data.price;
	reportData.lbs = data.lbs;
	reportData.cal_Serv = data.cal_Serv;
	reportData.kg = convertLbsKg(&data.lbs, &reportData.kg);
	reportData.g = convertLbsG(&data.lbs, &reportData.kg);
	reportData.total_Servings = calculateServings(num_Grams, reportData.g, &reportData.total_Servings);
	reportData.cost_Per_Serving = calculateCostPerServing(&reportData.price, &reportData.total_Servings, &reportData.cost_Per_Serving);
	total_calorie = reportData.cal_Serv * reportData.total_Servings;
	reportData.cost_Of_Calories_Per_Serving = calculateCostPerCal(&reportData.price, &total_calorie, &reportData.cost_Of_Calories_Per_Serving);

	return reportData;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\n");
	printf("Analysis Report (Note: Serving = %dg\n", num_Grams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportData.sku, reportData.price, reportData.lbs, reportData.kg, reportData.g, reportData.cal_Serv, reportData.total_Servings, reportData.cost_Per_Serving, reportData.cost_Of_Calories_Per_Serving);
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest)
{
	printf("\n"); 
	printf("Final Analysis\n"); 
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", cheapest.sku, cheapest.price); 
	printf("\nHappy shopping!\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo data[max_Product];
	int i, cheapt;
	int cheaptPrice = 10000000;
	openingMessage();

	for (i = 0; i < max_Product; i++)
	{
		getCatFoodInfo(&data[i].sku, &data[i].price, &data[i].
			lbs, &data[i].cal_Serv, i + 1);
	}

	printf("\n");

	displayCatFoodHeader();

	for (i = 0; i < max_Product; i++)
	{
		displayCatFoodDate(data[i].sku, &data[i].price, &data[i].
			lbs, data[i].cal_Serv);
	}

	struct ReportData report[max_Product]; 

	for (i = 0; i < max_Product; i++)
	{
		report[i] = calculateReportData(data[i]);
		if (report[i].cost_Per_Serving < cheaptPrice)
		{
			cheaptPrice = report[i].cost_Per_Serving;
			cheapt = i;
		}
	}
	
	displayReportHeader();
	
	for (i = 0; i < max_Product; i++) 
	{
		
		displayReportData(report[i]);
		if (cheapt == i)
		{ 
			printf(" ***"); 
		}
		printf("\n");
	}
	
	displayFinalAnalysis(data[cheapt]);
	
}
