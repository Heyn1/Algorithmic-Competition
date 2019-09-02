#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <inttypes.h>
using namespace std;
typedef long long ll;

pair<ll, ll> calc(ll n, ll m) {
	if (n == 0)
		return make_pair(0, 0);
	ll len = 1ll << (n - 1), cnt = 1ll << (2 * n - 2);
	pair<ll, ll> pos = calc(n - 1, m % cnt);
	ll x = pos.first, y = pos.second;
	ll z = m / cnt;
	if (z == 0) return make_pair(y, x);
	if (z == 1) return make_pair(x, y + len);
	if (z == 2) return make_pair(x + len, y + len);
	return make_pair(2 * len - y - 1, len - x - 1);
}

int main() {
	int t;
	ll n, s, d;
	printf("Please input T: ");
	scanf("%d", &t);
	while (t--) {
		printf("Please input N, S, D: ");
		scanf("%lld%lld%lld", &n, &s, &d);

		--s; --d;
		pair<ll, ll> a = calc(n, s);
		pair<ll, ll> b = calc(n, d);
        long double i = fabs((long double)a.first - (long double)b.first);
        long double j = fabs((long double)a.second - (long double)b.second);
		long double tmp = sqrt(i * i + j * j) * 10;
		ll k = (ll)tmp;
		if (tmp - k >= 0.5)
            ++k;
		printf("The distance is: %lld\n", k);
	}

	return 0;
}
