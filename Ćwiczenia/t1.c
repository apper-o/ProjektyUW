#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int rzadkie(int n)
{
    int *cnt = malloc(32 * sizeof(int));
    cnt[0] = 1;
    cnt[1] = 2;
    for(int i=2;i<32;i++)
        cnt[i] = cnt[i-1] + cnt[i-2];
    int res = 0;
    for(int i=0;(1<<i)<=n;i++)
        if(n & (1<<i))
            res += cnt[i];
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", rzadkie(n));
    return 0;
}