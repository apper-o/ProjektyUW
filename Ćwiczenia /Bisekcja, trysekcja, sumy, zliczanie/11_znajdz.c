#include <stdio.h>
#include <stdlib.h>

int znajdz(int **arr, int y, int x, int v)
{
    int a = x-1, res = 0;
    for(int i=0;i<y;i++)
    {
        while(a>0 && arr[i][a] < v)
            a--; 
        res += (arr[i][a] == v);
    }
    return res;
}

int main()
{
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    int **arr = malloc(y * sizeof(int*));
    for(int i=0;i<y;i++)
        arr[i] = malloc(x * sizeof(int));
    for(int i=0;i<y;i++)
        for(int j=0;j<x;j++)
            scanf("%d", &arr[i][j]);
    printf("%d\n", znajdz(arr, y, x, v));
    return 0;
}