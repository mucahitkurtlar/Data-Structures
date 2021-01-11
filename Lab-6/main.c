#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    int grade;
    struct student *right;
    struct student *left;
};
typedef struct student student;

student* insert(student *node, int id, int grade);
void walk(student *node);
void printlayers(student *node);
void printsamelevel(student *node, int level, int parent, int order, int rst);
int getdepth(student *node);

int main() {
    student *tree = NULL;
    int id, grade;
    scanf("%d", &id);
    while (id != -1)
    {
        scanf("%d", &grade);
        tree = insert(tree, id, grade);
        scanf("%d", &id);
    }
    walk(tree);
    puts("");
    printlayers(tree);
    return 0;
}

student* insert(student *node, int id, int grade) {
    if (node == NULL)
    {
        student *newstdnt = (student*) malloc(sizeof(student));
        newstdnt->id = id;
        newstdnt->grade = grade;
        newstdnt->right = NULL;
        newstdnt->left = NULL;
        return newstdnt;
    }
    if (node->grade < grade)
    {
        node->right = insert(node->right, id, grade);
        return node;
    }
    node->left = insert(node->left, id, grade);
    return node;
}

void walk(student *node) {
    if (node == NULL)
    {
        return;
    }
    walk(node->left);
    printf("%d %d\n", node->id, node->grade);
    walk(node->right);
}

void printlayers(student *node) 
{ 
    int height = getdepth(node);
    for (int i = 1; i <= height; i++) 
    { 
        printsamelevel(node, i, node->grade, 2, 1); 
        puts("");
    } 
} 


void printsamelevel(student *node, int level, int parent, int order, int rst)
{
    static int isnl = 1;
    if (rst)
    {
        isnl = 1;
    }
    if (node == NULL) {
        return;
    }
    if (isnl)
    {
        
        if (level == 1 && order == 3)
        {
            printf("%d %d (%d R)", node->id, node->grade, parent);
            isnl = 0;
        }
        if (level == 1 && order == 2)
        {
            printf("%d %d", node->id, node->grade, parent);
            isnl = 1;
        }
        if (level == 1 && order == 1)
        {
            printf("%d %d (%d L)", node->id, node->grade, parent);
            isnl = 0;
        }
    } else
    {
        if (level == 1 && order == 3)
        {
            printf(" %d %d (%d R)", node->id, node->grade, parent);
        }
        if (level == 1 && order == 1)
        {
            printf(" %d %d (%d L)", node->id, node->grade, parent);
        }
    }
    if (level > 1) 
    {
        printsamelevel(node->left, level-1, node->grade, 1, 0);
        printsamelevel(node->right, level-1, node->grade, 3, 0); 
    }
} 

int getdepth(student *node)  
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