#include <stdio.h>

int main()
{
    printf("entrer 10 nombers: ");
    int nombers[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &nombers[i]);
    }
    int somme = 0;
    for (int i = 0; i < 10; i++)
    {

        if (nombers[i] % 5 == 0 || nombers[i] % 3 == 0)
        {

            somme += nombers[i];
        }
    }

    printf("le somme est: %d", somme);

    return 0;
}