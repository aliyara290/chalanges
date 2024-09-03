#include <stdio.h>
// Écrivez un programme C qui calcule et affiche la somme des éléments d'un tableau d'entiers. Le programme doit demander le nombre d'éléments, puis les éléments du tableau, et afficher la somme totale.

int main()
{
    int num;
    int somme = 0;
    printf("Enter some integer numbers: ");
    scanf("%d", &num);
    int numbers[num];

    printf("Enter %d elements\n", num);
    for (int i = 0; i < num; i++)
    {
        printf("element %d: ", i + 1);
        scanf("%d", &numbers[i]);
        somme += numbers[i];
    }

    printf('La somme des elements du tableau est: %d', somme);
    return 0;
}
