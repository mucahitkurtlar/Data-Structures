#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

_Bool pop(Node **head) {
    if (*head == NULL)
        return 0;
    
    Node *iter = *head;
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    free(iter->next);
    iter->next = NULL;
    return 1;
}

_Bool push(Node **head, int data) {
    if (*head == NULL)
    {
        Node *newnode = (Node*) malloc(sizeof(Node));
        newnode->data = data;
        newnode->next = NULL;
        *head = newnode;
        return 1;
    }

    Node *newnode = (Node*) malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    Node *iter = *head;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = newnode;
    return 1;
}

void prints(Node* head) {
    if (head == NULL)
    {
        printf("NULL head\n");
    }
    
    Node *iter = head;
    for (unsigned int i = 0; iter != NULL; i ++)
    {
        printf("%d: node->data = %d\n", i, iter->data);
        iter = iter->next;
    }
    puts("");
}