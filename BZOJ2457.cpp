#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long
const int maxn = 200005;

pair<ll, ll> num[maxn];

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ll n, tmp;
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf("%lld", &tmp);
		num[i] = make_pair(tmp, i);
	}
	sort(num, num + n, cmp);
	bool t = false;
	ll pre = INT_MAX, ans = 1;
	for (ll i = 0, j; i < n; ++i) {
		j = i + 1;
		while (j < n && num[j].first == num[i].first)
			++j;
		--j;
		// cout << "j: " << num[j].second << endl;
		if (t) {
			if (pre > num[i].second) {
				++ans;
				t = false;
				pre = num[i].second;
			}
			else
				pre = num[j].second;
		}
		else {
			if (num[j].second > pre) {
				t = true;
				pre = num[j].second;
			}
			else
				pre = num[i].second;
		}
		i = j;
	}
	printf("%lld\n", ans);

	return 0;
}