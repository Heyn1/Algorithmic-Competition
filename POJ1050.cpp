#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
const int maxn = 105;

int arr[maxn][maxn], ans[maxn][maxn], n, sum;

int main() {
	scanf("%d", &n);
	int tmp;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &tmp);
			arr[i][j] = tmp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	int res = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			sum = 0;
			for (int k = 1; k <= n; ++k) {
				sum += arr[j][k] - arr[j][k - 1] - arr[i - 1][k] + arr[i - 1][k - 1];
				res = max(res, sum);
				if (sum < 0)
					sum = 0;
			}
		}
	}
	printf("%d\n", res);
	
	return 0;
}