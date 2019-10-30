#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#define inf 0x7fffffff
using namespace std;
const int maxn = 100005;

struct heap {
	int v, x;
} h[2 * maxn];
int a[maxn], pre[maxn], nxt[maxn], pos[maxn], m, n, sz = 0, ans;

inline int read() {
	char ch = getchar();
	int f = 1, x = 0;
	while (!(ch >= '0' && ch <= '9')) {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return f * x;
}
void pushup(int x) {
	while (h[x].v < h[x >> 1].v) {
		pos[h[x >> 1].x] = x;
		swap(h[x], h[x >> 1]);
		x = x >> 1;
	}
	pos[h[x].x] = x;
}
void push(int v, int x) {
	h[++sz].v = v;
	h[sz].x = x;
	pos[x] = sz;
	pushup(sz);
}
void init() {
	n = read();
	m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	for (int i = 2; i <= n; ++i) {
		push(a[i] - a[i - 1], i);
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	pre[2] = nxt[n] = -1;
}
void pushdown(int x) {
	int to;
	while ((x << 1) <= sz) {
		to = (x << 1);
		if (to < sz && h[to].v > h[to + 1].v)
			to++;
		if (h[x].v > h[to].v) {
			pos[h[to].x] = x;
			swap(h[to], h[x]);
			x = to;
		}
		else
			break;
	}
	pos[h[x].x] = x;
}
void del(int x) {
	h[x].v = inf;
	pushdown(x);
}
void solve() {
	int a, b;
	heap k;
	for (int i = 1; i <= m; ++i) {
		k = h[1];
		if (pre[k.x] == -1) {
			ans += k.v;
			del(1);
			del(pos[nxt[k.x]]);
			pre[nxt[nxt[k.x]]] = -1;
		}
		else if (nxt[k.x] == -1) {
			ans += k.v;
			del(1);
			del(pos[pre[k.x]]);
			nxt[pre[pre[k.x]]] = -1;
		}
		else {
			ans += k.v;
			a = nxt[k.x];
			b = pre[k.x];
			pre[k.x] = pre[b];
			nxt[pre[b]] = k.x;
			nxt[k.x] = nxt[a];
			pre[nxt[a]] = k.x;
			h[1].v = h[pos[a]].v + h[pos[b]].v - h[1].v;
			pushdown(1);
			del(pos[a]);
			del(pos[b]);
		}
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}

