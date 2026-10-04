#include <stdio.h>
#include<unistd.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr;
    if((fptr=fopen("contact.csv","w"))==NULL)
    {
        fprintf(stderr,"file not found");
        return ;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
    for(int i=0;i<=100;i++)
    {
        printf("Saving[");
        for(int dash=0;dash<i;dash++)
        {
            printf("-");
        }
        for(int space=i;space<100;space++)
            printf(" ");
        printf("]%d%%\r",i);
        fflush(stdout);
        for(int i=0;i<0xffffff;i++);
    }
    printf("\rChanges saved Successfully...");
    for(int i=0;i<=100;i++)
        printf(" ");
    printf("\n");
    
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr;
    if((fptr=fopen("contact.csv","r"))==NULL)
    {
        fprintf(stderr,"file not found");
        return ;
    }
    while((fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[addressBook->contactCount].name,
        addressBook->contacts[addressBook->contactCount].phone,
        addressBook->contacts[addressBook->contactCount].email))==3)
    {
        addressBook->contactCount++;
    }
    fclose(fptr);

    
}
