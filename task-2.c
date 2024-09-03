#include <stdio.h> 
// Écrivez un programme C qui demande à l'utilisateur le nombre d'éléments d'un tableau, puis demande à l'utilisateur de saisir ces éléments. Affichez ensuite les éléments du tableau.
int main() {
    int nb;
    printf("Enter the number of elements: ");
    scanf("%d", &nb);

    int arr[nb];

    printf("Know enter %d elements\n", nb);

    for(int i = 0; i < nb; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("the array elements are: ");

    for(int i = 0; i < nb; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}