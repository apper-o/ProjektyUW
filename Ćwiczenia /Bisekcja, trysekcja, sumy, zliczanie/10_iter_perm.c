#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int* iter_perm(int n, int *a, int k)
{
    int *res = malloc(n * sizeof(int));
    int *tmp = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        res[i] = -1;
    for(int i=0;i<n;i++)
    {
        if(res[i] != -1)
            continue;
        int it = 1;
        tmp[0] = i;
        for(int j=a[i];j!=i;j=a[j])
            tmp[it++] = j;
        for(int j=0;j<it;j++)
            res[tmp[j]] = tmp[(j+k) % it];
    }
    free(tmp);
    return res;
}

int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    int *b = inter_perm(n, a, k);
    for(int i=0;i<n;i++)
        printf("%d ", b[i]);
    free(a);
    return 0;
}