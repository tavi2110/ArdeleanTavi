#include<stdio.h>
#include<stdlib.h>
int n, sol=0;
int st[20];

void afisare()
{
    sol++;
    printf("Solutia %d:\n", sol);
    for(int i=1;i<=n;++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(st[i] == j) printf("R ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int solutie(int k)
{
    if(k==n)
        return 1;
    else
        return 0;
}

int valid(int k)
{
    int copie=k;
    k--;
    while(k!=0)
    {
        if(st[k]==st[copie]||abs(copie - k) == abs(st[copie] - st[k]))
            return 0;
        k--;
    }
    return 1;
}

void back(int k)
{
    for(int i=1;i<=n;++i)
    {
        st[k]=i;
        if(valid(k))
        {
            if(solutie(k))
                afisare();
            else
                back(k+1);
        }
    }
}

int main()
{
    printf("Numarul de regine: n= ");
    scanf("%d",&n);
    printf("\n");
    back(1);
    printf("Numar solutii: %d",sol);
    return 0;
}
