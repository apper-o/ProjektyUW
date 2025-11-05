#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
 
/* O(n) */
int* zsumuj(int n, int a[])
{
    int *b = malloc(n * sizeof(int));
    b[n-1] = 0;
    for(int i=a[n-1]-1;i<n;i++)
        b[n-1] += a[i];
    for(int i=n-2;i>=0;i--)
    {
        b[i] = b[i+1];
        for(int j=a[i]-1;j<min(a[i+1]-1, n);j++)
            b[i] += a[j];
    }
    return b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    int *b = zsumuj(n, a);
    for(int i=0;i<n;i++)
        printf("%d ", b[i]);
    return 0;
}