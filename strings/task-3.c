#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[200];

    printf("Entrez la première chaîne : ");
    fgets(str1, sizeof(str1), stdin);

    printf("Entrez la deuxième chaîne : ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    strcpy(result, str1);
    strcat(result, str2);

    printf("Chaîne résultante : %s\n", result);

    return 0;
}
