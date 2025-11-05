#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int get(int **a, int x1, int x2, int y1, int y2)
{
    return a[y2][x2] - a[y1-1][x2] - a[y2][x1-1] + a[y1-1][x1-1]; 
}

int prostokat(int **a, int n, int m, int k)
{
    int res = 2 * (n + m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
    if(a[n][m] < k)
        return 0;
    for(int y1=1;y1<=n;y1++)
    {
        for(int y2=y1;y2<=n;y2++)
        {
            for(int x1=1,x2=1;x2<=m;x2++)
            {
                while(x1 < x2 && get(a, x1+1, x2, y1, y2) >= k)
                    x1++;
                if(get(a, x1, x2, y1, y2) >= k)
                    res = min(res, 2*(y2-y1+x2-x1+2));
            }
        }
    }   
    return res;
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