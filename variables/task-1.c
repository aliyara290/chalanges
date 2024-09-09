#include <stdio.h>

// Écrivez un programme qui demande un nombre et affiche si ce nombre est pair ou impair.

int main() {

    int nb;

    printf("Enter a number to see if it odd or even: ");
    scanf("%d", &nb);

    if(nb % 2 == 0) {
        printf("\nthe nubmer %d is even.\n", nb);
    } else {
        printf("the number %d is odd.", nb);
    }
    return 0;
}