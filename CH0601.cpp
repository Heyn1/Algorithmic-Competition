#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 500005;
int k, n, m, ans;
ll a[maxn], b[maxn];
ll t;

bool islegal(vector<int> v) {
	if (v.size() <= 1)
		return true;
	ll s = 0;
	int p = 0, q = v.size() - 1, cnt = m;
	while (p < q && cnt--) {
		ll gap = v[q] - v[p];
		s += gap *gap;
		if (s > t)
			return false;
		++p; --q;
	}
	return true;
}
bool combine(int l, int r, int nr) {
	sort(b + r + 1, b + nr + 1);
	vector<int> v;
	int p = l, q = r + 1;
	while (p <= r && q <= nr) {
		if (b[p] < b[q])
			v.push_back(b[p++]);
		else
			v.push_back(b[q++]);
	}
	while (p <= r)
		v.push_back(b[p++]);
	while (q <= nr)
		v.push_back(b[q++]);
	if (islegal(v)) {
		int i = l;
		for (auto x : v) {
			a[i] = b[i] = x;
			++i;
		}
		return true;
	}
	else {
		for (int i = r + 1; i <= nr; ++i)
			b[i] = a[i];
		return false;
	}
}
void solve() {
	int l = 0, r = 0;
	ans = 0;
	while (l < n) {
		int nr, d = 1;
		while (d) {
			nr = r + d;
			if (nr < n && combine(l, r, nr)) {
				r = nr;
				d *= 2;
			}
			else
				d /= 2;
		}
		++ans;
		r = l = min(r + 1, n);
	}
}
int main() {
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d%lld", &n, &m, &t);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
			b[i] = a[i];
		}
		solve();
		printf("%d\n", ans);
	}

	return 0;
}