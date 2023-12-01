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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h>

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            printf("\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("\nPatient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int record;
    
    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }
    
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            record = 1;
        }
    }

    if (record == 0)
    {
        printf("*** No records found ***\n\n");
    }
    
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int searchOptions;
    
    do  
    {
        printf("Search Options\n==========================\n1) By patient number\n2) By phone number\n..........................\n0) Previous menu\n..........................\n");
        printf("Selection: ");
        scanf("%d", &searchOptions);
        printf("\n");

        if (searchOptions == 1) {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (searchOptions == 2) {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (searchOptions != 0);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {
    int i;
    int count = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            count++;
        }
    }
    if (count < max) {
        patient[count].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[count]);
        printf("\n*** New patient record added ***\n\n");
        clearInputBuffer();
    }
    else {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) 
{
    int patientNum, locate;

    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    printf("\n");
    
    locate = findPatientIndexByPatientNum(patientNum, patient, max);

    if (locate == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else 
    {
        menuPatientEdit(patient + locate);
    }
}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) 
{
    int patientNum;
    int locate;
    char confirm;
    
    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    printf("\n");

    locate = findPatientIndexByPatientNum(patientNum, patient, max);
    if (locate != -1)
    {
        printf("Name  : %s\n", patient[locate].name);
        printf("Number: %05d\n", patient[locate].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[locate].phone.number);
        printf(" (%s)", patient[locate].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");
        clearInputBuffer();
        scanf("%c", &confirm);

        if (confirm == 'y') 
        {
            patient[locate].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        else 
        {
            printf("Operation aborted.\n\n");
        }
    }
    else 
    {
        printf("ERROR: Patient record not found!\n\n");
    }

}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) 
{
    int patientNum;
    int locate;
    
    printf("Search by patient number: ");
    scanf("%d", &patientNum);
    printf("\n");

    locate = findPatientIndexByPatientNum(patientNum, patient, max);
    if (locate != -1) 
    {
        printf("Name  : %s\n", patient[locate].name);
        printf("Number: %05d\n", patient[locate].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[locate].phone.number);
        printf(" (%s)", patient[locate].phone.description);
        printf("\n\n");
    }
    else {
        printf("*** No records found ***\n\n");
    }
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) 
{
    char phoneNumber[PHONE_LEN + 1];
    int found = 0;
    int i;

    printf("Search by phone number: ");
    scanf("%10s", phoneNumber);
    clearInputBuffer();
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++) 
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0) 
        {
            found = 1;
            printf("%05d", patient[i].patientNumber);
            printf(" %-15s ", patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)", patient[i].phone.description);
            printf("\n");
        }
    }

    if (!found) 
    {
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) 
{
    int maxPnumber = 0;
    int i;

    for (i = 0; i < max; i++) 
    {
        if (patient[i].patientNumber > maxPnumber) 
        {
            maxPnumber = patient[i].patientNumber;
        }
    }

    return maxPnumber + 1;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) 
    {
        if (patient[i].patientNumber == patientNumber) 
        {
            return i;
        }
    }
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) 
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", (*patient).patientNumber);
    printf("Name  : ");
    scanf(" %[^\n]", (*patient).name);
    printf("\n");
    inputPhoneData(&((*patient).phone));
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {
    int option;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &option);
    

    if (option == 1) {
        strcpy((*phone).description, "CELL");
        printf("\nContact: %s\n", (*phone).description);
        clearInputBuffer();
        printf("Number : ");
        scanf(" %[^\n]", (*phone).number);
        
    }
    else if (option == 2) {
        strcpy((*phone).description, "HOME");
        printf("\nContact: %s\n", (*phone).description);
        clearInputBuffer();
        printf("Number : ");
        scanf(" %[^\n]", (*phone).number);
        
    }
    else if (option == 3) {
        strcpy((*phone).description, "WORK");
        printf("\nContact: %s\n", (*phone).description);
        clearInputBuffer();
        printf("Number : ");
        scanf(" %[^\n]", (*phone).number);
        
    }
    else {
        strcpy((*phone).description, "TBD");
        (*phone).number[0] = '\0';
        
    }

    (*phone).number[strcspn((*phone).number, "\n")] = '\0';
}

