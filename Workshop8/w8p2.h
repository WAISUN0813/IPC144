/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  :WAISUN LAM
Student ID#:146691225
Email      :wslam4@myseneca.ca
Section    :E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros
#define max_Product 3
#define num_Grams 64
#define lbs_To_Kg 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    double lbs;
    int cal_Serv;
};

struct ReportData
{
    int sku;
    double price;
    int cal_Serv;
    double lbs;
    double kg;
    int g;
    double total_Servings;
    double cost_Per_Serving;
    double cost_Of_Calories_Per_Serving;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void);

// 4. Get user input for the details of cat food product
double getCatFoodInfo(int* sku, double* price, double* lbs, int* cal_Serv, int s_num);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodDate(int sku, double* price, double*
    lbs, int cal_Serv);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(const int size_Gram, const int total_Grams, double* result);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* total_Servings, double* cost_Serving_Result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* total_Calories, double* Cost_Calories_Result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo data);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(int cheapest);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);