#include <stdint.h> 
#include <stdio.h> 
#include "../includes/users.h"


unsigned afficherEcran1(){
    int response = 0;
    printf("------------- BIENVENUE -------------\n");
    printf("=====================================\n");
    printf("   1. Se connecter\n");
    printf("   2. S'inscrire\n");
    printf("   3. Quitter\n\n");
    printf("   >  ");
    scanf("%d", &response);

    printf("=====================================\n");
    printf("-------------- Voiture --------------\n");
    
    return response;
}

unsigned login(char *erreur) {
    char username[25];
    char password[25];
    unsigned connected = 0;

    printf("------------- CONNEXION -------------\n");
    printf("=====================================\n");
    printf("Login: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    return authenticateUser(username, password, "../ressources/users.txt", erreur);
}

unsigned signin(char *erreur) {
    char username[25];
    char password[25];

    printf("---------- CREER UN COMPTE ----------\n");
    printf("=====================================\n");

    printf("Username: ");
    scanf("%s", username);

    if (!userExist(username, "../ressources/users.txt", erreur)) {
        printf("Password: ");
        scanf("%s", password);
        encryptPassword(password);
        createNewUser(username, "../ressources/users.txt", password, erreur);
        return 1;
    }
    return 0;
}