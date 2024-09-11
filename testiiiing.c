#include <stdio.h>

struct etudiantDate {
    char jour[20];
    char mois[20];
    char annee[20];
};

struct etudiantInfo {
    char id[100];
    char nom[20];
    char prenom[30];
    char departement[40];
    char noteGenerale[100];
    struct etudiantDate dateNaissance;
};

void ajouterEtudiant(struct etudiantInfo etudiants[], int nb) {
    printf("Entrez l'ID de l'étudiant: ");
    scanf("%s", etudiants[nb].id);
    printf("\nEntrez le prénom: ");
    scanf("%s", etudiants[nb].prenom);
    printf("\nEntrez le nom: ");
    scanf("%s", etudiants[nb].nom);
    printf("\nEntrez la date de naissance (Jour Mois Annee): ");
    scanf("%s %s %s", etudiants[nb].dateNaissance.jour, etudiants[nb].dateNaissance.mois, etudiants[nb].dateNaissance.annee);
    printf("\nEntrez le département: ");
    scanf("%s", etudiants[nb].departement);
    printf("\nEntrez la note: ");
    scanf("%s", etudiants[nb].noteGenerale);
}

void affichage(struct etudiantInfo etudiants[], int nombreEtudiants) {
    for(int i = 0; i < nombreEtudiants; i++) {
        printf("\nEtudiant [%d] inormations: \n", i + 1);
        printf("id: %s\n", etudiants[i].id);
        printf("prenom: %s\n", etudiants[i].prenom);
        printf("nom: %s\n", etudiants[i].nom);
        printf("date de naissance: %s/%s/%s\n", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
        printf("departement: %s\n", etudiants[i].departement);
        printf("note general: %s\n", etudiants[i].noteGenerale);
        printf("____________________________");
    }
}

int main() {
    int nb = 0;
    struct etudiantInfo etudiants[100]; // Adjust size as needed

    int choix;
    do {
        printf("\n1. Ajouter un étudiant\n");
        printf("2. Afficher tous les étudiants\n");
        printf("0. Quitter\n");

        printf("\nChoisissez une option: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                ajouterEtudiant(etudiants, nb);
                nb++;
                break;
            case 2:
                affichage(etudiants, nb);
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("\nEntrer un nombre entre 1 - 2\n");
                break;
        }
    } while(choix != 0);

    return 0;
}
