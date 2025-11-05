#include <stdio.h>
#include <stdlib.h>

int find(int *a, int n, int s)
{
    int i = 0, j = 0, sum = 0;
    while(j<n)
    {
        sum += a[j];
        while(sum > s)
            sum -= a[i++];
        if(s == sum)
            return i;
        j++;
    }
    return -1;
}

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("%d", find(a, n, s));
    free(a);
    return 0;
}