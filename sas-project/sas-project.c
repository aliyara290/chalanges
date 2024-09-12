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
    printf("\nEntrez l'ID de l'étudiant: ");
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
    switch (depChoix)
    {
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
    printf("Entrez la note: ");
    scanf("%f", &etudiants[nb].noteGenerale);
}

void affichage(struct etudiantInfo etudiants[], int nb)
{
    for (int i = 0; i < nb; i++)
    {
        printf("**Etudiant ID-%d informations:\n", etudiants[i].id);
        printf("ID: %d\n", etudiants[i].id);
        printf("Prenom: %s\n", etudiants[i].prenom);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Date de naissance: %s/%s/%s\n", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
        printf("Departement: %s\n", etudiants[i].departement);
        printf("Note general: %.1f\n", etudiants[i].noteGenerale);
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

int deleteEtudiant(struct etudiantInfo etudiants[], int nb)
{
    int studentId, found = 0;
    printf("Enter etudiant ID: ");
    scanf("%d", &studentId);

    for (int i = 0; i < nb; i++)
    {
        if (etudiants[i].id == studentId)
        {
            found = 1;
            for (int j = i; j < nb - 1; j++)
            {
                etudiants[j] = etudiants[j + 1];
            }
            nb--;
            printf("Etudiant deleted successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Etudiant with ID %d not found.\n", studentId);
    }

    return nb;
}

void rechercherEtudiant(struct etudiantInfo etudiants[], int nb)
{
    char etudiantNom[40];
    printf("Entrer le nom de etudiant: ");
    scanf("%s", etudiantNom);
    for (int i = 0; i < nb; i++)
    {
        if (strcmp(etudiants[i].nom, etudiantNom) == 0)
        {
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
        else
        {
            printf("No etudiant avec c'est nom!");
        }
    }
}

void afficherSpcDepart(struct etudiantInfo etudiants[], int nb)
{
    int choix;
    printf("\n1. Pour afficher Web Development departement.\n");
    printf("2. Pour afficher Data Science departement.\n");
    printf("3. Pour afficher DevOps departement.\n");
    printf("4. Pour afficher Ai departement.\n");
    printf("Enter a departement numero: ");
    scanf("%d", &choix);

    char depSelected[30];
    int found = 0;

    switch (choix)
    {
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

    for (int i = 0; i < nb; i++)
    {
        if (strcmp(etudiants[i].departement, depSelected) == 0)
        {
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

    if (!found)
    {
        printf("Aucun étudiant trouvé dans le département %s.\n", depSelected);
    }
}

void afficherNumEtdDepart(struct etudiantInfo etudiants[], int nb)
{
    int choix;
    printf("\n1. Pour afficher nomber de etudiants dans Web Development departement.\n");
    printf("2. Pour afficher nomber de etudiants dans Data Science departement.\n");
    printf("3. Pour afficher nomber de etudiants dans DevOps departement.\n");
    printf("4. Pour afficher nomber de etudiants dans Ai departement.\n");
    printf("Enter a departement numero: ");
    scanf("%d", &choix);

    char depSelected[30];
    int total = 0;
    int count = 0;
    int found = 0;

    switch (choix)
    {
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

    for (int i = 0; i < nb; i++)
    {
        if (strcmp(etudiants[i].departement, depSelected) == 0)
        {
            count++;
        }
    }
    if (count == 0)
    {
        printf("\nNo etudiant dans c'est departement!");
    }
    else
    {
        total = count;
        printf("\nTotal number de etudiant dans %s departement est: %d", depSelected, total);
    }
}

void moyenneGenDepart(struct etudiantInfo etudiants[], int nb)
{
    int deptChoix;
    printf("1. pour afficher la moyenne general de Web Development departement.\n");
    printf("2. pour afficher la moyenne general de Data Science departement.\n");
    printf("3. pour afficher la moyenne general de DevOps departement.\n");
    printf("4. pour afficher la moyenne general de Ai departement.\n");
    printf("Entrer votre choix: ");
    scanf("%d", &deptChoix);

    float somme = 0;
    int count = 0;
    char depSelected[30];

    // Select department based on user choice
    switch (deptChoix)
    {
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

    for (int i = 0; i < nb; i++)
    {
        if (strcmp(etudiants[i].departement, depSelected) == 0)
        {
            somme += etudiants[i].noteGenerale;
            count++;
        }
    }
    if (count == 0)
    {
        printf("\nAucun étudiant trouvé dans le département %s.\n", depSelected);
    }
    else
    {
        float noteGeneral = somme / count;
        printf("\nLa note generale de %s departement est: %.2f\n", depSelected, noteGeneral);
    }
}

void moyenneUnivers(struct etudiantInfo etudiants[], int nb)
{
    float somme = 0;
    float notesGeneral = 0;
    for (int i = 0; i < nb; i++)
    {
        somme += etudiants[i].noteGenerale;
    }
    notesGeneral = somme / nb;
    printf("\nLa moyenne generale l\'université entière est: %.2f\n", notesGeneral);
}

void moyenneGeneral(struct etudiantInfo etudiants[], int nb)
{
    int moyChoix;
    printf("1. pour afficher la moyenne de chaque departement.\n");
    printf("2. pour afficher la moyenne de l\'université entière.\n");
    printf("\nEntrer votre choix: ");
    scanf("%d", &moyChoix);
    switch (moyChoix)
    {
    case 1:
        moyenneGenDepart(etudiants, nb);
        break;
    case 2:
        moyenneUnivers(etudiants, nb);
        break;
    default:
        printf("Entrer numero 1 ou 2");
        return;
    }
}

void meilleursTrois(struct etudiantInfo etudiants[], int nb)
{
    struct etudiantInfo temp;
    for (int i = 0; i < nb - 1; i++)
    {
        for (int j = i + 1; j < nb; j++)
        {
            if (etudiants[i].noteGenerale < etudiants[j].noteGenerale)
            {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("\nLes trois meilleurs étudiants:\n");
    for (int i = 0; i < 3 && i < nb; i++)
    {
        printf("\n**Etudiant ID-%d informations:\n", etudiants[i].id);
        printf("Prenom: %s\n", etudiants[i].prenom);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Departement: %s\n", etudiants[i].departement);
        printf("Note general: %.2f\n", etudiants[i].noteGenerale);
        printf("----------------------\n");
    }
}

void totalEtudiants(struct etudiantInfo etudiants[], int nb)
{
    int total = 0;

    for (int i = 0; i < nb; i++)
    {
        total = nb;
    }
    printf("\nLe nombre total de etudiants est: %d", total);

    if (nb == 0)
    {
        printf("\nIl n'y a pas d'étudiants");
    }
}

void nomberReussi(struct etudiantInfo etudiants[], int nb)
{
    int choix;
    printf("\n1. Pour afficher le nombre d'étudiants ayant réussi dans le département Web Development.\n");
    printf("2. Pour afficher le nombre d'étudiants ayant réussi dans le département Data Science.\n");
    printf("3. Pour afficher le nombre d'étudiants ayant réussi dans le département DevOps.\n");
    printf("4. Pour afficher le nombre d'étudiants ayant réussi dans le département AI.\n");
    printf("Entrez un numéro de département: ");
    scanf("%d", &choix);

    char depSelected[30];
    int total = 0;

    switch (choix)
    {
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
        printf("Veuillez entrer un numéro entre 1 et 4!\n");
        return;
    }

    for (int i = 0; i < nb; i++)
    {
        if (strcmp(etudiants[i].departement, depSelected) == 0 && etudiants[i].noteGenerale >= 10)
        {
            total++;
        }
    }

    if (total == 0)
    {
        printf("\nAucun étudiant n'a réussi dans ce département!\n");
    }
    else
    {
        printf("\nLe nombre total d'étudiants ayant réussi dans le département %s est: %d\n", depSelected, total);
    }
}

void afficherEttSyp(struct etudiantInfo etudiants[], int nb)
{
    float userInput;
    printf("\nEntrez un nombre pour indiquer le nombre d'élèves qui ont obtenu une note supérieure à celle-ci: ");
    scanf("%f", &userInput);

    for (int i = 0; i < nb; i++)
    {
        if (etudiants[i].noteGenerale > userInput)
        {
            printf("\n**Etudiant ID-%d informations:\n", etudiants[i].id);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note general: %.2f\n", etudiants[i].noteGenerale);
            printf("----------------------\n");
        }
        else
        {
            printf("\nIl n\'y a aucun étudiant avec une moyenne cumulative supérieure à %.2f\n", userInput);
        }
    }
}

void triNoms(struct etudiantInfo etudiants[], int nb)
{
    struct etudiantInfo temp;
    int choix;

    printf("\n1. Trier les noms de A à Z\n");
    printf("2. Trier les noms de Z à A\n");
    printf("Choisissez une option: ");
    scanf("%d", &choix);
    int c = 0;
    for (int i = 0; i < nb - 1; i++)
    {
        for (int j = i + 1; j < nb; j++)
        {
            if (choix == 1 && strcmp(etudiants[i].nom, etudiants[j].nom) > 0)
            {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
            else if (choix == 2 && strcmp(etudiants[i].nom, etudiants[j].nom) < 0)
            {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
            c++;
        }
    }
    printf("\ncomlexity: %d\n", c);
    printf("\nListe des étudiants triés:\n");
    for (int i = 0; i < nb; i++)
    {
        printf("Nom: %s, Prénom: %s\n", etudiants[i].nom, etudiants[i].prenom);
    }
}

int main()
{
    int nb = 0;
    struct etudiantInfo etudiants[100];

    int choix;
    do
    {
        printf("\n1. Ajouter un étudiant: \n");                                                // done
        printf("2. Modifier un étudiant: \n");                                                 // done
        printf("3. Supprimer un étudiant: \n");                                                // done
        printf("4. Afficher tous les étudiants: \n");                                          // done
        printf("5. Rechercher un étudiant par nom: \n");                                       // done
        printf("6. Afficher la liste des étudiants dans un département spécifique: \n");       // done
        printf("7. Afficher les étudiants dans chaque département: \n");                       // done
        printf("8. Afficher les M-G par chaque département et de l\'université entière.: \n"); // done
        printf("9. Afficher les 3 meilleurs étudiants: \n");                                   // done
        printf("10. Afficher le nomber de etudiants dans la université: \n");                  // done
        printf("11. Afficher le nomber des étudiants ayant réussi: \n");                       // done
        printf("12. Afficher les étudiants ayant une M-G supérieure à un certain seuil.: \n");
        printf("13. Trier les étudiants par nom: \n");
        printf("14. Trier les étudiants par niveau: \n");
        printf("15. Trier les étudiants par statut: \n");
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
            nb = deleteEtudiant(etudiants, nb);
            break;
        case 4:
            affichage(etudiants, nb);
            break;
        case 5:
            rechercherEtudiant(etudiants, nb);
            break;
        case 6:
            afficherSpcDepart(etudiants, nb);
            break;
        case 7:
            afficherNumEtdDepart(etudiants, nb);
            break;
        case 8:
            moyenneGeneral(etudiants, nb);
            break;
        case 9:
            meilleursTrois(etudiants, nb);
            break;
        case 10:
            totalEtudiants(etudiants, nb);
            break;
        case 11:
            nomberReussi(etudiants, nb);
            break;
        case 12:
            afficherEttSyp(etudiants, nb);
            break;
        case 13:
            triNoms(etudiants, nb);
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