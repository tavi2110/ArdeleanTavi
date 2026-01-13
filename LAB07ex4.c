#include <stdio.h>
#include <stdlib.h>

int n, m;
int mat[100][100] = {{0}};

void citire(void)
{
    FILE *f=fopen("graf.in", "r");
    if (!f)
    {
        printf("Nu se poate deschide fisierul graf.in\n");
        exit(1);
    }

    fscanf(f, "%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int x, y;
        fscanf(f, "%d %d", &x, &y);
        mat[x][y]=1; // graf orientat
        // mat[y][x] = 1; // (doar dacă ar fi neorientat)
    }
    fclose(f);
}

void afisare(void)
{
    printf("Matricea de adiacenta:\n");
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void bfs(int nodStart)
{
    int queue[100];
    int front=0, rear=0;
    int vizitat[100]={0};
    int tati[100];
    int timp_start[100];
    int timp_end[100];
    int timp_curent=0;

    for(int i=0;i<n;i++)
    {
        tati[i]=-1;
        timp_start[i]=timp_end[i] = -1;
    }

    FILE *g=fopen("graf.out", "w");
    if (!g)
    {
        printf("Nu se poate deschide fisierul graf.out\n");
        exit(1);
    }

    vizitat[nodStart]=1;
    tati[nodStart]=-1;
    timp_curent++;
    timp_start[nodStart]=timp_curent;
    queue[rear++]=nodStart;

    printf("Ordinea de parcurgere BFS: ");
    fprintf(g, "Ordinea de parcurgere BFS: ");

    while(front<rear)
    {
        int v=queue[front++];
        printf("%d ", v);
        fprintf(g, "%d ", v);

        for(int w=0;w<n;w++)
        {
            if (mat[v][w]==1 && vizitat[w]==0)
            {
                vizitat[w]=1;
                tati[w]=v;
                timp_curent++;
                timp_start[w]=timp_curent;
                queue[rear++]=w;
            }
        }
    }
    timp_curent++;
    timp_end[v]=timp_curent;
    printf("\n");
    fprintf(g, "\n");
    printf("\n\nVectorul de tati:\n");
    fprintf(g, "\n\nVectorul de tati:\n");
    for (int i= 0; i < n; i++)
    {
        printf("tata[%d] = %d\n", i, tati[i]);
        fprintf(g, "tata[%d] = %d\n", i, tati[i]);
    }

    printf("\nTimpii de descoperire si finalizare:\n");
    fprintf(g, "\nTimpii de descoperire si finalizare:\n");
    for (int i = 0; i < n; i++) {
        printf("nod %d: start = %d, final = %d\n", i, timp_start[i], timp_end[i]);
        fprintf(g, "nod %d: start = %d, final = %d\n", i, timp_start[i], timp_end[i]);
    }

    fclose(g);
}

int main(void)
{
    citire();
    afisare();

    int start;
    printf("Introdu nodul de start: ");
    scanf("%d", &start);

    bfs(start);
    return 0;
}
