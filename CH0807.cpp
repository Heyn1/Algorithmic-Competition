#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1000005;

long long a[maxn], s[maxn], n, sum = 0;

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	sum /= n;
	for (int i = 1; i <= n; ++i) {
		a[i] -= sum;
		s[i] += (a[i] + s[i - 1]);
	}
	sort(s + 1, s + n + 1);
	long long mid, ans = 0;
	if (n & 1)
		mid = s[(n + 1) / 2];
	else
		mid = s[n / 2];
	for (int i = 1; i <= n; ++i)
		ans += abs(s[i] - mid);
	printf("%lld\n", ans);

	return 0;
}