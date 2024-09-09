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

void affichage(struct person p1) {
     printf("Your first Name is: %s", p1.firstName);
    printf("Your last name is: %s", p1.lastName);
    printf("Your last name is: %s / %s / %s", p1.birth.day, p1.birth.month, p1.birth.year);
}

int main() {
    struct person p1;
    int cases;
    
    char data[] = {"first name", "last name", "birthday"}
    
    do{
        
    switch(cases) {

    }
    }

   
    return 0;
}