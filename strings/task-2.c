#include <stdio.h>
#include <string.h>

// Écrivez un programme C qui calcule et affiche la longueur d'une chaîne de caractères sans utiliser la fonction strlen().


int main() {
    char chaine[200];
    printf("Enter something here (words, sentence..): ");
    fgets(chaine, sizeof(chaine), stdin);

    int length = strlen(chaine);

    printf("length of the chaine is: %d", length);
}