#include <stdio.h>
#define max(a, b) (a>b ? a : b)
#define min(a, b) (a<b ? a : b)

typedef struct{
    int x, y; /*lewy dolny rog i prawy gorny rog */
} punkt;

typedef struct{
    punkt a, b;
} fig;

int poprawny(const punkt *a, const punkt *b)
{
    return (a->x <= b->x && a->y <= b->y);
}

void oblicz(const fig *A, const fig *B, fig *C)
{
    punkt a = (punkt){B->a.x, min(A->b.y, B->a.y)};
    punkt b = (punkt){A->b.x, min(A->b.y, B->b.y)};
    if(poprawny(&a, &b))
        *C = (fig){a, b};
    else
        *C = (fig){(punkt){1, 1}, (punkt){-1, -1}};
}

int main()
{
    fig A, B;
    int ok = scanf("%d%d%d%d%d%d%d%d", &A.a.x, &A.a.y, &A.b.x, &A.b.y, &B.a.x, &B.a.y, &B.b.x, &B.b.y);
    if(!ok)
        return 0;
    if(A.a.x > B.a.x)    
    {
        fig C = A;
        A = B;
        B = C;
    }
    fig wynik;
    oblicz(&A, &B, &wynik);
    if(!poprawny(&wynik.a, &wynik.b))
        printf("NIE MA PRZECIECIA\n");
    else
        printf("(%d, %d), (%d, %d)", wynik.a.x, wynik.a.y, wynik.b.x, wynik.b.y);

    return 0;
}