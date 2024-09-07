#include <stdio.h>

int main()
{
    int originalArray[5] = {1, 2, 3, 4, 5};
    int copiedArray[5];
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        copiedArray[i] = originalArray[i];
    }

    printf("Éléments du tableau original : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", originalArray[i]);
    }
    printf("\n");

    printf("Éléments du tableau copié : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", copiedArray[i]);
    }
    printf("\n");

    return 0;
}
