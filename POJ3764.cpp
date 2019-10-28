#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100005;

struct node {
	int v, w, next;
} edge[maxn * 2];
int head[maxn], val[maxn], vis[maxn], trie[maxn * 32][2], n, edgeSum = 0, tot = 1, ans = -1;

void addEdge(int u, int v, int w) {
	edge[edgeSum].v = v;
	edge[edgeSum].w = w;
	edge[edgeSum].next = head[u];
	head[u] = edgeSum++;
}
void dfs(int u, int x) {
	val[u] = x;
	vis[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next) {
		int v = edge[i].v;
		int w = edge[i].w;
		if (!vis[v])
			dfs(v, x ^ w);
	}
}
void insert(const int &num) {
	int p = 1;
	for (int i = 31; i >= 0; i--) {
		int k = (num >> i) & 1;
		if (trie[p][k] == 0)
			trie[p][k] = ++tot;
		p = trie[p][k];
	}
}
int search(const int &num) {
	int p = 1, res = 0;
	for (int i = 31; i >= 0; i--) {
		int k = (num >> i) & 1;
		if (trie[p][!k]) {
			p = trie[p][!k];
			res += (1 << i);
		}
		else if (trie[p][k]) {
			p = trie[p][k];
		}
		else return -1;
	}
	return res;
}

int main() {
	while (~scanf("%d", &n)) {
		edgeSum = 0;
		memset(head, -1, sizeof head);
		memset(vis, 0, sizeof vis);
		memset(trie, 0, sizeof trie);
		int u, v, w;
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &u, &v, &w);
			u++;
			v++;
			addEdge(u, v, w);
			addEdge(v, u, w);
		}
		dfs(1, 0);
		tot = 1;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			insert(val[i]);
			ans = max(ans, search(val[i]));
		}
		printf("%d\n", ans);
	}

	return 0;
}