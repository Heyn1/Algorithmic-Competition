#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

int t, n;
struct node {
	ll s, e, d;
} equip[200005];

bool cmp (const node &a, const node &b) {
	if (a.e == b.e)
		return a.s < b.s;
	return a.e < b.e;
}
ll cnt(ll k) {
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (equip[i].s <= k)
			res += ((min(equip[i].e, k) - equip[i].s) / equip[i].d + 1);
	}
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%lld%lld%lld", &(equip[i].s), &(equip[i].e), &(equip[i].d));
		sort(equip + 1, equip + n + 1, cmp);
		ll l = 1, r = 1ll << 31 - 1, mid;
 		while (l < r) {
			mid = (l + r) >> 1;
			ll tmp = cnt(mid);
			if (tmp & 1)
				r = mid;
			else
				l = mid + 1;
		}
		ll ans = cnt(l) - cnt(l - 1);
		if (ans & 1)
			printf("%lld %lld\n", l, ans);
		else
			printf("There's no weakness.\n");
	}

	return 0;
}