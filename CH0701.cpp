#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
#define vint vector<int>
const int N = 1005;
struct node {
	int l, r;
} a[N];
int n, m, i, j, k;
vint now, ans;
void out(vint ans) {
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i];
	cout << endl;
}
int cmp(node a, node b) {
	if (a.l * a.r == b.l * b.r)
		return a.r < b.r;
	return a.l * a.r < b.l * b.r;
}
vint max_2(vint a, vint b) {
	if (a.size() != b.size())
		return a.size() > b.size() ? a : b;
	return a > b ? a : b;
}
vint mul(vint a, int x) {
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i)
		a[i] *= x;
	for (int i = 0; i < a.size(); ++i) {
		if (i < a.size() - 1)
			a[i + 1] += a[i] / 10;
		else if (a[i] >= 10)
			a.push_back(a[i] / 10);
		a[i] %= 10;
	}
	reverse(a.begin(), a.end());
	return a;
}
vint dis(vint a, int x) {
	vint c;
	int ok = true, s = 0;
	for (int i = 0; i < a.size(); ++i) {
		s = s * 10 + a[i];
		if (!ok || s >= x) {
			ok = false;
			c.push_back(s / x);
		}
		s %= x;
	}
	return c;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i <= n; ++i)
		cin >> a[i].l >> a[i].r;
	sort(a + 1, a + 1 + n, cmp);
	now.push_back(1);
	for (int i = 1; i <= n; ++i) {
		now = mul(now, a[i - 1].l);
		ans = max_2(ans, dis(now, a[i].r));
	}
	out(ans);

	return 0;
}