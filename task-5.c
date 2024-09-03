#include <stdio.h>

int main()
{
    int n;
    printf("Entrez le nombre d'elements dans le tableau : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integer numbers: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // know the max integer in the array

    int max = arr[0];

    for(int i = 1; i < n; i++) {
        if(max > arr[i]) {
            max = arr[i];
        }
    }
    printf("Min element du tableau est : %d\n", max);
    return 0;
}