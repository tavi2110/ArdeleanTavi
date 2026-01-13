#include <stdio.h>
#include <string.h>

int n, m;
int s[100];            // culoarea fiecarei tari
int adj[100][100];    // matrice adiacenta
char countryName[100][50];
char colorName[20][50];

int valid(int k)
{
    for(int j=1;j<k;j++)
    {
        if (adj[k][j]==1 && s[k]==s[j])
        {
            return 0;  // conflict de culoare
        }
    }
    return 1;
}

void afisare()
{
    printf("Solutie:\n");
    for(int i=1;i<=n;i++)
    {
        printf("%s -> %s\n", countryName[i], colorName[s[i]]);
    }
    printf("\n");
}

void back(int k)
{
    if (k>n)
    {            // opreste corect
        afisare();
        return;
    }
    for(int col=1;col<=m;col++)
    {
        s[k]=col;
        if (valid(k))
        {
            back(k + 1);   // mergem la tara urmatoare
        }
    }
}

int main()
{
    printf("Numar tari: ");
    scanf("%d", &n);
    printf("Tari:\n");
    for(int i=1;i<=n;i++)
        scanf("%s", countryName[i]);
    ///matrice adiacenta
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            adj[i][j]=0;
    printf("Vecinatati (tara1 tara2, 0 0 pentru stop):\n");
    while (1)
    {
        char a[50], b[50];
        scanf("%s %s", a, b);
        if (strcmp(a, "0")==0 && strcmp(b, "0")==0)
            break;
        int ia=-1, ib=-1;
        for(int i=1;i<=n;i++)
        {
            if (strcmp(countryName[i], a)==0)
                ia = i;
            if (strcmp(countryName[i], b)==0)
                ib = i;
        }
        if (ia!=-1 && ib!=-1)
        {
            adj[ia][ib]=adj[ib][ia]=1;
        }
    }
    printf("Numar culori: ");
    scanf("%d", &m);
    printf("Culori:\n");
    for(int i=1;i<=m;i++)
        scanf("%s", colorName[i]);
    back(1);   // start corect
    return 0;
}
