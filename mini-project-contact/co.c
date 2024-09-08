#include <stdio.h>
#include <string.h>

struct contact
{
    char nom[50];
    char phone[50];
    char email[50];
};

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
    do
    {
        printf("\nEnter one of the following numbers to perform an action:\n");
        printf("'1' to show all contacts.\n");
        printf("'2' to modify a contact.\n");
        printf("'3' to exist.\n");
        printf("Enter a number between 1 and 2: ");
        scanf("%d", &cases);

        switch (cases)
        {
        case 1:
            affichage(person, nb);
            break;
        case 2:
            modification(person, nb);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Enter one of the numbers above!\n");
            break;
        }
    } while (cases != 3);
    return 0;
}