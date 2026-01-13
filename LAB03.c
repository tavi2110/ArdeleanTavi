#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int key;
    struct nodetype *next;
    struct nodetype *prev;
} NodeT;

NodeT *first = NULL, *last = NULL;

NodeT *search(int givenKey)
{
    NodeT *p = first;
    while (p != NULL)
    {
        if (p->key == givenKey)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    return NULL;
}

void insert_first(int givenKey)
{
    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    p->key = givenKey;
    p->next = NULL;
    p->prev = NULL;
    if (first == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
        p->next = first;
        first->prev = p;
        first = p;
    }
}

void insert_last(int givenKey)
{
    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    p->key = givenKey;
    p->next = NULL;
    p->prev = NULL;

    if (first == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
        last->next = p;
        p->prev = last;
        last = p;
    }
}

void afisare_lista(void)
{
    NodeT *p = first;
    while (p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}


void print_backward(void)
{
    NodeT *p=last;
    while (p!=NULL)
    {
        printf("%d ", p->key);
        p=p->prev;
    }
    printf("\n");
}

void delete_first(void)
{
    NodeT *p = first;
    if (first == NULL)
        return;
    first = first->next;
    //////////////////////////
    if (first == NULL) //daca avem un element
        last = NULL;
    else
        first->prev=NULL;
    free(p);
}

void delete_last(void)
{

    NodeT *p = last;/////
    if (first == NULL)
        return;
    if (first == last)
    {
        free(first);
        first = NULL;
        last = NULL;
        return;
    }
    /////////////////////
    last=last->prev;
    free(p);
    last->next = NULL;


    void insert_after_key(int afterKey, int givenKey)
    {
        NodeT *current = search(afterKey);
        if(current==NULL)
        {
            return;
        }
        NodeT *urm = current->next;
        NodeT *p = (NodeT *)malloc(sizeof(NodeT));
        p->key = givenKey;
        p->prev = current;
        p->next=urm;
        current->next=p;
        if(urm!=NULL)
        {
            urm->prev=p;
        }
        else
        {
            last=p;
        }
    }

    void insert_before_key(int givenKey, int beforeKey)
    {
        NodeT *current=search(beforeKey);
        if (current==NULL)
        {
            return;
        }
        NodeT *prec=current->prev;
        NodeT *p=(NodeT *)malloc(sizeof(NodeT));
        p->key=givenKey;
        p->prev=prec;
        p->next=current;
        current->prev=p;
        if(prec!=NULL)
        {
            prec->next=p;
        }
        else
        {
            first=p;
        }
        current->prev=p;

        void delete_key(int givenKey)
        {
            NodeT *p=search(givenKey);

            if (p==NULL)   //cheia nu exista
                return;

            //daca este primul nod
            if (p==first)
            {
                first=p->next;
                if (first!=NULL)
                    first->prev=NULL;
                else
                    last=NULL;   //lista devine vida
            }
            //daca este ultimul nod
            else if (p==last)
            {
                last=p->prev;
                last->next=NULL;
            }
            //nod din interior
            else
            {
                p->prev->next=p->next;
                p->next->prev=p->prev;
            }
            free(p);
        }

        int main(void)
        {
            insert_first(8);
            insert_first(7);
            insert_last(10);
            afisare_lista();
            //   delete_first();
            //   afisare_lista();
            //   delete_last();
            //   afisare_lista();
            return 0;
        }
// to do insert_after_key(int givenKey, int afterKey)
//  to do delete_key(int givenKey)
//  to do insert_before_key(int givenKey, int beforeKey)
//
