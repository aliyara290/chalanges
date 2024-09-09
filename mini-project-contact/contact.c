#include <stdio.h>
#include <string.h>

struct contact
{
    char nom[50];
    char phone[50];
    char email[50];
};

int addContact(struct contact person[], int nb)
{
    printf("\nEnter contact name: ");
    scanf("%s", person[nb].nom);
    printf("Enter contact phone: ");
    scanf("%s", person[nb].phone);
    printf("Enter contact email: ");
    scanf("%s", person[nb].email);
    nb++;
    printf("\nContact successfully added.\n");
    return nb;
}

void Searching(struct contact person[], int nb) {
    char contactName[30];
    printf("\nEnter contact name: ");
    scanf("%s", contactName);

    for(int i = 0; i < nb; i++) {
        if(strcmp(person[i].nom, contactName) == 0) {
            printf("\nContact name: %s\n", person[i].nom);
            printf("Contact phone number: %s\n", person[i].phone);
            printf("Contact email: %s\n", person[i].email);
            return;
        }
    }
    printf("\nContact with the name '%s' not found.\n", contactName);
}

void modification(struct contact person[], int nb)
{
    char nameSearch[30];
    printf("\nEnter the name of the contact that you want to modify: ");
    scanf("%s", nameSearch);

    for (int i = 0; i < nb; i++)
    {
        if (strcmp(person[i].nom, nameSearch) == 0)
        {
            printf("Contact is found!\n");
            printf("Enter the new name of the contact: ");
            scanf("%s", person[i].nom);
            printf("Name updated successfully.\n");
            return;
        }
    }

    printf("Contact with the name '%s' not found.\n", nameSearch);
}

int deleteContact(struct contact person[], int nb)
{
    char nameSearch[30];
    printf("\nEnter the name of the contact that you want to delete: ");
    scanf("%s", nameSearch);

    for (int i = 0; i < nb; i++)
    {
        if (strcmp(person[i].nom, nameSearch) == 0)
        {
            for (int j = i; j < nb - 1; j++)
            {
                person[j] = person[j + 1];
            }
            nb--;
            printf("Contact deleted successfully.\n");
            return nb;
        }
    }

    printf("\nContact with the name '%s' not found.\n", nameSearch);
    return nb;
}

void affichage(struct contact person[], int nb)
{
    for (int i = 0; i < nb; i++)
    {
        printf("\n%s contact info: \n", person[i].nom);
        printf("Contact name: %s\n", person[i].nom);
        printf("Contact phone number: %s\n", person[i].phone);
        printf("Contact email: %s\n", person[i].email);
    }
}

int main()
{
    int nb = 0;
    int cases;
    struct contact person[100];

    printf("How many contacts do you want to add initially?: ");
    scanf("%d", &nb);

    for (int i = 0; i < nb; i++)
    {
        printf("\nEnter person %d contact info: \n", i + 1);
        printf("Enter contact name: ");
        scanf("%s", person[i].nom);
        printf("Enter contact phone number: ");
        scanf("%s", person[i].phone);
        printf("Enter contact email: ");
        scanf("%s", person[i].email);
    }

    do {
        printf("\nEnter one of the following numbers to perform an action:\n");
        printf("'1' to add a new contact.\n");
        printf("'2' to search for a contact.\n");
        printf("'3' to modify a contact.\n");
        printf("'4' to delete a contact.\n");
        printf("'5' to show all contacts.\n");
        printf("'6' to exit.\n");
        printf("\nEnter a number between 1 and 6: ");
        scanf("%d", &cases);

        switch (cases)
        {
            case 1:
                nb = addContact(person, nb);
                break;
            case 2:
                Searching(person, nb);
                break;
            case 3:
                modification(person, nb);
                break;
            case 4:
                nb = deleteContact(person, nb);
                break;
            case 5:
                affichage(person, nb);
                break;
            case 6:
                printf("\nSee you soon..\n");
                break;
            default:
                printf("Enter one of the numbers above!\n");
                break;
        }
    } while (cases != 6);

    return 0;
}
