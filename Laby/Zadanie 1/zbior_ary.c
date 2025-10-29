#include "zbior_ary.h"
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (a>b ? a : b)
#define min(a, b) (a<b ? a : b) 

/* Globalna roznica q, inicjowana przy pierwszym wywolaniu ciag_arytmetyczny. */
static int global_q;

/* Zwraca reszte z dzielenia liczby a przez q*/
int modulo(int a)
{
    a %= global_q;
    return (a + global_q) % global_q; 
}

/* Funkcja zwraca true, jezeli ciag a jest mniejszy ((1) wzgledem 
 reszty z dzielenia przez q (2) wzgledem poczatku ciagu) od b*/
bool minimalny(ciag a, ciag b)
{
    if(modulo(a.a) == modulo(b.a))
        return (a.a <= b.a);
    return (modulo(a.a) < modulo(b.b));
}

/* Funkcja pomocnicza do tworzenia pustego zbioru z poczatkowa pojemnoscia.*/
zbior_ary pusty(unsigned pojemnosc)
{
    zbior_ary zbior;
    zbior.tab = malloc(sizeof(ciag) * pojemnosc);
    zbior.rozmiar = 0;
    return zbior;
}

/* Funkcja pomocnicza do dodawania ciagu do zbioru, 
jeśli to konieczne alokuje wiecej pamieci zarzadzająca pamiecia.*/
void dodaj(zbior_ary *zbior, ciag c)
{
    /* Warunek c.a <= c.b sprawdza czy ciag jest poprawny */
    if(c.a <= c.b)
    {
        if(zbior->rozmiar == zbior->pojemnosc)
        {
            zbior->pojemnosc = (zbior->pojemnosc==0 ? 2 : zbior->pojemnosc * 2); 
            zbior->tab = realloc(zbior->tab, sizeof(ciag) * zbior->pojemnosc);
        }
        zbior->tab[zbior->rozmiar++] = c;
    }
}

zbior_ary ciag_arytmetyczny(int a, int q, int b)
{
    if(global_q == 0)
        global_q = q;
    zbior_ary zbior = pusty(1); 
    dodaj(&zbior, (ciag){a, b});
    return zbior;  
}

zbior_ary singleton(int a)
{
    return ciag_arytmetyczny(a, global_q, a);
}

zbior_ary suma(zbior_ary A, zbior_ary B)
{
    zbior_ary wynik = pusty(A.rozmiar + B.rozmiar);
    unsigned i=0, j=0;
    while(i < A.rozmiar || j < B.rozmiar)
    {
        ciag obecny;
        /* Wybiera minimalny ciag */
        if(i < A.rozmiar && (j == B.rozmiar || minimalny(A.tab[i], B.tab[j])))
            obecny = A.tab[i++];
        else
            obecny = B.tab[j++];
        if(!wynik.rozmiar)
            dodaj(&wynik, obecny);
        else
        {
            ciag *ostatni = &wynik.tab[wynik.rozmiar - 1];
            /* Sprawdza, czy ciagi mozna scalic */
            if(modulo(ostatni->a) == modulo(obecny.a) && ostatni->b + global_q >= obecny.a)
                ostatni->b = obecny.b;
            else
                dodaj(&wynik, obecny);
        }
    }
    return wynik;
}

zbior_ary iloczyn(zbior_ary A, zbior_ary B)
{
    zbior_ary wynik = pusty(max(A.rozmiar, B.rozmiar));
    unsigned i = 0, j = 0;
    while(i < A.rozmiar && j < B.rozmiar)
    {
        ciag a = A.tab[i];
        ciag b = B.tab[j];
        /* Jezeli reszta z dzielenia przez q jest taka sama to iloczynem zbiorow 
        jest ciag zaczynajacy sie w max(a.a, b.a) i konczac min(a.b, b.b) */
        if(modulo(a.a) == modulo(b.a))
        {
            dodaj(&wynik, (ciag){max(a.a, b.a), min(a.b, b.b)});
            if(a.b < b.b)
                i++;
            else
                j++;
        }
        else
        {
            if(modulo(a.a) < modulo(b.a))
                i++;
            else
                j++;
        }
    }
    return wynik;
}

