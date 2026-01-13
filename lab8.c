#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int key;
    struct nodetype *next;
} NodeT;


// typedef struct nod {
//   int descoperit,finalizat,tata;
// } Nod;

// Nod noduri[10];

//NodeT *first = NULL, *last = NULL;
int n, m;
int mat[100][100] = {{0}};
// NodeT *adj[100] = {NULL};
//int visited[100] = {0};

void citire(void)
{
    FILE *f = fopen("graf.in", "r");
    if (!f)
    {
        printf("Nu se poate deschide fisierul graf.in\n");
        return;
    }
    fscanf(f, "%d %d", &n, &m);

    int x, y;
    for (int i = 0; i < m; i++)
    {
        fscanf(f, "%d %d", &x, &y);
        mat[x][y] = 1;   // graf orientat
        // mat[y][x] = 1; pentru  graf neorientat
    }
    fclose(f);
}

void afisare(void)
{
    //pentru matricea de adiacenta
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void bfs(int nodStart)   //in latime, lab 7
{
    int visit[100] = {0};
    int Q[100];
    int st = 0, dr = 0; // coada

    // marcăm nodul sursă ca vizitat
    visit[nodStart] = 1;
    printf("BFS: %d ", nodStart);

    // îl punem în coadă
    Q[dr++] = nodStart;

    while (st < dr)
    {
        int v = Q[st++]; // scoatem din coadă

        // parcurgem toți vecinii lui v
        for (int w = 0; w < n; w++)
        {
            if (mat[v][w] == 1 && visit[w] == 0)
            {
                visit[w] = 1;   // marcare vizitat
                printf("%d ", w);
                Q[dr++] = w;      // adăugăm în coadă
            }
        }
    }

    printf("\n");

}

void dfs(int nodStart)   //in adancime, lab 8
{
    int S[100], sp = 0;
    int color[100] = {0}; // 0=WHITE

    S[sp++] = nodStart;

    while (sp > 0)
    {
        int v = S[--sp];

        if (color[v] == 0)   // WHITE
        {
            color[v] = 1;    // devine GRAY
            printf("%d ", v);

            for (int w = n-1; w >= 0; w--)
                if (mat[v][w] == 1 && color[w] == 0)
                    S[sp++] = w;
        }
    }
    printf("\n");

}

int main(void)
{
    citire();
    //bfs(0);
    afisare();
    return 0;
}
/*
graf.in
5 8
0 1
0 2
1 2
1 3
1 4
2 3
3 4
4 0
graf2.in
6 8
0 1
1 2
1 3
1 4
2 3
3 4
4 0
0 5
*/

