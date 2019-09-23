#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int n;
char fac[1005][1005];
void calc(int x, int y, int k) {
	if (k == 1) {
		fac[x][y] = 'X';
		return;
	}
	else {
		int len = (int)pow(3, k - 2);
		calc(x, y, k - 1);
		calc(x, y + 2 * len, k - 1);
		calc(x + len, y + len, k - 1);
		calc(x + 2 * len, y, k - 1);
		calc(x + 2 * len, y + 2 * len, k - 1);
	}
}

int main() {
	while (~scanf("%d", &n) && n != -1) {
		memset(fac, ' ', sizeof fac);
		calc(0, 0, n);
		int len = (int)pow(3, n - 1);
		for (int i = 0; i < len; ++i) {
			fac[i][len] = '\0';
			printf("%s\n", fac[i]);
		}
		printf("-\n");
	}

	return 0;
}