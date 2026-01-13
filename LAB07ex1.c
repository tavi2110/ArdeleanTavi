#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int key;
    struct nodetype *next;
} NodeT;

//NodeT *first = NULL, *last = NULL;
int n, m;
int mat[100][100] = {{0}};
//int visited[100] = {0};

void citire(void)
{
    FILE *f=fopen("graf.in", "r");
    if (!f)
    {
        printf("Nu se poate deschide fisierul graf.in\n");
        exit(1);
    }

    fscanf(f, "%d %d", &n, &m); // citim numarul de noduri si muchii

    for(int i=0;i<m;i++)
    {
        int x, y;
        fscanf(f, "%d %d", &x, &y);
        mat[x][y]=1;
        //mat[y][x]=1; // dacă graful e neorientat
    }

    fclose(f);
}

void afisare(void)
{
    printf("Matricea de adiacenta:\n");
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void bfs(int nodStart)
{
    //to do din pseudocod partea 2 din lab
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
*/

//   }

