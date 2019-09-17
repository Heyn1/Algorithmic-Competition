#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;
struct node {
	int val;
	int father;
	int t;
	double w;
} rst[1005];
int n, r, pos, fa, res, u, v;
int findpos() {
	int tmp;
	double tmpw = 0;
	for (int i = 1; i <= n; ++i) {
		if (rst[i].w > tmpw && i != r) {
			tmpw = rst[i].w;
			tmp = i;
		}
	}
	return tmp;
}
int main() {
	while (~scanf("%d%d", &n, &r) && n + r) {
		res = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &rst[i].val);
			rst[i].w = rst[i].val;
			rst[i].t = 1;
			res += rst[i].val;
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &u, &v);
			rst[v].father = u;
		}
		for (int i = 1; i < n; ++i) {
			pos = findpos();
			rst[pos].w = 0;
			fa = rst[pos].father;
			res += rst[pos].val * rst[fa].t;
			for (int j = 1; j <= n; ++j) {
				if (rst[j].father == pos)
					rst[j].father = fa;
			}
			rst[fa].t += rst[pos].t;
			rst[fa].val += rst[pos].val;
			rst[fa].w = (double)rst[fa].val / rst[fa].t;
		}
		printf("%d\n", res);
	}

	return 0;
}