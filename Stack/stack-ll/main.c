#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

int main() {
    Node *head = NULL;
    prints(head);
    pop(&head);
    prints(head);
    push(&head, 42);
    prints(head);
    push(&head, 2);
    prints(head);
    pop(&head);
    prints(head);
    push(&head, 16);
    prints(head);
    push(&head, -3);
    prints(head);
    pop(&head);
    prints(head);
}