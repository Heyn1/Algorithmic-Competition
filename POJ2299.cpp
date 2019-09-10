#include <iostream>
#include <cstdio>
using namespace std;
long long ans = 0;
int nums[500005], tmp[500005], n;
void merge(int l, int r) {
	if (r - l <= 1)
		return;
	int mid = l + (r - l) / 2;
	merge(l, mid);
	merge(mid, r);
	int i = l, j = mid, k = l;
	while (i < mid || j < r) {
		if (j >= r || (i < mid && nums[i] <= nums[j]))
			tmp[k++] = nums[i++];
		else {
			if (i < mid)
				ans += mid - i;
			tmp[k++] = nums[j++];
		}
	}
	for (int k = l; k < r; ++k)
		nums[k] = tmp[k];
}
int main() {
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &nums[i]);
		}
		ans = 0;
		merge(0, n);
		ans = 0;
		printf("%lld\n", ans);
	}

	return 0;
}