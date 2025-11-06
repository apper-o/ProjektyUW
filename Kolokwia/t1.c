#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

void get(int n, int* x, int* y)
{
    for(int i=0;(1<<i)<=n;i+=2)
        if((n & (1<<i)))
            *x+=(1<<i);
    for(int i=1;(1<<i)<=n;i+=2)
        if((n & (1<<i)))
            *y+=(1<<i);
}

void get2(int n, int *x, int *y)
{
    *x += (1<<31);
    for(int i=30;i>=0;i-=2)
        if(n & (1<<i))
            *y += (1<<i);
    for(int i=29;i>=0;i-=2)
        if(n & (1<<i))
            *x += (1<<i);
}

void print(int x)
{
    printf("%d", (x<0));
    for(int i=30;i>=0;i--)
    {
        printf("%d", (((1<<i) & x) > 0));
        if(i%4==0)
            printf(" ");
    }
    printf("\n");
}

int main()
{  
    int n, x = 0, y = 0;
    scanf("%d", &n);
    if(n >= 0)
        get(n, &x, &y);
    else
        get2(n, &x, &y);
    printf("%d %d\n", x, y);
    print(x);
    print(y);

    return 0;
}