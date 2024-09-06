// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

struct birthday {
    int day, month, year;
};

struct accountInfo {
    char email[30];
    char password[100];
};

struct addresse {
    char ville[50];
    char paye[50];
    char codePostal[50];
    char addresse[50];
};

struct person {
    char firstName[30];
    char lastName[30];
    struct birthday birth;
    struct addresse addr;
    struct accountInfo account;
};

int main() {
    struct person person_1;
    printf("Enter your First name: ");
    scanf("%s", person_1.firstName);
    printf("Enter your Last name: ");
    scanf("%s", person_1.lastName);
    printf("Enter your Birth date(day/month/year): ");
    scanf("%d %d %d", &person_1.birth.day, &person_1.birth.month, &person_1.birth.year);
    // printf("Enter your Name: ");
    // scanf("%s", person_1.firstName);
    // printf("Enter your Name: ");
    // scanf("%s", person_1.firstName);
    

    printf("Your Name is: %s", person_1.firstName);
    return 0;
}