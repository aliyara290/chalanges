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
void ajouterEtudiant(struct etudiantInfo etudiants[]) {
    printf("Entrez l'ID de l'étudiant: \n");
    scanf("%s", etudiants->id);
    printf("Entrez le prénom: \n");
    scanf("%s", etudiants->prenom);
    printf("Entrez le nom: \n");
    scanf("%s", etudiants->nom);
    printf("Entrez la date de naissance (JJ/MM/AAAA): \n");
    scanf("%s %s %s", etudiants->dateNaissance.jour, etudiants->dateNaissance.mois, etudiants->dateNaissance.annee);
    printf("Entrez le département: \n");
    scanf("%s", etudiants->departement);
    printf("Entrez la note: \n");
    scanf("%s", etudiants->noteGenerale);
}

void affichage(struct etudiantInfo etudiants[]) {
    for(int i = 0; i < etudiants[]; i++) {
        printf("id: %s", etudiants[i].id);
        printf("prenom: %s", etudiants[i].prenom);
        printf("nom: %s", etudiants[i].nom);
        printf("date de naissance: %s", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
        printf("departement: %s", etudiants[i].departement);
        printf("note general: %s", etudiants[i].noteGenerale);
    }
    return;
}

int main() {

    struct etudiantInfo etudiants[]; 

    int choix;
    do{
        printf("\n1. Ajouter un étudiant: \n");
        printf("2. Modifier un étudiant: \n");
        printf("3. Supprimer un étudiant: \n");
        printf("4. Afficher tous les étudiants: \n");
        printf("5. Rechercher un étudiant par nom: \n");
        printf("6. Afficher les étudiants par département: \n");
        printf("7. Afficher les 3 meilleurs étudiants: \n");
        printf("8. Afficher les étudiants ayant réussi: \n");
        printf("9. Trier les étudiants par nom: \n");
        printf("10. Trier les étudiants par niveau: \n");
        printf("11. Trier les étudiants par statut: \n");
        printf("0. Quitter\n");

        printf("\nChoisissez une option: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
            ajouterEtudiant(etudiants);
            break;
            case 2:
            affichage(etudiants);
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 10:
            break;
            case 11:
            break;
            case 0:
            printf("Au revoir!");
            break;

            default:
            printf("\nEntrer nomber entre 1 - 11\n");
            break;
        }
    } while(choix != 0);

    return 0;
}