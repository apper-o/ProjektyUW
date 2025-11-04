#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int fit(int c, int n, int a[])
{
    int i = 0, j = n-1, res = INT_MAX;
    while(i<j)
    {
        res = min(res, abs(a[i] + a[j] + c));
        if(a[i] + a[j] + c <= 0)
            i++;
        else
            j--;
    }
    return res;
}

int main()
{
    int n, c;
    scanf("%d%d", &n, &c);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    int res = malo(c, n, a);
    printf("%d", res);
    free(a);
    return 0;
}