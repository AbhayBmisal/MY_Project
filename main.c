
#include "PatientManagement.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int ch;
   // struct node1* root = NULL;
   //struct node2* top = NULL;



    while (1)
    {
        printf("\nPress 1 to add a new patient\n");
        printf("Press 2 to add old patient's information\n");
        printf("Press 3 to delete information of a patient\n");
        printf("Press 4 to search by name\n");
        printf("Press 5 to identify disease\n");
        printf("Press 6 to exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            add_new_patient();
            break;

        case 2:
        {
            int number;
            printf("Enter patient number: ");
            scanf("%d", &number);
            display(number);
            add_patient_info();
            break;
        }

        case 3:
        {
            int number;
            printf("Enter number of patient to delete: ");
            scanf("%d", &number);
            delete_patient(number);
            break;
        }

        case 4:
        {
            char name[50];
            printf("Enter the patient name: ");
            scanf("%s", name);
            searchByName(name);
            break;
        }

        case 5:
        {
            struct Node* root = createNode("fever");
            root->yes = createNode("cough");
            root->no = createNode("headache");
            root->yes->yes = createNode("sore throat");
            root->yes->no = createNode("shortness of breath");
            root->no->yes = createNode("runny nose");
            root->no->no = createNode("body aches");
            root->yes->yes->yes = createNode("tonsillitis");
            root->yes->yes->no = createNode("common cold");
            root->yes->no->yes = createNode("asthma");
            root->yes->no->no = createNode("bronchitis");
            root->no->yes->yes = createNode("allergies");
            root->no->yes->no = createNode("sinusitis");
            root->no->no->yes = createNode("flu");
            root->no->no->no = createNode("COVID-19");
            root->yes->yes->yes->yes = createNode("streptococcal infection");
            root->yes->no->yes->yes = createNode("respiratory infection");
            root->no->yes->yes->yes = createNode("hay fever");

            identifyDisease(root);
            break;
        }

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

