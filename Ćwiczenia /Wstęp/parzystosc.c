#include <stdio.h>

int parzystosc(int x)
{
    if(x==0)
        return -1;
    int wynik = 0;
    while(x%2==0)
    {
        wynik++;
        x/=2;
    }
    return wynik;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", parzystosc(x));
    return 0;
}