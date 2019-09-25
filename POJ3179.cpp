#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
const int maxn = 505;

int posx[maxn], posy[maxn], pos[2 * maxn], s[2 * maxn][2 * maxn], c, n, len;

int getsum(int si, int sj, int ei, int ej) {
	return s[ei][ej] - s[ei][sj - 1] - s[si - 1][ej] + s[si - 1][sj - 1];
}
bool check(int mid) {
	if (pos[len] < mid) {
		if (s[len][len] >= c)
			return true;
		else
			return false;
	}
	int end = upper_bound(pos + 1, pos + len + 1, pos[len] - mid + 1) - pos - 1;
	int tx, ty;
	for (int i = 1; i <= end; ++i) {
		for (int j = 1; j <= end; ++j) {
			tx = upper_bound(pos + 1, pos + len + 1, pos[i] + mid - 1) - pos - 1;
			ty = upper_bound(pos + 1, pos + len + 1, pos[j] + mid - 1) - pos - 1;
			if (getsum(i, j, tx, ty) >= c)
				return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &c, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &posx[i], &posy[i]);
		pos[++len] = posx[i];
		pos[++len] = posy[i];
	}
	sort(pos + 1, pos + len + 1);
	len = unique(pos + 1, pos + len + 1) - pos - 1;
	int tx, ty;
	for (int i = 1; i <= n; ++i) {
		tx = lower_bound(pos + 1, pos + len + 1, posx[i]) - pos;
		ty = lower_bound(pos + 1, pos + len + 1, posy[i]) - pos;
		s[tx][ty] += 1;
	}
	pos[++len] = 10010;
	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j <= len; ++j)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
	}
	int l = 1, r = 10000, mid, ans = 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	printf("%d\n", ans);

	return 0;
}