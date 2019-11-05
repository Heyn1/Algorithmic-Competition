#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int array[maxn][maxn], sum[maxn][maxn], stack[maxn], weight[maxn], n, m, p;

int main() {
	scanf("%d%d", &n, &m);
	// printf("%d%d", n, m);
	getchar();
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c = getchar();
			getchar();
			// printf("c: %c\n", c);
			if (c == 'F') {
				// printf("i: %d\nj: %d\n", i, j);
				array[i][j] = 1;
				sum[i][j] = 1;
			}
			
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = n; i >= 1; i--) {
			if (array[i][j])
				sum[i][j] += sum[i + 1][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		p = 0;
		int tmp = 0;
		memset(weight, 0, sizeof weight);
		for (int j = 1; j <= m + 1; j++) {
			// printf("%d ", sum[i][j]);
			if (sum[i][j] > stack[p]) {
				stack[++p] = sum[i][j];
				weight[p] = 1;
			}
			else {
				int wid = 0;
				while (stack[p] > sum[i][j]) {
					wid += weight[p];
					tmp = max(tmp, wid * stack[p]);
					p--;
				}
				stack[++p] = sum[i][j];
				weight[p] = wid + 1;
			}
		}
		// printf("\n");
		ans = max(ans, tmp);
	}
	printf("%d\n", 3 * ans);

	return 0;
}