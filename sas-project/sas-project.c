#include <stdio.h>
#include <string.h>

struct etudiantDate
{
    char jour[20];
    char mois[20];
    char annee[20];
};

struct etudiantInfo
{
    int id;
    char nom[20];
    char prenom[30];
    char departement[100];
    float noteGenerale;
    struct etudiantDate dateNaissance;
};
void ajouterEtudiant(struct etudiantInfo etudiants[], int nb)
{
    int depChoix;
    printf("Entrez l'ID de l'étudiant: ");
    scanf("%d", &etudiants[nb].id);
    printf("Entrez le prénom: ");
    scanf("%s", etudiants[nb].prenom);
    printf("Entrez le nom: ");
    scanf("%s", etudiants[nb].nom);
    printf("Entrez la date de naissance (JJ/MM/AAAA): ");
    scanf("%s %s %s", etudiants[nb].dateNaissance.jour, etudiants[nb].dateNaissance.mois, etudiants[nb].dateNaissance.annee);
    printf("Choisissez l'une de ces departement:\n");
    printf("1. Développement Web.\n");
    printf("2. Data Science.\n");
    printf("3. DevOps.\n");
    printf("4. Ai.\n");
    printf("Departement: ");
    scanf("%d", &depChoix);
    switch(depChoix) {
        case 1:
        strcpy(etudiants[nb].departement, "dev");
        break;
        case 2:
        strcpy(etudiants[nb].departement, "data");
        break;
        case 3:
        strcpy(etudiants[nb].departement, "devops");
        break;
        case 4:
        strcpy(etudiants[nb].departement, "ai");
        break;
        default:
        printf("Entrer numero entre 1 et 4!.");
        break;
    }
    // printf("Entrez le département: ");
    // scanf("%s", etudiants[nb].departement);
    printf("Entrez la note: ");
    scanf("%d", &etudiants[nb].noteGenerale);
}

void affichage(struct etudiantInfo etudiants[], int nb)
{
    for (int i = 0; i < nb; i++)
    {
        printf("**Etudiant ID-%d informations:\n", etudiants[i].id);
        printf("ID: %d\n", etudiants[i].id);
        printf("Prenom: %s\n", etudiants[i].prenom);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Date de naissance: %s\n", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
        printf("Departement: %s\n", etudiants[i].departement);
        printf("Note general: %d\n", etudiants[i].noteGenerale);
        printf("----------------------\n");
    }
    return;
}

