/*
DOCUMENTATION

NAME        :Rajkamal V
ID          :26012_111
START DATE  :14/06/2026
END DATE    :28/07/2026
SAMPLE INPUT:
-----------------------------------
        Address Book Menu:
        1. Create contact
        2. Search contact
        3. Edit contact
        4. Delete contact
        5. List all contacts
        6. Exit
-----------------------------------

Enter your choice: 1
Enter the name : scarlett
Enter the phone number : 9876543219
enter the email id:blackwidow@gmail.com

SAMPLE OUTPUT:
->Contact created successfully...
*/
#include <stdio.h>
#include "contact.h"
int main() 
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("-----------------------------------");
        printf("\n\tAddress Book Menu:\n");
        printf("\t1. Create contact\n");
        printf("\t2. Search contact\n");
        printf("\t3. Edit contact\n");
        printf("\t4. Delete contact\n");
        printf("\t5. List all contacts\n");
        printf("\t6. Exit\n");
        printf("-----------------------------------\n");
        printf("\nEnter your choice: ");  
        if((scanf("%d", &choice))!=1)
        {
            while(getchar()!='\n');
            choice=0;
        }
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                
                listContacts(&addressBook);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("->Error Message : invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
