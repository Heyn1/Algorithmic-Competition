#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 10005;

int pro[maxn], tot = 0, n;
pair<int, int> prod[maxn];

void down(int i) {
	int s = i * 2;
	while (s <= tot) {
		if (s < tot && pro[s] > pro[s + 1])
			s++;
		if (pro[s] < pro[i]) {
			swap(pro[s], pro[i]);
			i = s;
			s = i * 2;
		}
		else
			break;
	}
}
void up(int i) {
	while (i > 1) {
		if (pro[i] < pro[i / 2]) {
			swap(pro[i], pro[i / 2]);
			i /= 2;
		}
		else
			break;
	}
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

int main() {
	while (~scanf("%d", &n)) {
		tot = 0;
		memset(pro, 0, sizeof pro);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &(prod[i].first), &(prod[i].second));
		}
		sort(prod, prod + n, cmp);
		for (int i = 0; i < n; i++) {
			if (prod[i].second == tot) {
				if (pro[1] < prod[i].first) {
					pro[1] = prod[i].first;
					down(1);
				}
			}
			else if (prod[i].second > tot) {
				pro[++tot] = prod[i].first;
				up(tot);
			}
		}
		int ans = 0;
		for (int i = 1; i <= tot; i++)
			ans += pro[i];
		printf("%d\n", ans);
	}

	return 0;
}