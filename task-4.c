#include <stdio.h>

int main()
{
    int n;

    printf("Entrez le nombre d'elements dans le tableau : ");
    scanf("%d", &n);

    int arr[n];

    printf("Entrez %d elements :\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("grand element du tableau est : %d\n", max);

    return 0;
}
