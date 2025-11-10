#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int solve(int *arr, int n, int k)
{
    int *cnt = malloc((k+2) * sizeof(int));
    int res = 0;
    for(int i=0;i<=k;i++)
        cnt[i] = 0;
    for(int i=n-1;i>=0;i--)
    {
        int x = arr[i];
        if(cnt[x+1] > 0)
            cnt[x+1]--;
        else
            res++;
        cnt[x]++;
    }
    free(cnt);
    return res;
}

int main()
{  
    int n, k; /* n = liczba cyfr w tablicy, k = zakres */
    scanf("%d%d", &n, &k);
    int *arr = malloc(n * sizeof(int)); 
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("%d", solve(arr, n, k));
    return 0;
}
