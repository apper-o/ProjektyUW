#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int p(int n, int t[])
{
    int res = t[0], suma = t[0];
    for(int i=1;i<n;i++)
    {
        if(suma < 0)
            suma = 0;
        suma += t[i];
        res = max(res , suma);
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
    printf("%d", p(n, a));
    free(a);
    return 0;
}