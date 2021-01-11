#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *right;
    struct node *left;
    int height;
};
typedef struct node node;

int max(int a, int b);
node* newnode(int num);
node* insert(node *n, int num);
int heightof(node *n);
node* rotate_r(node *y);
node* rotate_l(node *x);
int balfact(node *n);
void walk(node *n);
int getdepth(node *n);
void printlayers(node *n);
void printsamelevel(node *n, int level, int parent, int order, int rst);

int main() {
    node *tree = NULL;
    int num;
    scanf("%d", &num);
    for (; num != -1; scanf("%d", &num))
    {
        tree = insert(tree, num);
    }
    walk(tree);
    puts("");
    printlayers(tree);
    return 0;
}

int max(int a, int b) {
    if (a > b)
    {
        return a;
    }
    return b;
    
}
node* newnode(int num) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->num = num;
    new_node->height = 1;
    new_node->right = NULL;
    new_node->left = NULL;

    return new_node;
}
node* insert(node *n, int num) {
    if (n == NULL)
    {
        return newnode(num);
    }
    if (n->num > num)
    {
        n->left = insert(n->left, num);
    } else if (n->num < num)
    {
        n->right = insert(n->right, num);
    } else
    {
        return n;
    }
    n->height = max(heightof(n->right), heightof(n->left)) + 1;
    int bal = balfact(n);
    if (1 < bal && n->left->num > num)
    {
        return rotate_r(n);
    }
    if (-1 > bal && n->right->num < num)
    {
        return rotate_l(n);
    }
    if (1 < bal && n->left->num < num)
    {
        n->left = rotate_l(n->left);
        return rotate_r(n);
    }
    if (-1 > bal && n->right->num > num)
    {
        n->right = rotate_r(n->right);
        return rotate_l(n);
    }
    return n;
}
int heightof(node *n) {
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
node* rotate_r(node *y) {
    node *x = y->left;
    node *t2 = x->right;

    y->left = t2;
    x->right = y;
    y->height = max(heightof(y->right), heightof(y->left)) + 1;
    x->height = max(heightof(x->right), heightof(x->left)) + 1;

    return x;
}
node* rotate_l(node *x) {
    node *y = x->right;
    node *t2 = y->left;

    x->right = t2;
    y->left = x;
    x->height = max(heightof(x->right), heightof(x->left)) + 1;
    y->height = max(heightof(y->right), heightof(y->left)) + 1;

    return y;
}
int balfact(node *n) {
    if (n == NULL)
    {
        return 0;
    }
    return heightof(n->left) - heightof(n->right);
}
void walk(node *n) {
    if (n == NULL)
    {
        return;
    }
    walk(n->left);
    printf("%d\n", n->num);
    walk(n->right);
}
int getdepth(node *node)  
{
    if (node==NULL)
    {
       return 0;
    }
    else 
    { 
        int lDepth = getdepth(node->left); 
        int rDepth = getdepth(node->right);
        if (lDepth > rDepth)
        {
            return(lDepth+1);
        } else
        {
            return(rDepth+1);
        }
    }    
}
void printlayers(node *n) 
{ 
    int height = getdepth(n);
    for (int i = 1; i <= height; i++) 
    { 
        printsamelevel(n, i, n->num, 2, 1); 
        puts("");
    } 
} 
void printsamelevel(node *n, int level, int parent, int order, int rst)
{
    static int isnl = 1;
    if (rst)
    {
        isnl = 1;
    }
    if (n == NULL) {
        return;
    }
    if (isnl)
    {
        
        if (level == 1 && order == 3)
        {
            printf("%d (%d R) (%d B)", n->num, parent, balfact(n));
            isnl = 0;
        }
        if (level == 1 && order == 2)
        {
            printf("%d (%d B)", n->num, balfact(n));
            isnl = 1;
        }
        if (level == 1 && order == 1)
        {
            printf("%d (%d L) (%d B)", n->num, parent, balfact(n));
            isnl = 0;
        }
    } else
    {
        if (level == 1 && order == 3)
        {
            printf(" %d (%d R) (%d B)", n->num, parent, balfact(n));
        }
        if (level == 1 && order == 1)
        {
            printf(" %d (%d L) (%d B)", n->num, parent, balfact(n));
        }
    }
    if (level > 1) 
    {
        printsamelevel(n->left, level-1, n->num, 1, 0);
        printsamelevel(n->right, level-1, n->num, 3, 0); 
    }
} 