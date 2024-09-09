#include <stdio.h>

void laMoyenne(int notes[], int nb) {
    int moyenne = 0;
    for(int i = 0; i < nb; i++) {
        moyenne += notes[i] / nb;
    }
    printf("\nLa moyenne des notes est: %d", moyenne);
}

void superieur(int notes[], int nb) {
    int super = 0;
    for(int i = 0; i < nb; i++) {
        super += notes[i] / nb;
        if(super >= notes[i]) {
            printf("les notes supérieures à la moyenne est: %d\n", notes[i]);
        } else {
            printf("No etudiant sepérieues de la moyenne");
        }
    }
}

void eleveeNote(int notes[], int nb) {
    int elevee = 0;
    int basse = 0;

    for(int i = 0; i < nb; i++) {
        if(notes[i] > notes[i]) {
            elevee = notes[i];
            printf("\nla note plus élevée est: %d", elevee);
        } if else(notes[i] < notes[i]) {
            elevee = notes[i];
            printf("\nla note plus basse est: %d", elevee);
        }
    }

}
int main() {

    int nb;
    printf("combien d'étudiants y a-t-il?: ");
    scanf("%d", &nb);

    int notes[nb];
    for(int i = 0; i < nb; i++) {
        printf("Enter la note de l'étudiant %d: ", i + 1);
        scanf("%d", &notes[i]);
    }

    int choix = 0;

    do {
        printf("\n1. Caculer la moyenne des notes\n");
        printf("\n2. Trouver la note la plus élevée et la plus basse\n");
        printf("\n3. Afficher les notes supérieures à la moyenne\n");
        printf("\n4. Compter le nombre d'étudiants ayant validé (note >= 12)\n");
        printf("\n5. Compter le nombre d'étudiants en rattrapage (note < 12)\n");
        printf("\n6. Quitter\n");
        printf("\nEntre nomber entre 1 - 6: ");
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
        break;
        case 5:
        break;
        case 6:
        printf("Au revoir !");
        break;
        default:
        printf("Entrer nomber entre 1 - 6");
        break;
    }

    } while(choix != 6);

    return 0;
}