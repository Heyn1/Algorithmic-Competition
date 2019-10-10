#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100005;

int num[105], n, m;
pair<int, int> machine[maxn], task[maxn];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(num, 0, sizeof num);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &(machine[i].first), &(machine[i].second));
		for (int i = 0; i < m; ++i)
			scanf("%d%d", &(task[i].first), &(task[i].second));
		sort(machine, machine + n, cmp);
		sort(task, task + m, cmp);
		int j = 0, cnt = 0;
		long long ans = 0;
		for (int i = 0; i < m; ++i) {
			while (j < n && task[i].first <= machine[j].first) {
				num[machine[j].second]++;
				j++;
			}
			for (int k = task[i].second; k <= 100; ++k) {
				if (num[k]) {
					cnt++;
					ans += task[i].first * 500 + task[i].second * 2;
					num[k]--;
					break;
				}
			}
		}
		printf("%d %lld\n", cnt, ans);
	
		return 0;
	}
}