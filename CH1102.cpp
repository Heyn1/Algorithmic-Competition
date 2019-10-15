#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
const int maxn = 60005;
const ll M = 1000000000;

ll a[maxn], sum[maxn * 2], l;
int n;

void prime(int b, int f) {
	for (int j = 2; j * j <= b && b != 1; ++j) {
		while (b % j == 0) {
			sum[j] += f;
			b /= j;
		}
	}
	if (b)
		sum[b] += f;
}
void high(ll c) {
	for (int i = 1; i <= l; ++i)
		a[i] *= c;
	for (int i = 1; i <= l; ++i)
		a[i + 1] += a[i] / M, a[i] %= M;
	while (a[l + 1])
		++l;
}

int main() {
	l = 1;
	a[1] = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		prime(n + i, 1);
	for (int i = 2; i <= n + 1; ++i)
		prime(i, -1);
	for (int i = 2; i <= 2 * n; ++i)
		for (ll j = 0; j < sum[i]; ++j)
			high(i);
	printf("%lld", a[l]);
	for (ll i = l - 1; i; --i)
		printf("%09lld", a[i]);
	printf("\n");
	
	return 0;
}