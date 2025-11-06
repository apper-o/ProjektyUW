#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y;
} para;

void wypelnij(int **tab, para *ruch, int k, int dol, int k_obecne, int *x, int *y, int *licz)
{
    if(k_obecne >= dol)
    {
        for(int i=0;i<4;i++)
        {
            int xp = ruch[i].x * (1<<k_obecne), yp = ruch[i].y * (1<<k_obecne);
            *y += yp;
            *x += xp;
            if(i!=3)
            {
                tab[*y][*x] = (*licz)++;
                if(k_obecne < k)
                    wypelnij(tab, ruch, k, k_obecne+1, k, x, y, licz);
            }
        }
        if(k_obecne-1 >= dol)
            wypelnij(tab, ruch, k, dol, k_obecne-1, x, y, licz);
    }
}

int **cieniowanie(int k)
{
    int **tab = (int**)malloc((1<<k) * sizeof(int*));
    for(int i=0;i<(1<<k);i++)
        tab[i] = (int*)malloc((1<<k) * sizeof(int));
    int x = 0, y = 0, licz = 1;
    para ruch[4] = {(para){1, 1}, (para){0, -1}, (para){-1, 1}, (para){0, -1}}; 
    wypelnij(tab, ruch, k-1, 0, k-1, &x, &y, &licz);
    return tab;
}

int main()
{
    int k;
    scanf("%d", &k);
    int **tab = cieniowanie(k);
    for(int i=0;i<(1<<k);i++)
    {
        for(int j=0;j<(1<<k);j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
    return 0;
}