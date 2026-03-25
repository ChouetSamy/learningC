#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray/dynamicArray.h"

int main() {
    t_node* head_list = NULL; // Initialisation de la liste vide

    // Test des fonctions
    append(&head_list, 10);
    append(&head_list, 20);
    append(&head_list, 30);
    printList(head_list); // Affiche : 10 20 30

    deleteAt(&head_list, 1);
    printList(head_list); // Affiche : 10 30

    modifyAt(head_list, 0, 99);
    printList(head_list); // Affiche : 99 30

    insertAt(&head_list, 1, 88);
    printList(head_list); // Affiche : 99 88 30

    return 0;
}