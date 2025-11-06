#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int fragmenty(int *a, int n, int s)
{
    int i = 0, j = 0, res = n, sum = 0;
    while(j<n)
    {
        while(j<n && sum + a[j] <= s)
            sum += a[j++];
        res = min(res, j-i);
        sum -= a[i++];
    }
    return res;
}

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("%d", fragmenty(a, n, s));
    free(a);
    return 0;
}