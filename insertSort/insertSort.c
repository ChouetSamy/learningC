#include <stdio.h>

/*
 * ALGORITHME : INSERTION SORT (TRI PAR INSERTION)
 * 
 * Idée générale (comme trier des cartes à la main) :
 * - Supposer que le premier élément est trié
 * - Pour chaque élément suivant (la « clé »)
 *   -> Trouver sa bonne position dans la partie triée
 *   -> Décaler les éléments plus grands vers la droite
 *   -> Insérer la clé à sa place
 * - Répéter jusqu'au bout
 * 
 * Exemple avec [5, 2, 9, 1, 5, 6] :
 * Étape 0 : [5] - partie triée
 * Étape 1 : [2, 5] - on insère 2 à gauche
 * Étape 2 : [2, 5, 9] - on insère 9 à droite
 * Étape 3 : [1, 2, 5, 9] - on insère 1 tout à gauche
 * Étape 4 : [1, 2, 5, 5, 9] - on insère 5
 * Étape 5 : [1, 2, 5, 5, 6, 9] - on insère 6
 * 
 * Complexité : O(n²) en général, mais O(n) si presque trié - très efficace pour ça !
 */

void insertionSort(int tab[], int n) {
    // Boucle principale : à partir de l'index 1 (car index 0 est déjà "trié")
    for (int i = 1; i < n; i++) {
        
        // Sauvegarder l'élément qu'on doit insérer
        int key = tab[i];
        
        // j représente l'index du dernier élément de la partie triée
        // (avant l'élément qu'on veut insérer)
        int j = i - 1;

        // Tant que :
        // - On n'est pas arrivé au début du tableau (j >= 0)
        // - ET que l'élément actuel de la partie triée est PLUS GRAND que la clé
        // -> On décale cet élément vers la droite
        while (j >= 0 && tab[j] > key) {
            // Décaler l'élément d'une position vers la droite
            // Cela crée une place vide où on pourra mettre la clé
            tab[j + 1] = tab[j];
            
            // Revenir à l'élément précédent dans la partie triée
            j--;
        }

        // Maintenant j+1 est la bonne position pour insérer la clé
        // Tous les éléments à gauche sont plus petits que la clé
        // Tous les éléments à droite (qu'on a décalés) sont plus grands
        tab[j + 1] = key;
    }
}

// Fonction pour afficher le tableau sur une seule ligne
void printArray(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int main() {
    // Créer un tableau d'entiers à trier
    int tab[] = {5, 2, 9, 1, 5, 6};
    
    // Calcul du nombre d'éléments
    int n = sizeof(tab) / sizeof(tab[0]);

    // Afficher le tableau AVANT le tri
    printf("Tableau avant le tri : ");
    printArray(tab, n);

    // Appeler la fonction de tri par insertion
    insertionSort(tab, n);

    // Afficher le tableau APRÈS le tri
    printf("Tableau après le tri : ");
    printArray(tab, n);

    return 0;
}