#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct s_node {
    int value;
    struct s_node* prev;
    struct s_node* next;
} t_node;

void append(t_node** head_list, int val);
void deleteAt(t_node** head_list, int index);
void modifyAt(t_node* head_list, int index, int val);
void printList(t_node* head_list);
void insertAt(t_node** head_list, int index, int val);

#endif