#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
char temp[50]; // temp was declared globally and this used accross all function to store the characters temporarily
void listContacts(AddressBook *addressBook)
{
    int sortCriteria;
    do
    {

        printf("-----------------------------------\n");
        printf("\tSelect sort criteria:\n");
        printf("\t1. Sort by name  : \n");
        printf("\t2. Sort by phone : \n");
        printf("\t3. Sort by email : \n");
        printf("\t4.Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        if ((scanf("%d", &sortCriteria)) != 1)
        {
            while (getchar() != '\n')
                ;
            sortCriteria = 0;
        }
        switch (sortCriteria)
        {
        case 1:

            printf("Sorting based on name :\n\n");
            for (int i = 0; i < addressBook->contactCount - 1; i++) // Align the name in ascending order using bubble sort technique
            {
                for (int j = 0; j < addressBook->contactCount - i - 1; j++)
                {
                    if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) // strcmp stop and returns when str1 has greater than str2.
                    {
                        Contact temp = addressBook->contacts[j]; // if it is positive swap the contacts.
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            printf(" S.No: \tName:\t\t\tPhone No:\t\tEmail ID:\n\n");
            for (int i = 0; i < addressBook->contactCount; i++) // print the contacts in the addressbook after the sorting.
                printf("  %d.\t%-20s\t%-15s\t\t%-30s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            break;

        case 2:

            printf("Sorting based on phone :\n\n");
            for (int i = 0; i < addressBook->contactCount - 1; i++) // Align the phone number using bubble sort technique
            {
                for (int j = 0; j < addressBook->contactCount - i - 1; j++)
                {
                    if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0) // strcmp stop and returns when str1 has greater than str2.
                    {
                        Contact temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            printf(" S.No: \tName:\t\t\tPhone No:\t\tEmail ID:\n\n");
            for (int i = 0; i < addressBook->contactCount; i++) // print the contacts in the addressbook after the sorting.
                printf("  %d.\t%-20s\t%-15s\t\t%-30s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            break;

        case 3:

            printf("Sorting based on email :\n\n");
            for (int i = 0; i < addressBook->contactCount - 1; i++) // Align the Email ID using bubble sort technique
            {
                for (int j = 0; j < addressBook->contactCount - i - 1; j++)
                {
                    if (strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0) // strcmp stop and returns when str1 has greater than str2.
                    {
                        Contact temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            printf(" S.No: \tName:\t\t\tPhone No:\t\tEmail ID:\n\n");
            for (int i = 0; i < addressBook->contactCount; i++) // print the contacts in the addressbook after the sorting.
                printf("  %d.\t%-20s\t%-15s\t\t%-30s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            break;
        case 4:
            printf("->Exit Successfully...\n\n");
            break;
        default:
            printf("->Error Message : Invalid choice. Please try again.\n\n");
            break;
        }
    } while ((sortCriteria < 1) || (sortCriteria > 4));
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    // populateAddressBook(addressBook);
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook)
{
    int flag = 0, max = 0; // flag is to check whether the entered details are passed all validations or not
    do
    {
        if (addressBook->contactCount < MAX_CONTACTS) // to check whether the maximum contact range is reached or not
        {
            printf("Enter the name : ");
            scanf("%[^\n]", temp);
            while (getchar() != '\n')
                ;
            flag = name_validation(temp); // function call for name validation
            if (flag == 0)
                strcpy(addressBook->contacts[addressBook->contactCount].name, temp); // after validation storing the name in the contacts using strcpy function
        }
        else
        {
            printf("->Max contacts reached, so you can't able to store contact...\n");
            max = 1;
        }
    } while (flag);

    do
    {
        if (!max) // whether the maximum contact range is reached or not
        {
            printf("Enter the phone number : ");
            scanf("%s", temp);
            flag = phone_validation(temp, addressBook); // function call for phone validation

            if (!flag)
                strcpy(addressBook->contacts[addressBook->contactCount].phone, temp); // after validation storing the phone number in the Addressbook using strcpy function
        }
    } while (flag);

    do
    {
        flag = 0;
        if (!max) // whether the maximum contact range is reached or not
        {
            printf("enter the email id:");
            scanf("%s", temp);
            flag = email_validation(temp, addressBook);

            if (!flag)
            {
                strcpy(addressBook->contacts[addressBook->contactCount].email, temp); // after validation storing the phone number in the Addressbook using strcpy function
                printf("\n->Contact created successfully...\n\n");
            }
        }
    } while (flag);
    if (!max)
        addressBook->contactCount++; // finally increment the contactcount .
}

void searchContact(AddressBook *addressBook)
{
    int flag = 0, count = 0; // count is used to print how many contacts matched.
                             // flag is used to check whether the contact is matched or not.
    int searchChoice;
    do
    {
        printf("--------------------------------------\n");
        printf("\tSelect Search criteria:\n");
        printf("\t1. Search by name : \n");
        printf("\t2. Search by phone : \n");
        printf("\t3. Search by email : \n");
        printf("\t4. Exit : \n");
        printf("--------------------------------------\n");
        printf("Enter your choice : ");
        if (scanf("%d", &searchChoice) != 1)
        {
            while (getchar() != '\n')
                ;
            searchChoice = 0;
        }
        switch (searchChoice)
        {
        case 1:
            do
            {
                printf("enter the name:");
                scanf(" %s", temp);
                int i = 0;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcasestr(addressBook->contacts[i].name, temp)) // to check whether the name is present in the contact using strcasestr() function, because it will take both (alphabetic)cases.
                    {
                        printf("  %-20s\t%-15s\t\t%-30s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                        count++;
                    }
                }
                if (!flag)
                    printf("->Error Message : No matching record found\n");
                else
                    printf("\n %d contacts matched in addressbook\n\n", count);
            } while (!flag);
            break;

        case 2:
            do
            {
                count = 0;
                printf("enter the phone number:");
                scanf(" %s", temp);
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strstr(addressBook->contacts[i].phone, temp)) // to check whether the phone number is present in the Addressbook using strstr function.
                    {
                        printf("  %-20s\t%-15s\t\t%-30s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                        count++;
                    }
                }
                if (!flag)
                    printf("->Error Message : No matching record found\n");
                else
                    printf("\n %d contacts matched in addressbook\n\n", count);
            } while (!flag);
            break;

        case 3:
            do
            {
                count = 0;
                printf("enter the email:");
                scanf(" %s", temp);
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strstr(addressBook->contacts[i].email, temp)) // to check whether the email ID is present in the Addressbook using strstr function.
                    {
                        printf("  %-20s\t%-15s\t\t%-30s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                        count++;
                    }
                }
                if (!flag)
                    printf("->Error Message : No matching record found\n\n");
                else
                    printf("\n %d contacts matched in addressbook\n", count);
            } while (!flag);
            break;

        case 4:
            printf("->Exit successfully...\n");
            break;

        default:
            printf("->Error Message : Invalid choice please try again\n");
        }
    } while (searchChoice < 1 || searchChoice > 4);
}

void editContact(AddressBook *addressBook)
{
    int editChoice; // it is used to ask user, which one you want to edit  name or phone number or email ID.
    do
    {
        printf("--------------------------------------\n");
        printf("\tSelect Edit criteria : \n");
        printf("\t1. Edit by name : \n");
        printf("\t2. Edit by phone : \n");
        printf("\t3. Edit by email : \n");
        printf("\t4. Exit : \n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &editChoice) != 1)
        {
            while (getchar() != '\n')
                ;
            editChoice = 0;
        }
        switch (editChoice)
        {
            int flag, valid; // flag is used to check whether the entered name is present in the addressbook or not.
                             // valid is used to check whether the edited name would comes under validation or not.
        case 1:
            do
            {
                flag = 0;
                printf("Enter the previous name : ");
                scanf("%s", temp);
                int i = 0, index = 0; // index is used to print where the name stored in the addressbook
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcasestr(addressBook->contacts[i].name, temp)) // strcasestr is used to compare the entered name is whether present or not.
                    {
                        printf(" %d.\t%-15s\n", i + 1, addressBook->contacts[i].name);
                        flag = 1;
                    }
                }
                if (!flag)
                    printf("->Error Message : Name not found\nPlease enter valid name\n");
                if (flag)
                {
                    printf("Enter the serial number : ");
                    scanf("%d", &index);
                    do
                    {
                        printf("Enter the new name : ");
                        scanf(" %[^\n]", temp);
                        valid = name_validation(temp); // function call to name validation.

                        if (!valid) // if valid becomes zero means edited name as passsed all validations.
                        {
                            strcpy(addressBook->contacts[index - 1].name, temp); // using strcpy the name stored in the addressbook.
                            printf("\n->Name edited successfully...\n\n");
                        }
                    } while (valid);
                }
            } while (flag == 0);
            break;

        case 2:
            do
            {
                flag = 0;
                int index = 0;
                printf("enter the previous phone number:");
                scanf(" %s", temp);
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strstr(addressBook->contacts[i].phone, temp))
                    {
                        printf(" %d.\t%-15s\n", i + 1, addressBook->contacts[i].phone);
                        flag = 1;
                    }
                }
                if (!flag)
                    printf("->Error Message : Phone number not found\nPlease enter valid phone\n");
                if (flag)
                {
                    printf("Enter the serial number : ");
                    scanf("%d", &index);
                    do
                    {
                        printf("Enter the new number : ");
                        scanf("%s", temp);
                        valid = phone_validation(temp, addressBook); // function call to phone validation
                    } while (valid);

                    if (!valid) // if valid becomes zero means edited phone number as passsed all validations.
                    {
                        strcpy(addressBook->contacts[index - 1].phone, temp); // using strcpy the phone number stored in the addressbook.
                        printf("\n->Phone number edited successfully...\n\n");
                    }
                }
            } while (!flag);
            break;

        case 3:
            do
            {
                flag = 0;
                int index = 0;
                printf("enter the previous Email ID:");
                scanf(" %s", temp);
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strstr(addressBook->contacts[i].email, temp))
                    {
                        printf(" %d.\t%-15s\n", i + 1, addressBook->contacts[i].email);
                        flag = 1;
                    }
                }
                if (!flag)
                    printf("->Error Message : Email ID not found\nPlease enter valid Email\n");
                if (flag)
                {
                    printf("Enter the serial number : ");
                    scanf("%d", &index);
                    do
                    {
                        printf("Enter the new Email ID : ");
                        scanf("%s", temp);
                        valid = email_validation(temp, addressBook); // function call to email validation.
                    } while (valid);
                    if (!valid) // if valid becomes zero means edited email ID as passsed all validations.
                    {
                        strcpy(addressBook->contacts[index - 1].email, temp); // using strcpy the email ID stored in the addressbook.
                        printf("\n->Email ID edited successfully...\n\n");
                    }
                }
            } while (!flag);
            break;

        case 4:
            printf("->Exit successfully...\n");
            break;

        default:
            printf("->Error Message : Invalid choice. Please try again\n");
        }
    } while (editChoice < 1 || editChoice > 4); // it will terminate only,when the input beyond from 1 to 4.
}

void deleteContact(AddressBook *addressBook)
{
    int deleteChoice;
    do
    {
        printf("--------------------------------------\n");
        printf("\tSelect Delete criteria : \n\n");
        printf("\t1. Delete by name  : \n");
        printf("\t2. Delete by phone : \n");
        printf("\t3. Delete by email : \n");
        printf("\t4. Exit : \n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &deleteChoice) != 1) // it will clear the input buffer when the user enter the char instead of int.
        {
            while (getchar() != '\n')
                ;
            deleteChoice = 0; // initialize deleteChoioce =0 .
        }
        int flag; // flag is used to check whether the entered name is present in the addressbook or not.
        char var; // var is used to store the confirmation message from user.
        switch (deleteChoice)
        {

        case 1:
            do
            {
                flag = 0;
                printf("Enter the name to delete : ");
                scanf("%s", temp);
                int i = 0, index = 0; ////index is used to print the serial number stored in the addressbook
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcasestr(addressBook->contacts[i].name, temp)) // strcasestr is used to compare the entered name is whether present or not in the addressbook.
                    {
                        printf(" %3d. %3s \n", i + 1, addressBook->contacts[i].name);
                        flag = 1;
                    }
                }
                if (!flag)
                    printf("->Error Message : Name not found\nPlease enter valid name\n");
                else
                {
                    printf("Enter the serial number : ");
                    scanf("%d", &index);
                    printf("Are you sure you want to delete 'Y' / 'N' : "); // confirmation message
                    scanf(" %c", &var);
                    switch (var)
                    {
                    case 'Y':
                    case 'y':
                        index -= 1;
                        while (*addressBook->contacts[index].name != '\0')
                        {
                            addressBook->contacts[index] = addressBook->contacts[index + 1];
                            index++;
                        }
                        printf("->Contact deleted successfully...\n\n");
                        addressBook->contactCount--;
                        break;

                    case 'N':
                    case 'n':
                        printf("->contact wasn't deleted...\n\n");
                        flag = 1;
                        break;

                    default:
                        printf("->Error Message : Invalid choice please try again\n");
                    }
                }
            } while (!flag);
            break;
        case 2:
            do
            {
                flag = 0;
                printf("Enter the phone number to delete : ");
                scanf("%s", temp);
                int i = 0, index = 0;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strstr(addressBook->contacts[i].phone, temp)) // strstr is used to compare the entered name is whether present or not in the addresssbook.
                    {
                        printf("%3d.  %3s\n", i + 1, addressBook->contacts[i].phone);
                        flag = 1;
                    }
                }
                if (!flag)
                    printf("->Error Message : phone number not found\nPlease enter valid number\n");
                else
                {
                    printf("Enter the serial number : ");
                    scanf("%d", &index);
                    printf("Are you sure you want to delete 'Y' / 'N' : ");
                    scanf(" %c", &var);
                    switch (var)
                    {
                    case 'Y':
                    case 'y':
                        index -= 1;
                        while (*addressBook->contacts[index].phone != '\0')
                        {
                            addressBook->contacts[index] = addressBook->contacts[index + 1];
                            index++;
                        }
                        printf("->Contact deleted successfully...\n\n");
                        addressBook->contactCount--;
                        break;

                    case 'N':
                    case 'n':
                        printf("->contact wasn't deleted...\n\n");
                        flag = 1;
                        break;
                    default:
                        printf("->Error Message : Invalid choice please try again\n");
                    }
                }
            } while (!flag);
            break;

        case 3:
            do
            {
                flag = 0;
                printf("Enter the email to delete : ");
                scanf("%s", temp);
                int i = 0, index = 0;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strstr(addressBook->contacts[i].email, temp)) // strstr is used to compare the entered name is whether present or not in the addressbook
                    {
                        printf(" %3d. %3s \n", i + 1, addressBook->contacts[i].email);
                        flag = 1;
                    }
                }
                if (!flag)
                    printf("->Error Message : email not found\nPlease enter valid email\n");
                else
                {
                    printf("Enter the serial number : ");
                    scanf("%d", &index);
                    printf("Are you sure you want to delete 'Y' / 'N' : "); // confirmation message
                    scanf(" %c", &var);
                    switch (var)
                    {
                    case 'Y':
                    case 'y':
                        index -= 1;
                        while (*addressBook->contacts[index].email != '\0') // shift left technique is used to delete the contact from the addressbook.
                        {
                            addressBook->contacts[index] = addressBook->contacts[index + 1];
                            index++;
                        }
                        printf("->Contact deleted successfully...\n\n");
                        addressBook->contactCount--;
                        break;

                    case 'N':
                    case 'n':
                        printf("->Contact wasn't deleted...\n\n");
                        flag = 1;
                        break;

                    default:
                        printf("->Error Message : Invalid choice please try again\n");
                    }
                }
            } while (!flag);
            break;

        case 4:
            printf("->Exit successfully...\n");
            break;

        default:
            printf("->Error Message : Invalid choice please try again \n");
        }
    } while (deleteChoice < 1 || deleteChoice > 4);
}
int name_validation(char temp[])
{
    int flag = 0, len = strlen(temp);

    if (temp[flag] == ' ') // name doesn't start with space .
    {
        printf("->Error Message : Name should not start with space\n");
        return 1;
    }
    for (int i = 0; i < len; i++)
    {
        if ((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z') || temp[i] == ' ')
            flag = 0;

        else
        {
            printf("->Error Message : Name should contain only alphabets\n");
            flag = 1;
            break;
        }
    }
    if (len < 3)
    {
        printf("->Error Message : Name must contain at least 3 characters\n");
        flag = 1;
    }

    return flag;
}
int phone_validation(char temp[], AddressBook *addressBook)
{
    int flag = 0, len = strlen(temp);
    if (len != 10)
    {
        printf("->Error Message : Phone number must contain exactly 10 digits\n");
        flag = 1;
    }
    if (temp[0] < '6' || temp[0] > '9')
    {
        printf("->Error Message : First digit must be between 6 and 9\n");
        flag = 1;
    }
    for (int i = 0; i < len; i++)
    {
        if (temp[i] < '0' || temp[i] > '9')
        {
            printf("->Error Message : Other than Digits any other Character not allowed in phone number\n");
            flag = 1;
            break;
        }
    }
    for (int i = 0; i < addressBook->contactCount; i++)
        if (strcmp(addressBook->contacts[i].phone, temp) == 0)
        {
            printf("->Error Message : This phone number is already exists\n");
            flag = 1;
            break;
        }
    return flag;
}
int email_validation(char temp[], AddressBook *addressBook)
{
    int i = 0, is_symbol = 0, is_dot = 0, is_lower = 0, is_alpha = 0, is_invalid = 0, is_upper = 0; // is_symbol is used to check whether the @ is present or not.
                                                                                                    // is_dot is used to check whether the '.' is present or not.
                                                                                                    // is_lower is used to check whether the lower case is present or not.
                                                                                                    // is_alpha is used to check whether the alphabetic is present or not in b/w @ and '.'
                                                                                                    // is_upper is used to check whether the upper case is present or not.
    char str_cmp1[5] = "com", str_cmp2[10];
    while (temp[i] != '\0')
    {
        if ((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= '0' && temp[i] <= '9' || temp[i] == '.'))
            is_lower = 1;

        else if (temp[i] == '@')
            is_symbol++;

        else if (temp[i] >= 'A' && temp[i] <= 'Z')
            is_upper = 1;
        else
            is_invalid = 1;
        i++;
    }
    int flag = 0; //
    if (is_invalid)
    {
        printf("->Error Message : Invalid symbol identified\n");
        flag = 1;
    }
    if (!is_lower || is_upper)
    {
        printf("->Error Message : Email ID should only contain lowercase, Digits\n");
        flag = 1;
    }

    if (!is_symbol)
    {
        printf("->Error Message : Email ID must contain exactly one @ symbol\n");
        flag = 1;
    }
    else if (is_symbol > 1)
    {
        printf("->Error Message : Multiple @ symbols are not allowed\n");
        flag = 1;
    }

    i = 0, is_dot = 0;
    while (temp[i] != '\0') // this loop is used find the '.' is appear multiple times or not before '@'.
    {
        while (temp[i] != '@' && temp[i] != '\0')
        {
            if (temp[i] == '.')
                is_dot++;
            i++;
        }
        if (is_symbol && is_dot)
        {
            flag = 1;
            printf("->Error Message : The . (dot) must appear after @ symbol\n");
            break;
        }
        else if (is_dot > 1)
        {
            flag = 1;
            printf("->Error Message : Multiple . symbols are not allowed\n");
            break;
        }
        else
        {
            is_dot = 0;
            break;
        }
        i++;
    }
    i = 0;
    while (temp[i] != '\0') // this loop is used to find '.' present multiple times or not after '@'.
    {
        if (temp[i] == '@')
        {
            int j = i + 1;
            while (temp[j] != '\0')
            {
                if (temp[j] == '.')
                    is_dot++;
                j++;
            }
        }
        if (!is_symbol) //  '@' doesn't appear in the id and it check atleast '.' was appeared or not.
        {
            if (temp[i] == '.')
                is_dot++;
        }
        i++;
    }
    if (!is_dot)
    {
        printf("->Error Message : Email ID must contain exactly one . symbol\n");
        flag = 1;
    }
    else if (is_dot > 1)
    {
        printf("->Error Message : Email ID has more . (dot)symbol\n");
        flag = 1;
    }
    else
    {
        i = 0;
        while (temp[i] != '\0') // this loop is used to store the character after '.'
        {
            if (temp[i] == '.')
            {
                int j = 0;
                while (temp[i] != '\0')
                {
                    str_cmp2[j] = temp[i + 1];
                    j++;
                    i++;
                }
            }
            else
                i++;
        }
    }
    i = 0;
    is_alpha = 0;
    while (temp[i] != '.' && temp[i] != '\0') //  this loop is used to check atleast one character should present or not.
    {

        if (temp[i] == '@')
        {
            i++;
            if (temp[i] != '.')
            {
                while (temp[i] != '.' && temp[i] != '\0')
                {
                    if (temp[i] >= 'a' && temp[i] <= 'z')
                        ;

                    else
                    {
                        is_alpha = 1;
                        break;
                    }
                    i++;
                }
            }
            else
            {
                flag = 1;
                printf("->Error Message : At least one character should be present between @ and .(dot)\n");
                break;
            }
        }
        if (is_alpha && is_dot)
        {
            flag = 1;
            printf("->Error Message : Lower case should only present between @ and .(dot)\n");
            break;
        }
        i++;
    }
    if ((strcmp(str_cmp2, str_cmp1)) < 0 && is_dot) // if str_cmp2 has less words compare to str_cmp1 ,it returns in negative.
    {
        printf("->Error Message : 'com' must be present after '.' dot at the end\n");
        flag = 1;
    }
    if ((strcmp(str_cmp2, str_cmp1)) > 0 && is_dot) // if str_cmp2 has more words compare to str_cmp1 ,it returns in positive.
    {
        printf("->Error Message : At the end '.com' should only present\n");
        flag = 1;
    }

    if (flag == 0)
    {
        for (int index = 0; index < addressBook->contactCount; index++) // it is for check the entered email is already exist or not in the addressbook.
        {
            if ((strcmp(addressBook->contacts[index].email, temp)) == 0) // using strcmp() function I check every email exist in the addressbook.
            {
                printf("->Error Message : email id is already exist\n");
                flag = 1;
                break;
            }
            i++;
        }
    }
    return flag;
}
