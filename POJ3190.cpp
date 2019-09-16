#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int n, ans = 0, use[50005];
struct cow {
	int id;
	int start;
	int end;
	bool operator < (const struct cow &a) const {
		if (end == a.end)
			return start > a.start;
		return end > a.end;
	}
} cows[50005];
priority_queue<cow> q;
bool cmp(const struct cow &a, const struct cow &b) {
	return a.start < b.start;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		cows[i].id = i;
		cows[i].start = a;
		cows[i].end = b;
	}
	sort(cows, cows + n, cmp);
	q.push(cows[0]);
	int now = 0;
	ans = 1;
	use[cows[0].id] = 1;
	for (int i = 1; i < n; ++i) {
		if (!q.empty() && q.top().end < cows[i].start) {
			use[cows[i].id] = use[q.top().id];
			q.pop();
		}
		else {
			++ans;
			use[cows[i].id] = ans;
		}
		q.push(cows[i]);
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i)
		printf("%d\n", use[i]);

	return 0;
}