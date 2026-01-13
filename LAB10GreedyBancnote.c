#include<stdio.h>
#include<stdlib.h>

int main()
{
    int bancnote[] = {500, 200, 100, 50, 10, 5, 1};
    int n=7, suma;
    printf("Suma: ");
    scanf("%d", &suma);
    printf("Numar minim de bancnote:\n");
    for (int i = 0; i < n; i++)
    {
        int nr_bancnote = suma / bancnote[i];
        if (nr_bancnote > 0)
        {
            printf("%d x %d RON\n", nr_bancnote, bancnote[i]);
            suma = suma % bancnote[i];
        }
    }

    return 0;
}
