#include <stdio.h>

int main() {
    char chaine[200];
    printf("Enter something here (words, sentence..): ");
    
    fgets(chaine, sizeof(chaine), stdin);

    printf("You typed: %s", chaine);

    return 0;
}
