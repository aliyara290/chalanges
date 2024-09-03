#include <stdio.h>

int main()
{
    int nomber;
    printf("Enter le nomber de les elements: ");
    scanf("%d", &nomber);

    int tableau[nomber];
    for (int i = 0; i < nomber; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &tableau[i]);
    }

    int facteur;
    printf("Maintenant le facteur de multiplication: ");
    scanf("%d", &facteur);

 
    for (int i = 0; i < nomber; i++) {
        tableau[i] *= facteur;
        printf("%d ", tableau[i]);
    }

    return 0;
}