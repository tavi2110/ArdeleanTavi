#include <stdio.h>

int binarySearchInsert(int v[], int n, int k)
{
    int st=0;
    int dr=n-1;
    while (st<=dr)
    {
        int m=(st+dr)/2;
        if (v[m]==k)
            return m;        //element gasit
        else if (v[m]<k)
            st=m+1;       // caut in jumatatea dreapta
        else
            dr=m-1;       // caut in jumatatea stanga
    }
    return st; //poz unde ar trebui inserat
}

int main()
{
    int v[]= {1, 3, 5, 7, 9, 11};
    int n=sizeof(v)/sizeof(v[0]);
    int k;
    printf("Element cautat: ");
    scanf("%d", &k);
    int pos=binarySearchInsert(v, n, k);
    printf("Pozitia returnata: %d\n", pos);
    return 0;
}
