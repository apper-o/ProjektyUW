#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int get(int **a, int x1, int x2, int y1, int y2)
{
    return a[y2][x2] - a[y1-1][x2] - a[y2][x1-1] + a[y1-1][x1-1]; 
}

int check(int **a, int n, int m, int k, int x)
{
    for(int i=x;i<=n;i++)
        for(int j=x;j<=m;j++)
            if(get(a, j-x+1, j, i-x+1, i) <= k)
                return 1;
    return 0;
}

int prostokat(int **a, int n, int m, int k)
{
    int res = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
    int l = 0, r = min(n, m);
    while(l < r)
    {
        int mid = l + (r - l + 1) / 2;
        if(check(a, n, m, k, mid))
            l = mid;
        else 
            r = mid - 1; 
    }
    /* Zwracam bok najwiekszego kwadratu */
    return l;
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int **arr = malloc((n+1) * sizeof(int*));
    for(int i=0;i<=n;i++)
        arr[i] = malloc((m+1) * sizeof(int));
    for(int i=0;i<=n;i++)
        arr[i][0] = 0;
    for(int i=0;i<=m;i++)
        arr[0][i] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)    
            scanf("%d", &arr[i][j]);
    printf("%d", prostokat(arr, n, m, k));
    for(int i=0;i<=n;i++)
        free(arr[i]);
    free(arr);
    return 0;
}