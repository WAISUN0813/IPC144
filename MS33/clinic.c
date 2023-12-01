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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) 
{
    
    int index;
    int count;
    int i = 0;

    count = 0;
    while (i < max && count == 0) 
    {
        if (patient[i].patientNumber == 0) 
        {
            count = 1;
            index = i;
        }
        i++;
    }

    if (count != 0) 
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n");
        clearInputBuffer();
    }
    else 
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patientNum;
    int locate;
    char confirm;
    char character;

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
        int loop = 1;
        while (loop)
        {
            scanf(" %c%c", &confirm, &character);

            if ((confirm == 'n' || confirm == 'N') && (character == '\n'))
            {
                printf("Operation aborted.\n\n");
                clearInputBuffer();
                loop = 0;
            }
            else if ((confirm == 'y' || confirm == 'Y') && (character == '\n'))
            {
                patient[locate].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                loop = 0;
            }
            else
            {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        }
    }
    else 
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    } 
}
     
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) 
{
    int i;
    int j;
    
    sort((*data).appointments, (*data).maxAppointments);

    displayScheduleTableHeader(NULL, 1);

    for (i = 0; i < (*data).maxAppointments; i++) {
        for (j = 0; j < (*data).maxPatient; j++) {
            if ((*data).appointments[i].patientNumber && (*data).patients[j].patientNumber) {
                if ((*data).appointments[i].patientNumber == (*data).patients[j].patientNumber) {
                    displayScheduleData(&(*data).patients[j], &(*data).appointments[i], 1);
                }
            }
        }
    }

    printf("\n");
}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i;
    int j;
    int monthDay = 31;
    struct Date date;

    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    printf("Day (1-");
  
    if (date.month == 2) 
    {
        monthDay = 28;
    }
    if (date.year % 4 == 0 && date.month == 2) 
    {
        monthDay = 29;
    }
    if (date.month == 4 || date.month == 9 || date.month == 11)
    {
        monthDay = 30;
    }
    printf("%d)  : ", monthDay);
    date.day = inputIntRange(1, monthDay);
    printf("\n");
    
    sort((*data).appointments, (*data).maxAppointments);
    
    displayScheduleTableHeader(&date, 0);
    
    for (i = 0; i < (*data).maxAppointments; i++)
    {

        for (j = 0; j < (*data).maxPatient; j++)
        {
            if ((*data).appointments[i].patientNumber != 0 && (*data).patients[j].patientNumber != 0 &&
                (*data).appointments[i].patientNumber == (*data).patients[j].patientNumber)
            {
                if ((*data).appointments[i].date.year == date.year && (*data).appointments[i].date.month == date.month && (*data).appointments[i].date.day == date.day)
                {

                    displayScheduleData(&(*data).patients[j], &(*data).appointments[i], 0);
                }
            }
        }
    }

    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointment, int maxAppointments, struct Patient* patient, int maxPatients)
{

    struct Date date;
    struct Time time;
    int i;
    int monthDay = 31;
    int patientNumber;
    int location;
    int noday = 1;
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    location = findPatientIndexByPatientNum(patientNumber, patient, maxPatients);

    if (location >= 0)
    {
        do
        {
            printf("Year        : ");
            date.year = inputIntPositive();

            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            printf("Day (1-");
           
            if (date.month == 2) 
            {
                monthDay = 28;
            }
            if (date.year % 4 == 0 && date.month == 2) 
            {
                monthDay = 29;
            }
            if (date.month == 4 || date.month == 9 || date.month == 11) 
            {
                monthDay = 30;
            }
            printf("%d)  : ", monthDay);
            date.day = inputIntRange(1, monthDay);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            for (i = 0; i < maxAppointments; i++)
            {
                if (date.year == appointment[i].date.year && date.month == appointment[i].date.month && date.day == appointment[i].date.day && time.hour == appointment[i].time.hour && time.min == appointment[i].time.min)
                {
                    printf("\nERROR: Appointment timeslot is not available!\n\n");

                    printf("Year        : ");
                    date.year = inputIntPositive();

                    printf("Month (1-12): ");
                    date.month = inputIntRange(1, 12);

                    printf("Day (1-");
                  
                    if (date.month == 2) 
                    {
                        monthDay = 28;
                    }
                    if (date.year % 4 == 0 && date.month == 2) 
                    {
                        monthDay = 29;
                    }
                    if (date.month == 4 || date.month == 9 || date.month == 11) 
                    {
                        monthDay = 30;
                    }
                    printf("%d)  : ", monthDay);
                    date.day = inputIntRange(1, monthDay);
                }
                else
                {
                    noday = 0;

                }
            }
        } while (noday != 0);


        do
        {
            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);
            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);
            if ((time.hour < START || time.hour > END) || (time.hour == END && time.min > 0) || (time.min % MIN_INTERVAL != 0))
            {
                printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START, END, MIN_INTERVAL);
            }
        } while ((time.hour < START || time.hour > END) || (time.hour == END && time.min > 0) || (time.min % MIN_INTERVAL != 0));

        location = slot(appointment, maxAppointments);
        appointment[location].date = date;
        appointment[location].time = time;
        appointment[location].patientNumber = patientNumber;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
}
  
// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointment, int maxAppointments, struct Patient* patient, int maxPatients) 
{
    struct Date date;
    int location;
    int location2;
    int patientNumber;
    int monthDay = 31;

    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    location = findPatientIndexByPatientNum(patientNumber, patient, maxPatients);

    if (location >= 0)
    {
        printf("Year        : ");
        date.year = inputIntPositive();

        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        printf("Day (1-");
        
        if (date.month == 2) 
        {
            monthDay = 28;
        }
        if (date.year % 4 == 0 && date.month == 2) 
        {
            monthDay = 29;
        }
        if (date.month == 4 || date.month == 9 || date.month == 11)
        {
            monthDay = 30;
        }
        printf("%d)  : ", monthDay);
        date.day = inputIntRange(1, monthDay);
       
        location2 = check(patientNumber, date, appointment, maxAppointments);


        if (location2 >=0)
        {
            printf("\n");
            displayPatientData(&patient[location], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y')
            {
                appointment[location2].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }

            else
            {
                printf("ERROR: No appointment for this date!\n\n");
            }
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", (*patient).patientNumber);
    printf("Name  : ");
    inputCString((*patient).name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&((*patient).phone));
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone) 
{
    int option;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    option = inputIntRange(1, 4);

    if (option == 1) 
    {
        strcpy((*phone).description, "CELL");
        printf("\nContact: %s\n", (*phone).description);
        printf("Number : ");
        do 
        {
            inputCString((*phone).number, 10, 10);
            //scanf(" %[^\n]", (*phone).number);
            clearInputBuffer();
            //if (strlen((*phone).number) != 10)
            //{
                //printf("Invalid 10-digit number! Number: ");
            //}
        } while (strlen((*phone).number) != 10);
    }
    else if (option == 2) 
    {
        strcpy((*phone).description, "HOME");
        printf("\nContact: %s\n", (*phone).description);
        printf("Number : ");
        do
        {
            inputCString((*phone).number, 10, 10);
            //scanf(" %[^\n]", (*phone).number);
            clearInputBuffer();
            //if (strlen((*phone).number) != 10)
            //{
                //printf("Invalid 10-digit number! Number: ");
            //}
        } while (strlen((*phone).number) != 10);
    }
    else if (option == 3) 
    {
        strcpy((*phone).description, "WORK");
        printf("\nContact: %s\n", (*phone).description);
        printf("Number : ");
        do
        {
            inputCString((*phone).number, 10, 10);
            //scanf(" %[^\n]", (*phone).number);
            clearInputBuffer();
            //if (strlen((*phone).number) != 10)
            //{
               // printf("Invalid 10-digit number! Number: ");
            //}
        } while(strlen((*phone).number) != 10);
    }
    else 
    {
        strcpy((*phone).description, "TBD");
        (*phone).number[0] = '\0';

    }

    (*phone).number[strcspn((*phone).number, "\n")] = '\0';
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    size_t i = 0;
    FILE* fp;
    char line[256];

    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (i < max && fgets(line, sizeof(line), fp) != NULL)
        {
            if (sscanf(line, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF)
            {
                i++;
            }
            else
            {
                printf("ERROR: Failed to parse line: %s\n", line);
            }
        }

        fclose(fp);
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }

    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int count = 0;
    FILE* fp;
    char line[256]; 

    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (count < max && fgets(line, sizeof(line), fp) != NULL)
        {
            if (sscanf(line, "%d,%d,%d,%d,%d,%d", &appoints[count].patientNumber, &appoints[count].date.year, &appoints[count].date.month, &appoints[count].date.day, &appoints[count].time.hour, &appoints[count].time.min) == 6)
            {
                count++;
            }
            else
            {
                printf("ERROR: Failed to parse line: %s\n", line);
            }
        }

        fclose(fp);
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }

    return count;
}

/*void sort(struct Appointment appoints[], int max)
{
    int i;
    int j;
    int minIndex;
    struct Appointment temp;
   
    for (i = 0; i < max; i++) 
    {
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;
    }

    for (i = 0; i < max - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < max; j++)
        {
            if (appoints[j].time.min < appoints[minIndex].time.min)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            temp = appoints[i];
            appoints[i] = appoints[minIndex];
            appoints[minIndex] = temp;
        }
    }

    for (i = 0; i < max; i++) 
    {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }
}*/

void sort(struct Appointment appoints[], int max)
{
    int i;
    int j;
    int minIndex;
    struct Appointment temp;
    const int MINUTES_PER_YEAR = 12 * 30 * 24 * 60;
    const int MINUTES_PER_MONTH = 30 * 24 * 60;
    const int MINUTES_PER_DAY = 24 * 60;
    const int MINUTES_PER_HOUR = 60;

    for (i = 0; i < max; i++)
    {
        appoints[i].time.min = appoints[i].date.year * MINUTES_PER_YEAR +
            appoints[i].date.month * MINUTES_PER_MONTH +
            appoints[i].date.day * MINUTES_PER_DAY +
            appoints[i].time.hour * MINUTES_PER_HOUR +
            appoints[i].time.min;
       
    }

    for (i = 0; i < max - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < max; j++)
        {
            if (appoints[j].time.min < appoints[minIndex].time.min)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            temp = appoints[i];
            appoints[i] = appoints[minIndex];
            appoints[minIndex] = temp;
        }
    }

    for (i = 0; i < max; i++)
    {
         
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * MINUTES_PER_YEAR +
            appoints[i].date.month * MINUTES_PER_MONTH +
            appoints[i].date.day * MINUTES_PER_DAY +
            appoints[i].time.hour * MINUTES_PER_HOUR);
    }
}
int slot(struct Appointment* appointment, int maxAppointments)
{
    int i = 0;
    int fine = 0;
    do
    {
        if (fine == 0 && i < maxAppointments)
        {
            if (appointment[i].patientNumber < 1)
                fine = 1;
        }
        i++;
    } while (fine == 0 && i < maxAppointments);
    return i;
}

int check(int patientNumber, struct Date date, struct Appointment* appointment, int maxAppointments) 
{
    int i = 0;
    int flag = 0;

    do {
        if ((appointment[i].patientNumber == patientNumber) && (appointment[i].date.day == date.day) && (appointment[i].date.month == date.month) && (appointment[i].date.year == date.year))
        {
            flag = 1;
        }
        i++;
    } while (flag == 0 && i < maxAppointments);

    return i - 1;
}
