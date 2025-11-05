#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct{
    int a, b;
} pii;

int f(int **arr, int x, int y, int k)
{
    int res = 0;
    for(int i=1;i<=y;i++)
        for(int j=1;j<=x;j++)
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
    pii *d = malloc(k * sizeof(pii));
    int it = 0;
    for(int i=1;i*i<=k;i++)
        if(k % i == 0)
            d[it++] = (pii){i, k/i};
    for(int i=0;i<it;i++)
    {
        int a = d[i].a, b = d[i].b;
        for(int Y=0;Y+a<=y;Y++)
            for(int X=0;X+b<=x;X++)
                res = max(res, arr[Y+a][X+b] - arr[Y][X+b] - arr[Y+a][X] + arr[Y][X]);
    }
    return res;            
}

int main()
{
    int y, x, k;
    scanf("%d%d%d", &x, &y, &k);
    int **arr = malloc((y+1) * sizeof(int*));
    for(int i=0;i<=y;i++)
        arr[i] = malloc((x+1) * sizeof(int));
    for(int i=0;i<=x;i++)
        arr[0][i] = 0;
    for(int i=0;i<=y;i++)
        arr[i][0] = 0;
    for(int i=1;i<=y;i++)
        for(int j=1;j<=x;j++)
            scanf("%d", &arr[i][j]);
    printf("%d", f(arr, x, y, k));
    free(arr);
    return 0;
}