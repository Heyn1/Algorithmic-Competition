#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1000005;
struct ELem {
	int val, ind;
}priq[maxn];
int nums[maxn], n, k, l, r, sum = 0;

void getmin() {
	memset(priq, 0, sizeof priq);
	priq[0].val = -INF;
	l = r = 1;
	for (int i = 1; i <= k; i++) {
		while (priq[r].val >= nums[i] && l <= r)
			r--;
		priq[++r].val = nums[i];
		priq[r].ind = i;
	}
	for (int i = k; i <= n; i++) {
		while (priq[r].val >= nums[i] && l <= r)
			r--;
		priq[++r].val = nums[i];
		priq[r].ind = i;
		while (priq[l].ind <= i - k)
			l++;
		printf("%d ", priq[l].val);
	}
}
void getmax() {
	memset(priq, 0, sizeof priq);
	priq[0].val = INF;
	l = r = 1;
	for (int i = 1; i <= k; i++) {
		while (priq[r].val <= nums[i] && l <= r)
			r--;
		priq[++r].val = nums[i];
		priq[r].ind = i;
	}
	for (int i = k; i <= n; i++) {
		while (priq[r].val <= nums[i] && l <= r)
			r--;
		priq[++r].val = nums[i];
		priq[r].ind = i;
		while (priq[l].ind <= i - k)
			l++;
		printf("%d ", priq[l].val);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", nums + i);
	getmin();
	printf("\n");
	getmax();
	printf("\n");

	return 0;
}