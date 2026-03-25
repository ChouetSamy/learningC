#include <stdio.h>

/*
 * ALGORITHME : BUBBLE SORT (TRI À BULLES)
 * 
 * Idée générale :
 * - Parcourir le tableau plusieurs fois
 * - À chaque passage, comparer deux éléments voisins
 * - Si l'élément de gauche > élément de droite, les inverser
 * - Le plus grand élément « remonte » vers la fin comme une bulle
 * - Répéter jusqu'à ce que le tableau soit trié
 * 
 * Exemple avec [5, 2, 9, 1, 5, 6] :
 * Pass 1 : [2, 5, 1, 5, 6, 9]  <- 9 est à sa place
 * Pass 2 : [2, 1, 5, 5, 6, 9]  <- 6 est à sa place
 * Pass 3 : [1, 2, 5, 5, 6, 9]  <- complètement trié
 * 
 * Complexité : O(n²) - lent pour les grands tableaux
 */

void bubbleSort(int tab[], int n) {
    // Boucle externe : chaque passage dans le tableau
    // On fait (n-1) passages car après chaque passage, le plus grand élément est à sa place
    for (int i = 0; i < n - 1; i++) {
        
        // Boucle interne : comparer les éléments voisins
        // On compare jusqu'à (n-1-i) car les derniers i éléments sont déjà triés
        for (int j = 0; j < n - 1 - i; j++) {
            
            // Si l'élément actuel est PLUS GRAND que le suivant : c'est mal trié
            if (tab[j] > tab[j + 1]) {
                
                // ÉCHANGE les deux éléments :
                // 1. Sauvegarder la valeur de tab[j] dans une variable temporaire
                int tmp = tab[j];
                // 2. Mettre la valeur de tab[j+1] à la place de tab[j]
                tab[j] = tab[j + 1];
                // 3. Mettre la valeur sauvegardée à la place de tab[j+1]
                tab[j + 1] = tmp;
            }
        }
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
    
    // Calcul du nombre d'éléments : sizeof(tab) / sizeof(tab[0])
    // sizeof(tab) = taille totale du tableau en octets
    // sizeof(tab[0]) = taille d'un élément (un int) en octets
    int n = sizeof(tab) / sizeof(tab[0]);

    // Afficher le tableau AVANT le tri
    printf("Tableau avant le tri : ");
    printArray(tab, n);

    // Appeler la fonction de tri bubble sort
    bubbleSort(tab, n);

    // Afficher le tableau APRÈS le tri
    printf("Tableau après le tri : ");
    printArray(tab, n);

    return 0;
}