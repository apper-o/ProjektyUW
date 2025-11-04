#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float a, b;
} punkt;

float suma(punkt a)
{
    return a.a * a.a + a.b * a.b;
}

float diagonal(int n, punkt a[])
{
    int l = 0, r = n - 1;
    while(l + 1 < r)
    {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if(suma(a[m1]) < suma(a[m2]))
            r = m2 - 1;
        else if(suma(a[m1]) > suma(a[m2]))
            l = m1 + 1;
        else
        {
            l = m1;
            r = m2;
        }
    }
    if(suma(a[l]) > suma(a[r]))
        l++;
    return sqrt(a[l].a*a[l].a+a[l].b*a[l].b);
}

int main()
{
    int n;
    scanf("%d", &n);
    punkt *a = malloc(n * sizeof(punkt));
    for(int i=0;i<n;i++)
        scanf("%f %f", &(a[i].a), &(a[i].b));
    printf("%f", diagonal(n ,a));
    free(a);
    return 0;
}

