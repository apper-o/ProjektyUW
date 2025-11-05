#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int f(int n, int *a)
{
    int res = 0;
    int *pref = malloc(n * sizeof(int));
    pref[0] = 0;
    for(int i=1;i<n;i++)
    {
        if(a[pref[i-1]] < a[i])
            pref[i] = pref[i-1];
        else 
            pref[i] = i;
    }   
    for(int i=n-1,j=n-1;i>=0;i--)
    {
        while(j && a[pref[j - 1]] <= a[i])
            j = pref[j - 1];
        res = max(res, i-j);
    }
    free(pref);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("%d", f(n, arr));
    free(arr);
    return 0;
}