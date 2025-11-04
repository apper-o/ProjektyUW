#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int cykl(int n, int a[])
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int curr = 1;
        for(int j=a[i];j!=i;j=a[j])
            curr++;
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n+1;i++)
        scanf("%d", &a[i]);
    printf("%d", cykl(n, a));
    free(a);
    return 0;
}