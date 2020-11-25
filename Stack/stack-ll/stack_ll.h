#ifndef stack_ll
#define stack_ll
struct node
{
    int data;
    struct node* next;
};
typedef struct node Node;

_Bool pop(Node**);
_Bool push(Node**, int);
void prints(Node*);

#endif