#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define ll long long
const int maxn = 100005;

int n, p;
ll w[maxn], a[maxn], h, ans = 0, wid;

int main() {
	while (~scanf("%d", &n) && n) {
//		memset(w, 0, sizeof w);
//		memset(a, 0, sizeof a);
		p = 0;
		ans = 0;
		a[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &h);
			if (h > a[p]) {
				a[++p] = h;
				w[p] = 1;
			}
			else {
				wid = 0;
				while (a[p] > h) {
					wid += w[p];
					ans = max(ans, wid * a[p]);
					--p;
//					printf("hey: %lld\n", ans);
				}
				a[++p] = h;
				w[p] = wid + 1;
			}
		}
		wid = 0;
		while (p) {
			wid += w[p];
			ans = max(ans, wid * a[p]);
			--p;
//			printf("wow: %lld\n", ans);
		}
		printf("%lld\n", ans);
	}

	return 0;
}