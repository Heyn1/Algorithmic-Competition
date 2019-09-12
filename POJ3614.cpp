#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int c, l;
int milk[2505];
pair<int, int> cows[2505];
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}
int main() {
	scanf("%d%d", &c, &l);
	for (int i = 0; i < c; ++i)
		scanf("%d%d", &(cows[i].first), &(cows[i].second));
	for (int i = 0; i < l; ++i) {
		int idx, tmp;
		scanf("%d%d", &idx, &tmp);
		milk[idx] += tmp;
	}
	sort(cows, cows + c, cmp);
	int ans = 0;
	for (int i = 0; i < c; ++i) {
		for (int j = cows[i].second; j >= cows[i].first; --j) {
			if (milk[j]) {
				++ans;
				--milk[j];
				break;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}