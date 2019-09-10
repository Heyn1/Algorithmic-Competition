#include <cstdio>
#include <iostream>
using namespace std;
long long ans = 0;
int nums[250005], tmp[250005], n;
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
	for (i = l; i < r; ++i)
		nums[i] = tmp[i];
}
int main() {
	while (~scanf("%d", &n) && n) {
		int tnum = 0, sum = 0;
		long long last;
		for (int i = 0; i < n * n; ++i) {
			scanf("%d", &tnum);
			if (tnum != 0)
				nums[sum++] = tnum;
		}
		ans = 0;
		merge(0, sum);
		last = ans;
		ans = 0;
		sum = 0;
		for (int i = 0; i < n * n; ++i) {
			scanf("%d", &tnum);
			if (tnum != 0)
				nums[sum++] = tnum;
		}
		merge(0, sum);
		if ((last % 2 == 0) == (ans % 2 == 0))
			printf("TAK\n");
		else
			printf("NIE\n");
	}

	return 0;
}