#include <stdio.h>

void laMoyenne(int notes[], int nb) {
    int somme = 0;
    for(int i = 0; i < nb; i++) {
        somme += notes[i];
    }
    int moyenne = somme / nb;
    printf("\nLa moyenne des notes est: %d\n", moyenne);
}

void superieur(int notes[], int nb) {
    int somme = 0;
    for(int i = 0; i < nb; i++) {
        somme += notes[i];
    }
    int moyenne = somme / nb;

    printf("Les notes supérieures à la moyenne (%d) sont :\n", moyenne);
    for(int i = 0; i < nb; i++) {
        if(notes[i] > moyenne) {
            printf("%d\n", notes[i]);
        }
    }
}

void eleveeNote(int notes[], int nb) {
    int eleve = notes[0];
    int base = notes[0];

    for(int i = 1; i < nb; i++) {
        if(notes[i] > elevee) {
            eleve = notes[i];
        }
        if(notes[i] < basse) {
            base = notes[i];
        }
    }

    printf("\nLa note la plus élevée est: %d", elevee);
    printf("\nLa note la plus basse est: %d\n", basse);
}

void compterValide(int notes[], int nb) {
    int countValide = 0;
    for(int i = 0; i < nb; i++) {
        if(notes[i] >= 12) {
            countValide++;
        }
    }
    printf("Nombre d'étudiants ayant validé (note >= 12): %d\n", countValide);
}

void compterRattrapage(int notes[], int nb) {
    int countRattrapage = 0;
    for(int i = 0; i < nb; i++) {
        if(notes[i] < 12) {
            countRattrapage++;
        }
    }
    printf("Nombre d'étudiants en rattrapage (note < 12): %d\n", countRattrapage);
}

int main() {
    int nb;
    printf("Combien d'étudiants y a-t-il?: ");
    scanf("%d", &nb);

    int notes[nb];
    for(int i = 0; i < nb; i++) {
        printf("Entrez la note de l'étudiant %d: ", i + 1);
        scanf("%d", &notes[i]);
    }

    int choix = 0;

    do {
        printf("\n1. Calculer la moyenne des notes\n");
        printf("2. Trouver la note la plus élevée et la plus basse\n");
        printf("3. Afficher les notes supérieures à la moyenne\n");
        printf("4. Compter le nombre d'étudiants ayant validé (note >= 12)\n");
        printf("5. Compter le nombre d'étudiants en rattrapage (note < 12)\n");
        printf("6. Quitter\n");
        printf("Entrez un nombre entre 1 et 6: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                laMoyenne(notes, nb);
                break;
            case 2:
                eleveeNote(notes, nb);
                break;
            case 3:
                superieur(notes, nb);
                break;
            case 4:
                compterValide(notes, nb);
                break;
            case 5:
                compterRattrapage(notes, nb);
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Veuillez entrer un nombre valide entre 1 et 6.\n");
                break;
        }

    } while(choix != 6);

    return 0;
}
