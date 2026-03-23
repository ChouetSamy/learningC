#include <stdio.h>
#include <string.h>

int main() {
    // Déclaration des questions et réponses
    // Chaque string peut contenir jusqu'à 99 caractères + '\0'
    char questions[3][100] = {
        "Quelle est la capitale de la France ?\n",
        "Quel est le résultat de 2 + 2 ?\n",
        "Qui a écrit 'Le Petit Prince' ?\n"
    };

    char answers[3][100] = {
        "Paris\n",
        "4\n",
        "Antoine de Saint-Exupéry\n"
    };

    char userAnswer[100]; // Variable pour stocker la réponse de l'utilisateur
    int count = 3;        // Nombre de questions

    for (int i = 0; i < count; i++) {
        printf("%s", questions[i]);             // Affiche la question
        fgets(userAnswer, sizeof(userAnswer), stdin);  // Lit toute la ligne entrée par l'utilisateur (inclut '\n')

        // strcmp compare les chaînes. Retourne 0 si elles sont exactement identiques
        if (strcmp(userAnswer, answers[i]) == 0) {
            printf("Bonne réponse !\n");
        } else {
            printf("Mauvaise réponse !\n");
        }
    }

    return 0;
}

/*
💡 Schéma mental des tableaux et boucle :

questions[3][100]      answers[3][100]      userAnswer[100]
+----------------+     +----------------+    +------------+
| "Quelle est ...\n"| ->| "Paris\n"      |    | (vide au début)
+----------------+     +----------------+    +------------+
| "Quel est ...\n" | ->| "4\n"          |
+----------------+     +----------------+
| "Qui a écrit ...\n"|->| "Antoine de ...\n" |
+----------------+     +----------------+

Boucle for (i = 0; i < 3; i++) :
- i = 0 : affiche questions[0], lit userAnswer, compare avec answers[0]
- i = 1 : affiche questions[1], lit userAnswer, compare avec answers[1]
- i = 2 : affiche questions[2], lit userAnswer, compare avec answers[2]

Chaque index i assure la correspondance question ↔ réponse.
*/