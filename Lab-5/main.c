#include <stdio.h>
#include <stdlib.h>

struct customer {
    int num;    //müsteri no
    int whper;  //hangi personel ilgilendi
    int come;   //gelis zamani
    int total_t;//toplam islem zamani
    int leave;  //ayrilis zamani
    int wait_t; //bekleme süresi
    struct customer *next;
};
typedef struct customer customer;

struct personnel {
    int id;
    int start_t;
    int end_t;
    int total_t;
    struct personnel *next;
};
typedef struct personnel personnel;

void pop(personnel **head);
void push(personnel **head, int i, int s, int e, int t);
customer* enqueue(customer **head, int n, int w, int c, int t, int l, int wa);
void dequeue(customer **head);
void print_c(customer *head);
void print_p(personnel* head);
void print_ptime(personnel *head);
int getcsize(customer* head);
void banking(customer **chead, personnel **phead, int time);

int g_maxt = 0;
int g_ischeadnull = 0;

int main() {
    int num, come, total;
    int size_c = 0;
    customer *chead = NULL;
    personnel *phead = NULL;
    scanf("%d", &num);
    if (num == -1)
    {
        return 0;
    }
    for (; num != -1;)
    {
        scanf("%d %d", &come, &total);
        chead = enqueue(&chead, num, -1, come, total, come + total, -1);
        if (g_maxt < come)
        {
            g_maxt = come;
        }
        
        size_c++;
        scanf("%d", &num);
    }
    for (int i = 6; i >= 1; i--)
    {
        push(&phead, i, -1, 0, 0);
    }
    for (unsigned int time = 1; time <= g_maxt; time++)
    {
        size_c = getcsize(chead);
        for (int i = 0; i < size_c && !g_ischeadnull; i++)
        {
            banking(&chead, &phead, time);
        }
        
    }
    puts("");
    print_ptime(phead);
    return 0;
}

void pop(personnel **head) {
    if (*head == NULL)
    {
        return;
    }
    personnel *iter = *head;
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    free(iter->next);
    iter->next = NULL;
}
void push(personnel **head, int i, int s, int e, int t) {
    if (*head == NULL)
    {
        personnel *newnode = (personnel*) malloc(sizeof(personnel));
        newnode->id = i;
        newnode->start_t = s;
        newnode->end_t = e;
        newnode->total_t = t;
        newnode->next = NULL;
        *head = newnode;
        return;
    }

    personnel *newnode = (personnel*) malloc(sizeof(personnel));
    newnode->id = i;
    newnode->start_t = s;
    newnode->end_t = e;
    newnode->total_t = t;
    newnode->next = NULL;
    personnel *iter = *head;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = newnode;
    return;
}
customer* enqueue(customer **head, int n, int w, int c, int t, int l, int wa) {
    if (*head == NULL)
    {
        customer *newnode = (customer*) malloc(sizeof(customer));
        newnode->num = n;
        newnode->whper = w;
        newnode->come = c;
        newnode->total_t = t;
        newnode->leave = l;
        newnode->wait_t = wa;
        newnode->next = NULL;
        *head = newnode;
        return newnode;
    }
    
    customer *newnode = (customer*) malloc(sizeof(customer));
    newnode->num = n;
    newnode->whper = w;
    newnode->come = c;
    newnode->total_t = t;
    newnode->leave = l;
    newnode->wait_t = wa;
    newnode->next = *head;
    *head = newnode;
    return newnode;
}
void dequeue(customer **head) {
    if (*head == NULL)
    {
        return;
    }
    
    customer *iter = *head;
    if (iter->next == NULL)
    {
        g_ischeadnull = 1; 
        //free(iter);
        iter = NULL;
        return;
    }
    
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    free(iter->next);
    iter->next = NULL;
}
void print_c(customer* head) {
    if (head == NULL)
    {
        printf("NULL head\n");
    }
    
    customer *iter = head;
    for (unsigned int i = 0; iter != NULL; i ++)
    {
        printf("num:%d whper:%d come:%d total_t:%d leave:%d wait_t:%d\n", iter->num, iter->whper, iter->come, iter->total_t, iter->leave, iter->wait_t);
        iter = iter->next;
    }
}

void print_p(personnel* head) {
    if (head == NULL)
    {
        printf("NULL head\n");
    }
    
    personnel *iter = head;
    for (unsigned int i = 0; iter != NULL; i ++)
    {
        printf("id:%d start_t:%d end_t:%d total_t:%d\n", iter->id, iter->start_t, iter->end_t, iter->total_t);
        iter = iter->next;
    }
    puts("");
}
void print_ptime(personnel *head) {
    if (head == NULL)
    {
        return;
    }
    
    personnel *iter = head;
    for (unsigned int i = 0; iter != NULL; i ++)
    {
        printf("%d %d\n", iter->id, iter->total_t);
        iter = iter->next;
    }
}
int getcsize(customer* head) {
    if (head == NULL)
    {
        return 0;
    }
    customer *iter = head;
    unsigned int i;
    for (i = 0; iter != NULL; i ++)
    {
        iter = iter->next;
    }
    return i;
}
void banking(customer **chead, personnel **phead, int time) {
    if (*chead == NULL)
    {
        return;
    }
    customer *citer = *chead;
    while (citer->next != NULL)
    {
        citer = citer->next;
    }
    if (citer->come <= time)
    {
        
        personnel *piter = *phead;
        while (piter->next != NULL)
        {
            if (piter->end_t <= time && piter->start_t != time)
            {
                break;
            }
            
            piter = piter->next;
        }
        if (piter->id == 1 && piter->end_t > time)
        {
            g_maxt++;
            return;
        }
        citer->leave = time + citer->total_t;
        piter->end_t = citer->leave;
        piter->total_t += citer->total_t;
        piter->start_t = time;
        citer->wait_t = time - citer->come;
        citer->whper = piter->id;
        printf("%d %d %d %d %d\n", citer->num, citer->whper, time, citer->leave, citer->wait_t);
        dequeue(chead);
    }
}