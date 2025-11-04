#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

void swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b; 
    *a -= *b;
}

int powtorz(int n, int a[])
{
    while(a[a[0]] != a[0])
        swap(&a[a[0]], &a[0]);
    return a[0];
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(n));
    for(int i=0;i<n+1;i++)
        scanf("%d", &a[i]);
    printf("%d", powtorz(n, a));
    free(a);
    return 0;
}