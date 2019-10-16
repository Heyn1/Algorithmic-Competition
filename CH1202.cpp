#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;

int main() {
	long long n, m, q, u, v, t, tmp, delta = 0;
	scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &q, &u, &v, &t);
	priority_queue<long long, vector<long long>, less<long long> > a;
	queue<long long> b, c;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &tmp);
		a.push(tmp);
	}
	for (long long i = 1; i <= m; ++i) {
		long long s1 = INT_MIN, s2 = INT_MIN, s3 = INT_MIN, maxn = INT_MIN;
		if (!a.empty())
			s1 = a.top() + delta;
		if (!b.empty())
			s2 = b.front() + delta;
		if (!c.empty())
			s3 = c.front() + delta;
		maxn = max(s1, max(s2, s3));
		if (i % t == 0)
			printf("%lld ", maxn);
		if (s1 == maxn) {
			a.pop();
		}
		else if (s2 == maxn) {
			b.pop();
		}
		else if (s3 == maxn) {
			c.pop();
		}
		b.push((maxn * u) / v - delta - q);
		c.push(maxn - (maxn * u) / v - delta - q);
		delta += q;
	}
	printf("\n");
	for (long long i = 1; i <= n + m; ++i) {
		long long s1 = INT_MIN, s2 = INT_MIN, s3 = INT_MIN, maxn = INT_MIN;
		if (!a.empty())
			s1 = a.top();
		if (!b.empty())
			s2 = b.front();
		if (!c.empty())
			s3 = c.front();
		maxn = max(s1, max(s2, s3));
		if (maxn == s1)
			a.pop();
		else if (maxn == s2)
			b.pop();
		else if (maxn == s3)
			c.pop();
		if (i % t == 0) {
			printf("%lld ", maxn + delta);
		}
	}
	printf("\n");

	return 0;
}