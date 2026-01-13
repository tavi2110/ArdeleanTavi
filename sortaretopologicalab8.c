#include <stdio.h>
#include <stdlib.h>

int n, m;
int mat[100][100] = {{0}};
int gradIntern[100];
int topo[100], topoPos = 0;

void citire(void)
{
    FILE *f=fopen("graf.in", "r");
    if (!f)
    {
        printf("Nu se poate deschide fisierul graf.in\n");
        exit(1);
    }

    fscanf(f, "%d %d", &n, &m);

    int x, y;
    for(int i=0;i<m;i++)
    {
        fscanf(f, "%d %d", &x, &y);
        x--; y--;                 // transformare 1-based -> 0-based
        mat[x][y]=1;            // graf orientat
    }
    fclose(f);
}

void sortare_topologica()
{
    // 1. Calculam gradul intern pentru fiecare nod
    for (int j=0;j<n;j++)
    {
        gradIntern[j] = 0;
        for(int i=0;i<n;i++)
            if (mat[i][j]==1)
                gradIntern[j]++;
    }

    printf("Sortarea topologica: ");

    for (int step=0;step<n;step++)
    {
        // gasirea celui mai mic nod cu grad intern 0
        int nod=-1;
        for (int i=0;i<n;i++)
            if (gradIntern[i]==0)
            {
                nod=i;
                break;
            }

        if (nod==-1)
        {
            printf("\nGraful are ciclu – sortare topologica imposibila!\n");
            return;
        }

        // afisare nod (1-based)
        printf("%d ",nod + 1);

        // "eliminam" nodul din graf (nu il mai alegem din nou)
        gradIntern[nod]=-1;

        // scadem gradul intern al vecinilor sai
        for(int w=0;w<n; w++)
            if (mat[nod][w]==1)
                gradIntern[w]--;
    }

    printf("\n");
}

int main()
{
    citire();
    sortare_topologica();
    return 0;
}
