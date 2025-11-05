#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int f(int n, int *a)
{
    int l = 0, r = n-1;
    while(l < r)
    {
        int m = l + (r - l) / 2;
        if(a[m] > m)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("%d", f(n, arr));
    return 0;
}