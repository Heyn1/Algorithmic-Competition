#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 10005;

int posx[maxn], posy[maxn], midx[maxn], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &posx[i]);
		scanf("%d", &posy[i]);
	}
	sort(posx + 1, posx + n + 1);
	sort(posy + 1, posy + n + 1);
	int mid = (n + 1) / 2, ans = 0;
	for (int i = 1; i <= n; ++i)
		posx[i] -= (i - 1);
	sort(posx + 1, posx + n + 1);
	for (int i = 1; i <= n; ++i) {
		ans += (abs(posx[i] - posx[mid]) + abs(posy[i] - posy[mid]));
	}
	printf("%d\n", ans);

	return 0;
}