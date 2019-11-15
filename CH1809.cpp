#include <cstdio>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

const int maxn = 200005;
int nxt[maxn], f[maxn], cnt[maxn], n, m, q;
char a[maxn], b[maxn];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	scanf("%s", b + 1);
	scanf("%s", a + 1);
	nxt[1] = 0;
	for (int i = 2, j = 0; i <= m; ++i) {
		while (j > 0 && a[i] != a[j + 1])
			j = nxt[j];
		if (a[i] == a[j + 1])
			++j;
		nxt[i] = j;
	}
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j > 0 && b[i] != a[j + 1])
			j = nxt[j];
		if (b[i] == a[j + 1])
			++j;
		f[i] = j;
	}
	for (int i = 1; i <= n; ++i)
		++cnt[f[i]];
	for (int i = m; i > 0; --i)
		cnt[nxt[i]] += cnt[i];

	while (q--) {
		int p;
		scanf("%d", &p);
		printf("%d\n", cnt[p] - cnt[p + 1]);
	}

	return 0;
}