#include <stdio.h>
const long long K = 32;

long long kodowanie(long long a, long long b)
{
	return (a << K) + b;
}

void dekodowanie(long long hsh, long long *a, long long *b)
{
	*a = hsh >> K;
	*b = hsh % (1LL<<K);
}

int main()
{
	long long a, b, c, d, hsh;
	scanf("%lld%lld", &a, &b);
	hsh = kodowanie(a, b);
	dekodowanie(hsh, &c, &d);
	printf("Liczby przed kodowaniem %lld %lld\n.", a, b);
	printf("Hash liczb po kodowaniu %lld\n", hsh);
	printf("Liczby odkodowane %lld %lld\n", c, d);
	return 0;
}