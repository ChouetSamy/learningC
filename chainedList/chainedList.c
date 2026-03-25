#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int value;
    struct s_node* prev;
    struct s_node* next;
} t_node;

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

// ----- Parcours de la liste -----
void printList(t_node* head_list) {
    t_node* ptr_current_node = head_list;
    while (ptr_current_node != NULL) {
        printf("%d ", ptr_current_node->value);
        ptr_current_node = ptr_current_node->next;
    }
    printf("\n");
}

int main() {
    t_node* head_list = NULL;

    append(&head_list, 10); // ajoute à la fin
    append(&head_list, 20);
    append(&head_list, 30);

    printf("Liste après append: ");
    printList(head_list);

    modifyAt(head_list, 1, 99); // modifie le 2ème node (index 1)
    printf("Liste après modification: ");
    printList(head_list);

    deleteAt(&head_list, 0); // supprime le premier node
    printf("Liste après suppression: ");
    printList(head_list);

    // Libération mémoire
    while (head_list != NULL) {
        t_node* tmp = head_list;
        //tmp = temporaire et pointe vers le node actuel
        head_list = head_list->next;
        free(tmp);
    }

    return 0;
}

/*
1️⃣ t_node** head dans append
void append(t_node** head, int val)

head = adresse de la variable qui contient la tête de la liste.

Pourquoi double pointeur (**) ?

Dans le main :

t_node* head = NULL;
append(&head, 10);

head dans le main = pointeur vers le premier node

On passe l’adresse de head (&head) à append

Dans append, si la liste est vide, on doit changer la valeur de head pour qu’il pointe sur le nouveau node.

Si on passait juste t_node* head, on ne pourrait pas modifier le pointeur head du main.

✅ Donc t_node** head = permet de modifier la tête de liste depuis la fonction
*/

/*
3️⃣ Conseils pour réécrire tout de zéro

Ne copie pas bêtement

Lis le code, comprends chaque ligne → puis essaie de réécrire juste la fonction append toi-même sans regarder.

Commence par des mini-versions

Exemple : créer une liste de 2 nodes seulement, puis test append, puis delete, puis insert.

Schémas sur papier

Pour chaque modification (append, insertAt, deleteAt), trace prev/next → tu vois mieux les liens.

Ajoute des print intermédiaires

printf("Current=%d, prev=%p, next=%p\n", ...)
→ tu visualises les adresses et valeurs

Refais les exos en variant les cas

Liste vide, un seul élément, milieu, fin.

Compare avec le code initial

Vérifie que ton code fait exactement la même chose → puis tu peux l’optimiser.

💡 Petite astuce : quand tu travailles sur algo/listes :

Chaque node = objet indépendant → relie via prev/next

head/tête = point d’entrée

NULL = fin de la liste

Pointeurs = outils pour déplacer/insérer/supprimer
*/