void modification(struct etudiantInfo etudiants[], int nb)
{
    int studentId, moChoix;
    printf("Entrer student ID: ");
    scanf("%d", &studentId);
    printf("\n1. pour modifie le prenom.\n");
    printf("2. pour modifie le nom.\n");
    printf("3. pour modifie le date de naissance.\n");
    printf("4. pour modifie le departement.\n");
    printf("5. pour modifie le note general.\n");
    printf("\nentrez un numéro que vous souhaitez modifier: ");
    scanf("%d", &moChoix);

    switch (moChoix)
    {
    case 1:
        for (int i = 0; i < nb; i++)
        {
            if (etudiants[i].id == studentId)
            {
                printf("Entrez le nouveau prénom: ");
                scanf("%s", etudiants[i].prenom);
                printf("changer avec succès.!\n");
                return;
            }
        }
        break;
    case 2:
        for (int i = 0; i < nb; i++)
        {
            if (etudiants[i].id == studentId)
            {
                printf("Entrez le nouveau nom: ");
                scanf("%s", etudiants[i].nom);
                printf("changer avec succès.!\n");
                return;
            }
        }
        break;
    case 3:
        for (int i = 0; i < nb; i++)
        {
            if (etudiants[i].id == studentId)
            {
                printf("Entrez la nouvelle date de naissance (JJ/MM/AAAA): ");
                scanf("%s", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
                printf("changer avec succès.!\n");
                return;
            }
        }
        break;
    case 4:
        for (int i = 0; i < nb; i++)
        {
            if (etudiants[i].id == studentId)
            {
                printf("Entrez le nouveau département: ");
                scanf("%s", etudiants[i].departement);
                printf("changer avec succès.!\n");
                return;
            }
        }
        break;
    case 5:
        for (int i = 0; i < nb; i++)
        {
            if (etudiants[i].id == studentId)
            {
                printf("Entrez la nouvelle note: ");
                scanf("%d", &etudiants[i].noteGenerale);
                printf("changer avec succès.!\n");
                return;
            }
        }
        break;
    default:
        printf("Entrer un numero entre 1 a 5!");
        break;
    }
    printf("Étudiant avec ID %d non trouvé !", studentId);
}

void deleteEtudiant(struct etudiantInfo etudiants[], int nb) {
    int studentId;
    printf("Enter etudiant ID: ");
    scanf("%d", &studentId);

    for(int i = 0; i < nb; i++) {
        if(etudiants[i].id == studentId) {
            for(int j = i; j < nb - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            printf("Contact deleted successfully.\n");
        }
    }
   
}

void modifieEtSupp(struct etudiantInfo etudiants[], int nb) {
    int options;
    printf("\n1. Pour Modifie un etudiant.\n");
    printf("2. Pour supprimer un etudiant.\n");
    printf("Entrer votre choix:");
    scanf("%d", &options);

    switch(options) {
        case 1:
        modification(etudiants, nb);
        break;
        case 2:
        deleteEtudiant(etudiants, nb);
        nb--;
        break;
        default:
        printf("Entrer 1 ou 2");
        break;
    }
}

void rechercherEtudiant(struct etudiantInfo etudiants[], int nb) {
    char etudiantNom[40];
    printf("Entrer le nom de etudiant: ");
    scanf("%s", etudiantNom);
    for(int i = 0; i < nb; i++) {
        if(strcmp(etudiants[i].nom, etudiantNom) == 0) {
            printf("\n------------------------\n");
            printf("**Etudiant ID-%d informations:\n", etudiants[i].id);
            printf("id: %d\n", etudiants[i].id);
            printf("nom: %s\n", etudiants[i].nom);
            printf("prenom: %s\n", etudiants[i].prenom);
            printf("date de naissance: %s\n", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
            printf("departement: %s\n", etudiants[i].departement);
            printf("note general: %d\n", etudiants[i].noteGenerale);
            printf("------------------------\n");
            return; 
        }
        else {
            printf("No etudiant avec c'est nom!");
        }
    }
}

void afficherSpcDepart(struct etudiantInfo etudiants[], int nb) {
    int choix;
    printf("\n1. Pour afficher Web Development departement.\n");
    printf("2. Pour afficher Data Science departement.\n");
    printf("3. Pour afficher DevOps departement.\n");
    printf("4. Pour afficher Ai departement.\n");
    printf("Enter a departement numero: ");
    scanf("%d", &choix);

    char depSelected[30];
    int found = 0;

    switch(choix) {
        case 1:
            strcpy(depSelected, "dev");
            break;
        case 2:
            strcpy(depSelected, "data");
            break;
        case 3:
            strcpy(depSelected, "devops");
            break;
        case 4:
            strcpy(depSelected, "ai");
            break;
        default:
            printf("Entrer numero entre 1 et 4!\n");
            return;
    }


    for(int i = 0; i < nb; i++) {
        if(strcmp(etudiants[i].departement, depSelected) == 0) {
            printf("\nÉtudiants du département de %s: \n", depSelected);
            printf("**Etudiant ID-%d informations:\n", etudiants[i].id);
            printf("id: %d\n", etudiants[i].id);
            printf("nom: %s\n", etudiants[i].nom);
            printf("prenom: %s\n", etudiants[i].prenom);
            printf("date de naissance: %s/%s/%s\n", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
            printf("departement: %s\n", etudiants[i].departement);
            printf("note general: %d\n", etudiants[i].noteGenerale);
            printf("------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun étudiant trouvé dans le département %s.\n", depSelected);
    }
}


// pour afficher la moyenne de chaque departement
void moyenneGenDepart(struct etudiantInfo etudiants[], int nb) {
    int deptChoix;
    printf("1. pour afficher la moyenne general de Web Development departement.\n");
    printf("2. pour afficher la moyenne general de Data Science departement.\n");
    printf("3. pour afficher la moyenne general de DevOps departement.\n");
    printf("4. pour afficher la moyenne general de Ai departement.\n");
    printf("Entrer votre choix: ");
    scanf("%d", &deptChoix);
    float somme = 0;
    float noteGeneral = 0;
    char depSelected[30];
    int found = 0;

    switch(deptChoix) {
        case 1:
            strcpy(depSelected, "dev");
            break;
        case 2:
            strcpy(depSelected, "data");
            break;
        case 3:
            strcpy(depSelected, "devops");
            break;
        case 4:
            strcpy(depSelected, "ai");
            break;
        default:
            printf("Entrer numero entre 1 et 4!\n");
            return;
    }

    for(int i = 0; i < nb; i++) {
        if(strcmp(etudiants[i].departement, depSelected) == 0) {
            somme += etudiants[i].noteGenerale;
            found = 1;
            noteGeneral = somme;
            printf("\nLa note general de %s departement est: %d", depSelected, noteGeneral);
        }
    }

    if(!found) {
        printf("\nNo etudiant exist.");
    }
}

void moyenneGeneral(struct etudiantInfo etudiants[], int nb) {
    int moyChoix;
    printf("1. pour afficher la moyenne de chaque departement.\n");
    printf("2. pour afficher la moyenne de l\'université entière.\n");
    printf("\nEntrer votre choix: ");
    scanf("%d", &moyChoix);
    switch(moyChoix) {
        case 1:
        moyenneGenDepart(etudiants, nb);
        break;
        case 2:
        // pour afficher la moyenne de l’université entière.
        break;
        default:
        printf("Entrer numero 1 ou 2");
        return;
    }

}
int main()
{
    int nb = 0;
    struct etudiantInfo etudiants[100];

    int choix;
    do
    {
        printf("\n1. Ajouter un étudiant: \n");
        printf("2. Modifier ou Supprimer un étudiant: \n");
        printf("3. Afficher tous les étudiants: \n");
        printf("4. Rechercher un étudiant par nom: \n");
        printf("5. Afficher la liste des étudiants dans un département spécifique: \n");
        printf("6. Afficher les étudiants par département: \n");
        printf("7. Afficher les moyenne general par chaque par département et de l’université entière.: \n");
        printf("8. Afficher les 3 meilleurs étudiants: \n");
        printf("9. Afficher les étudiants ayant réussi: \n");
        printf("10. Trier les étudiants par nom: \n");
        printf("11. Trier les étudiants par niveau: \n");
        printf("12. Trier les étudiants par statut: \n");
        printf("0. Quitter\n");
        printf("\nChoisissez une option: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterEtudiant(etudiants, nb);
            nb++;
            break;
        case 2:
            printf("Hello world number is : %d", nb);
            modifieEtSupp(etudiants, nb);
            break;
        case 3:
            affichage(etudiants, nb);
            break;
        case 4:
            rechercherEtudiant(etudiants, nb);
            break;
        case 5:
            afficherSpcDepart(etudiants, nb);
            break;
        case 6:
            // afficherParDep(etudiants, nb);
            break;
        case 7:
            moyenneGeneral(etudiants, nb);
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
    } while (choix != 0);

    return 0;
}