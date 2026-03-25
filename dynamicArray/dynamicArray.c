#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"

// ----- Fonction pour ajouter un node à la fin -----
// head_list est un double pointeur pour pouvoir modifier le pointeur de tête 
// si la liste est vide
void append(t_node** head_list, int val) {
    t_node* newNode = malloc(sizeof(t_node));
    newNode->value = val;
    //initialisation d'une nouvelle node, val est la valeur à stocker
    newNode->next = NULL; 
    // le prochain node est NULL car c'est la fin de la liste

    if (*head_list == NULL) {
        // Si la liste est vide, newNode devient le premier node
        newNode->prev = NULL;
        *head_list = newNode;
        return;
    }

    // Sinon, trouver le dernier node
    t_node* last = *head_list;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

//usage append : append(&head_list, 10); // ajoute 10 à la fin de la liste

// ----- Fonction pour supprimer un node à un index -----
void deleteAt(t_node** head_list, int index) {
    if (*head_list == NULL) return;
    
    t_node* ptr_current_node = *head_list;
    int i = 0;
    while (ptr_current_node != NULL && i < index) {
        ptr_current_node = ptr_current_node->next;
        i++;
    }

    if (ptr_current_node == NULL) return; // index invalide

    if (ptr_current_node->prev != NULL) ptr_current_node->prev->next = ptr_current_node->next;
    else *head_list = ptr_current_node->next; // supprimer le premier node

    if (ptr_current_node->next != NULL) ptr_current_node->next->prev = ptr_current_node->prev;

    free(ptr_current_node);
}

//usage deleteAt : deleteAt(&head_list, 1); // supprime le node à l'index 1

// ----- Fonction pour modifier un node à un index -----
void modifyAt(t_node* head_list, int index, int val) {
    t_node* ptr_current_node = head_list;
    int i = 0;
    while (ptr_current_node != NULL && i < index) {
        ptr_current_node = ptr_current_node->next;
        i++;
    }

    if (ptr_current_node != NULL) ptr_current_node->value = val; // modification
}

//usage modifyAt : modifyAt(head_list, 1, 99); // modifie la valeur du node à l'index 1 en 99

void insertAt(t_node** head_list, int index, int val) {
    t_node* newNode = malloc(sizeof(t_node));
    newNode->value = val;

    if (*head_list == NULL || index == 0) {
        // Insertion en tête
        newNode->next = *head_list;
        newNode->prev = NULL;
        if (*head_list != NULL) (*head_list)->prev = newNode;
        *head_list = newNode;
        return;
    }

    t_node* pCurrent = *head_list;
    int i = 0;
    while (pCurrent->next != NULL && i < index - 1) {
        pCurrent = pCurrent->next;
        i++;
    }

    // Insérer après pCurrent
    newNode->next = pCurrent->next;
    newNode->prev = pCurrent;

    if (pCurrent->next != NULL) pCurrent->next->prev = newNode;
    pCurrent->next = newNode;
}

//usage insertAt : insertAt(&head_list, 1, 99); // insère 99 à l'index 1

// ----- Fonction pour afficher la liste -----
void printList(t_node* head_list) {
    t_node* current = head_list;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}