#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

/* O(n) */
int rozne(int n, int a[])
{
    int i = 0, j = n-1;
    while(i<j)
    {
        if(a[i] == a[j])
            return 0;
        if(a[i] > a[j])
            i++;
        else
            j--;
    }
    return 1;
}

/* O(logn) */
int minimum(int n, int a[])
{
    int l = 0, r = n - 1;
    while(l < r)
    {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if(a[m1] < a[m2])
            r = m2-1;
        else if(a[m1] > a[m2])
            l = m1+1;
        else
        {
            l = m1;
            r = m2;
        }
    }
    return a[l];
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    int rozne_a = rozne(n, a);
    int min_a = minimum(n, a);
    printf("%d %d\n", rozne_a, min_a);
    return 0;
}