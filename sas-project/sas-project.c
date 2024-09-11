#include <stdio.h>

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
    char departement[40];
    int noteGenerale;
    struct etudiantDate dateNaissance;
};

int ajouterEtudiant(struct etudiantInfo etudiants[], int nb)
{
    printf("Entrez l'ID de l'étudiant: ");
    scanf("%d", &etudiants[nb].id);
    printf("Entrez le prénom: ");
    scanf("%s", etudiants[nb].prenom);
    printf("Entrez le nom: ");
    scanf("%s", etudiants[nb].nom);
    printf("Entrez la date de naissance (JJ/MM/AAAA): ");
    scanf("%s %s %s", etudiants[nb].dateNaissance.jour, etudiants[nb].dateNaissance.mois, etudiants[nb].dateNaissance.annee);
    printf("Entrez le département: ");
    scanf("%s", etudiants[nb].departement);
    printf("Entrez la note: ");
    scanf("%d", &etudiants[nb].noteGenerale);
}

void affichage(struct etudiantInfo etudiants[], int nb)
{
    for (int i = 0; i < nb; i++)
    {
        printf("id: %d\n", etudiants[i].id);
        printf("prenom: %s\n", etudiants[i].prenom);
        printf("nom: %s\n", etudiants[i].nom);
        printf("date de naissance: %s\n", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
        printf("departement: %s\n", etudiants[i].departement);
        printf("note general: %d\n", etudiants[i].noteGenerale);
    }
    return;
}

void modification(struct etudiantInfo etudiants[], int nb)
{
    int studentId, moChoix;
    printf("Entrer etudiant ID pour modifie: ");
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

int main()
{
    int nb = 0;
    struct etudiantInfo etudiants[100];

    int choix;
    do
    {
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

        switch (choix)
        {
        case 1:
            ajouterEtudiant(etudiants, nb);
            nb++;
            break;
        case 2:
            modification(etudiants, nb);
            break;
        case 3:
            break;
        case 4:
            affichage(etudiants, nb);
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
    } while (choix != 0);

    return 0;
}