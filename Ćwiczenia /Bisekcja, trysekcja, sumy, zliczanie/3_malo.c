#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int malo(int n, int a[])
{
    int i = 0, j = n-1, res = INT_MAX;
    while(i<j)
    {
        res = min(res, abs(a[i] + a[j]));
        if(abs(a[i]) <= abs(a[j]))
            j--;
        else
            i++;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    int res = malo(n, a);
    printf("%d", res);
    return 0;
}