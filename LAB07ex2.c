#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int key;
    struct nodetype *next;
} NodeT;

NodeT *adj[100] = {NULL};
int n, m;

void adaugaMuchie(int x, int y)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->key=y;
    p->next=adj[x]; // inserare la început
    adj[x]=p;
}

void citire(void)
{
    FILE *f=fopen("graf.in", "r");
    if (!f)
    {
        printf("Nu se poate deschide fisierul graf.in\n");
        exit(1);
    }

    fscanf(f, "%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        fscanf(f, "%d %d", &x, &y);
        adaugaMuchie(x, y); // doar x → y (graf orientat)
    }

    fclose(f);
}

void afisare(void)
{
    printf("Listele de adiacenta (graf orientat):\n");
    for(int i=0;i<n;i++)
    {
        printf("[%d]: ", i);
        NodeT *current=adj[i];
        while (current!=NULL)
        {
            printf("%d ", current->key);
            current=current->next;
        }
        printf("\n");
    }
}

int main(void)
{
    citire();
    afisare();
    return 0;
}
