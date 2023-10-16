
#include "PatientManagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


//struct node1* root = NULL;

//struct node2* top = NULL;

// Initialization 

void init(struct node1* root, struct node2* top)
{
    root = NULL;
    top = NULL;
    return;
}


// To create new node


struct Node* createNode(const char* symptom)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->symptom, symptom);
    node->yes = NULL;
    node->no = NULL;
    return node;
}


// To search patient information by the name


void searchByName(const char* name)
{
    struct node1* p = root;
    int found = 0;

    while (p != NULL)
    {
        if (strcmp(p->patient_name, name) == 0)
        {
            printf("Patient Number: %d\n", p->patient_no);
            printf("Patient Name: %s\n", p->patient_name);
            printf("Patient Gender: %s\n", p->gender);
            printf("Age of Patient: %d\n", p->age);

            struct node2* q = p->ptr;

            while (q != NULL)
            {
                printf("Visit Date: %s\n", q->date);
                printf("Weight: %.2f\n", q->weight);
                printf("Disease: %s\n", q->disease);
                printf("Medicine Recommended: %s\n", q->medicine);
                printf("\n");
                q = q->link;
            }

            found = 1;
        }
        p = p->link;
    }

    if (!found)
    {
        printf("No patient records found for the given name.\n");
    }
}


//To calculate opd fees


void calculateFee(const char date[])
{
    int fee = 500;
    printf("The fee for checking is: %d", fee);

}


// To shedule an appointment


void scheduleAppointment()
{
    struct node1* p = (struct node1*)malloc(sizeof(struct node1));
    struct node2* q = (struct node2*)malloc(sizeof(struct node2));
    struct node1* t;
    int count = 0;

    printf("Enter the name of the patient: ");
    scanf("%s", p->patient_name);
    printf("Enter patient's gender: ");
    scanf("%s", p->gender);
    printf("Enter patient's age: ");
    scanf("%d", &p->age);

    p->ptr = NULL;
    p->link = NULL;

    if (root == NULL)
    {
        root = p;
    }
    else
    {
        t = root;

        while (t->link != NULL)
        {
            t = t->link;
            count = count+1;
        }
        count = count + 1;

        t->link = p;
    }

   p->patient_no = count+1;

    time_t t1;
    time(&t1);
    struct tm* data;
    data = localtime(&t1);
    strftime(p->appointment_date, 11, "%Y-%m-%d", data);
    strftime(p->appointment_time, 6, "%H:%M", data);

    printf("\nAppointment Scheduled Successfully!\n");
    printf("Appointment Date: %s\n", p->appointment_date);
    printf("Appointment Time: %s\n", p->appointment_time);

    printf("\nEnter the visit date: ");
    scanf("%s", q->date);
    printf("Enter the weight of the patient: ");
    scanf("%f", &q->weight);
    printf("Enter the disease diagnosed: ");
    scanf("%s", q->disease);
    printf("Enter the medicine recommended: ");
    scanf("%s", q->medicine);

    q->link = NULL;

    if (p->ptr == NULL)
    {
        p->ptr = q;
    }
    else
    {
        t = p->ptr;

        while (t->link != NULL)
        {
            t = t->link;
        }

        t->link = q;
    }
}


// To add new patient 


void add_new_patient()
{
    int ch;
    printf("\nSchedule an appointment\n");
    

    scheduleAppointment();
    //break;
   
}


// To add patient information


void add_patient_info()
{
    int number, i;
    printf("Enter patient number: ");
    scanf("%d", &number);

    struct node1* p = root;
    struct node2* q;

    while (p != NULL)
    {
        if (p->patient_no == number)
        {
            q = p->ptr;

            while (q->link != NULL)
            {
                q = q->link;
            }

            struct node2* r = (struct node2*)malloc(sizeof(struct node2));

            printf("Enter the visit date: ");
            scanf("%s", r->date);
            printf("Enter the weight of the patient: ");
            scanf("%f", &r->weight);
            printf("Enter the disease diagnosed: ");
            scanf("%s", r->disease);
            printf("Enter the medicine recommended: ");
            scanf("%s", r->medicine);

            r->link = NULL;
            q->link = r;

            printf("\nPatient Information Added Successfully!\n");
            return;
        }

        p = p->link;
    }

    printf("No patient found with the given number.\n");
}


// To display patient information
 

void display(int number)
{
    struct node1* p = root;

    while (p != NULL)
    {
        if (p->patient_no == number)
        {
            printf("Patient Number: %d\n", p->patient_no);
            printf("Patient Name: %s\n", p->patient_name);
            printf("Patient Gender: %s\n", p->gender);
            printf("Age of Patient: %d\n", p->age);

            struct node2* q = p->ptr;

            while (q != NULL)
            {
                printf("Visit Date: %s\n", q->date);
                printf("Weight: %.2f\n", q->weight);
                printf("Disease: %s\n", q->disease);
                printf("Medicine Recommended: %s\n", q->medicine);
                printf("The fee for checking is INR 500");
                printf("\n");
                q = q->link;
            }

            return;
        }

        p = p->link;
    }

    printf("No patient found with the given number.\n");
}


// To delete all the data of existing patient


void delete_patient(int number)
{
    struct node1* p = root, * prev = NULL, *r;

    while (p != NULL)
    {
        if (p->patient_no == number)
        {
            if (prev == NULL)
            {
                root = p->link;
                p->link = NULL;
            }
            else
            {
                prev->link = p->link;
                p -> link = NULL;
            }
            r = prev -> link;
            while(r!=NULL)
            {
            	r -> patient_no = r -> patient_no -1;
            	r = r -> link;
			}

            free(p);

            printf("Patient information deleted successfully!\n");
            return;
        }

        prev = p;
        p = p->link;
    }

    printf("No patient found with the given number.\n");
}


// To identify disease of patient using symptoms


void identifyDisease(struct Node* root)
{
    struct Node* current = root;

    while (current->yes != NULL && current->no != NULL)
    {
        printf("%s (yes/no): ", current->symptom);

        char choice[10];
        scanf("%s", choice);

        if (strcmp(choice, "yes") == 0)
        {
            current = current->yes;
        }
        else if (strcmp(choice, "no") == 0)
        {
            current = current->no;
        }
        else
        {
            printf("Invalid choice!\n");
            return;
        }
    }

    printf("The identified disease is: %s\n", current->symptom);
}


// Function to save patient data to a file

/*
void saveDataToFile(const char* file1) {
    FILE* file = fopen(file1, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    struct node1* current = root;

    while (current != NULL) {
        fprintf(file, "%d,%s,%d,%s\n", current->patient_no, current->patient_name, current->age, current->gender);
        current = current->link;
    }

    fclose(file);
    printf("Patient data saved to file successfully!\n");
}
*/


// Function to load patient data from a file

/*
void loadDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    struct node1* current = head;

    // Clear the existing patient data
    while (current != NULL) {
        struct node1* temp = current;
        current = current->link;
        free(temp);
    }
    head = NULL;

    // Read patient data from file
    while (!feof(file)) {
        int patient_no, age;
        char patient_name[50], gender[10];

        if (fscanf(file, "%d,%[^,],%d,%s\n", &patientId, name, &age, gender) == 4) {
            addPatient(patientId, name, age, gender);
        }
    }

    fclose(file);
    printf("Patient data loaded from file successfully!\n");
}*/
