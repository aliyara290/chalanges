#include <stdio.h>

struct contact
{
    char nom[50];
    char phone[50];
    char email[50];
};

int main()
{
    int nb;

    struct contact person[nb];
    printf("How many contact you want to add?: ");
    scanf("%d", &nb);

    for (int i = 0; i < nb; i++)
    {
        printf("\nEnter person %d contact infos: \n", i + 1);
        printf("Enter contact name: ");
        scanf("\n%s", person[i].nom);
        printf("Enter contact phone number: ");
        scanf("\n%s", person[i].phone);
        printf("Enter contact email: ");
        scanf("\n%s", person[i].email);
    }

    for (int i = 0; i < nb; i++)
    {
        printf("\nperson %d contact infos: \n", i + 1);
        printf("Contact name: %s\n", person[i].nom);
        printf("Contact phone number: %s\n", person[i].phone);
        printf("Contact email: %s\n", person[i].email);
    }
    return 0;
}