zbior_ary roznica(zbior_ary A, zbior_ary B)
{
    zbior_ary wynik = pusty(A.rozmiar);
    unsigned i = 0, j = 0;
    while(i < A.rozmiar)
    {
        while(j < B.rozmiar && (B.tab[j].b < A.tab[i].a || modulo(B.tab[j].a) < modulo(A.tab[i].a)))
            j++;
        ciag a = A.tab[i];
        /* Sprawdzam wszystkie elementy ciagu B, ktore maja niepuste przeciecie z elementem A na indeksie i*/
        while(j < B.rozmiar && ((B.tab[j].a <= a.a && a.a <= B.tab[j].b) || (a.a <= B.tab[j].a && B.tab[j].a <= a.b)) && a.a<=a.b && modulo(B.tab[j].b) == modulo(a.a))
        {
            ciag b = B.tab[j];
            // Przypadek 1: ciag b jest infixem ciagu a
            if(a.a <= b.a && b.b <= a.b)
            {
                dodaj(&wynik, (ciag){a.a, b.a-global_q});
                a = (ciag){b.b+global_q, a.b};
            }
            // Przypadek 2: ciag a jest infixem ciagu b (ustawiam dowolny niepoprawny ciag o a.a > a.b)
            else if(b.a <= a.a && a.b <= b.b)
                a = (ciag){1, -1};
            // Przypadek 2: ciag b jest prefixem ciagu a
            else if(b.a <= a.a && a.a <= b.b)
                a = (ciag){b.a+global_q, a.b};
            // Przypadek 3: ciag b jest suffixem ciagu a 
            else
                a = (ciag){a.a, b.b-global_q};
            j++;
        }
        // Ciag B.tab[j] moze 'wplywac' na wiecej niz jeden ciag w A
        j--;
        dodaj(&wynik, a);
        i++;
    }
    return wynik;
}

bool nalezy(zbior_ary A, int b)
{
    if(A.rozmiar == 0)
        return 0;
    unsigned l = 0, r = A.rozmiar - 1;
    int mod = modulo(b);
    unsigned start, stop;
    /* Najpierw uzywam wyszukiwania binarnego, aby wyszukac pierwszego i ostatniego elementu w A
    o takiej samej reszcie z dzielenia przez q co b */
    while(l<r)
    {
        unsigned m = l + (r - l) / 2;
        if(modulo(A.tab[m].a) < mod)
            l = m+1;
        else
            r = m;
    }
    if(modulo(A.tab[l].a) != mod) 
        return false;

    start = l;
    l = 0, r = A.rozmiar - 1;
    while(l<r)
    {
        unsigned m = l + (r - l + 1) / 2;
        if(modulo(A.tab[m].a) > mod)
            r = m-1;
        else
            l = m;
    }
    stop = r;
    if(start > stop)
        return false;
    /* Znajac pierwszy i ostatni element sprawdzam czy istnieje taki ciag, ktory zawiera b */
    l = start, r = stop;
    while(l < r)
    {
        unsigned m = l + (r - l + 1) / 2;
        if(A.tab[m].a <= b)
            l = m;
        else
            r = m - 1;
    }
    return (A.tab[l].a <= b && b <= A.tab[l].b);
}

unsigned moc(zbior_ary A)
{ 
    unsigned wynik = 0;
    for(unsigned i=0;i<A.rozmiar;i++)
        wynik += (unsigned)(A.tab[i].b - A.tab[i].a) / (unsigned)global_q + 1;
    return wynik;
}

unsigned ary(zbior_ary A)
{
    return A.rozmiar;
}

