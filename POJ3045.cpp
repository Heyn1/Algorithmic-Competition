#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 50005;

int n;
pair<int, int> cows[maxn];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first + a.second < b.first + b.second;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &cows[i].first, &cows[i].second);
	}
	sort(cows, cows + n, cmp);
	int ans = INT_MIN, sum = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, sum - cows[i].second);
		sum += cows[i].first;
	}
	printf("%d\n", ans);

	return 0;
}