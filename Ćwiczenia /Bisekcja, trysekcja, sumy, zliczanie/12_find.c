#include <stdio.h>
#include <stdlib.h>

int find(int *a, int n)
{
    int l = 0, r = n - 1;
    while(l < r)
    {
        int m = l + (r - l) / 2;
        if(a[m] < a[r])
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("%d", find(a, n));
    return 0;
}