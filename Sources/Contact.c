#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addContact()
{
    FILE *file = fopen("../extern/contacts.csv", "a");
    char name[100];
    char surname[100];
    char phone[100];
    char email[100];
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the surname: ");
    scanf("%s", surname);
    printf("Enter the phone: ");
    scanf("%s", phone);
    printf("Enter the email: ");
    scanf("%s", email);
    fprintf(file, "%s,%s,%s,%s\n", name, surname, phone, email);
    fclose(file);
    system("pause");
}

void showContacts()
{
    FILE *file = fopen("../extern/contacts.csv", "r");
    char name[100];
    char surname[100];
    char phone[100];
    char email[100];
    // skip the first line of the csv
    fgets(name, 100, file);
    while (fgets(name, 100, file) != NULL) {
        // read data from the csv
        sscanf(name, "%[^,],%[^,],%[^,],%[^\n]", name, surname, phone, email);
        printf("Name: %s %s\n", name, surname);
        printf("Phone number: %s\n", phone);
        printf("Email address: %s\n", email);
        printf("\n");
    }
    fclose(file);
    system("pause");
}