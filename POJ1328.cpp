#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
bool f;
int n, index = 1, sum;
double d, now;
pair<double, double> range[1005];
bool cmp(const pair<double, double> &a, const pair<double, double> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
int main() {
	while (~scanf("%d%lf", &n, &d) && (n || d)) {
		f = true;
		sum = 0;
		now = INT_MIN;
		for (int i = 0; i < n; ++i) {
			double a, b;
			scanf("%lf%lf", &a, &b);
			if (d < b) {
				f = false;
				continue;
			}
			range[i].first = a - sqrt(d * d - b * b);
			range[i].second = a + sqrt(d * d - b * b);
		}
		if (!f) {
			printf("Case %d: %d\n", index++, -1);
			continue;
		}
		sort(range, range + n, cmp);
		for (int i = 0; i < n; ++i) {
			if (range[i].first > now) {
				++sum;
				now = range[i].second;
			}
			else {
				now = min(now, range[i].second);
			}
		}
		printf("Case %d: %d\n", index++, sum);
	}

	return 0;
}