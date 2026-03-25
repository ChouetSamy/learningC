#include <stdio.h>

/*
 * ALGORITHME : SELECTION SORT (TRI PAR SÉLECTION)
 * 
 * Idée générale :
 * - À chaque itération, trouver le PLUS PETIT élément
 *   dans la partie non triée du tableau
 * - Placer ce plus petit élément au début
 * - Répéter avec le reste du tableau
 * 
 * Exemple avec [5, 2, 9, 1, 5, 6] :
 * Étape 0 : Chercher le min : 1 -> [1, 2, 9, 5, 5, 6]
 * Étape 1 : Chercher le min : 2 -> [1, 2, 9, 5, 5, 6]
 * Étape 2 : Chercher le min : 5 -> [1, 2, 5, 9, 5, 6]
 * Étape 3 : Chercher le min : 5 -> [1, 2, 5, 5, 9, 6]
 * Étape 4 : Chercher le min : 6 -> [1, 2, 5, 5, 6, 9]
 * 
 * Complexité : O(n²) toujours - pas efficace mais simple à comprendre
 */

void selectionSort(int tab[], int n) {
    // Boucle principale : on va construire le tableau trié de gauche à droite
    // À chaque itération i, les éléments [0...i-1] sont déjà triés
    for (int i = 0; i < n - 1; i++) {
        
        // Supposer que l'élément à l'index i est le plus petit
        // (de la partie non triée)
        int min_idx = i;
        
        // Chercher le VRAI minimum dans la partie non triée
        // Parcourir de i+1 jusqu'à la fin du tableau
        for (int j = i + 1; j < n; j++) {
            
            // Si on trouve un élément PLUS PETIT que le supposé minimum
            if (tab[j] < tab[min_idx]) {
                // Mettre à jour min_idx : c'est la nouvelle position du minimum
                min_idx = j;
            }
        }
        
        // À ce stade, min_idx contient l'index du plus petit élément trouvé
        // Maintenant, ÉCHANGER tab[i] et tab[min_idx] pour placer le minimum
        // à sa bonne position
        
        // Sauvegarder tab[i] pour ne pas le perdre
        int tmp = tab[i];
        // Mettre le minimum à la position i
        tab[i] = tab[min_idx];
        // Mettre l'ancienne valeur de tab[i] à la position du minimum
        tab[min_idx] = tmp;
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
    int n = sizeof(tab)/sizeof(tab[0]);

    // Afficher le tableau AVANT le tri
    printf("Avant tri : ");
    printArray(tab, n);

    // Appeler la fonction de tri par sélection
    selectionSort(tab, n);

    // Afficher le tableau APRÈS le tri
    printf("Après tri : ");
    printArray(tab, n);

    return 0;
}