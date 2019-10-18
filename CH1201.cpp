#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
#define ll long long
const int maxn = 300005;

ll num[maxn], sum[maxn], q[maxn], n, m;

int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &(num[i]));
		sum[i] = sum[i - 1] + num[i];
	}
	ll l = 1, r = 1, ans = INT64_MIN;
	q[1] = 0;
	for (int i = 1; i <= n; ++i) {
		while (l <= r && q[l] < i - m)
			++l;
		ans = max(ans, sum[i] - sum[q[l]]);
		while (l <= r && sum[q[r]] >= sum[i])
			--r;
		q[++r] = i;
	}
	printf("%lld\n", ans);

	return 0;
}