#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxr = 10005;
const int maxc = 80;
int nxtr[maxr], nxtc[maxc], buckr[maxr], buckc[maxc], r, c, lenr = 1, lenc = 1;
char grid[maxr][maxc];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

void calc(int ind, bool flg) {
	if (flg) {
		memset(nxtc, 0, sizeof nxtc);
		nxtc[1] = 0;
		for (int i = 2, j = 0; i <= c; ++i) {
			while (j > 0 && grid[ind][i] != grid[ind][j + 1])
				j = nxtc[j];
			if (grid[ind][i] == grid[ind][j + 1])
				++j;
			nxtc[i] = j;
		}
	}
	else {
		memset(nxtr, 0, sizeof nxtr);
		nxtr[1] = 0;
		for (int i = 2, j = 0; i <= r; ++i) {
			while (j > 0 && grid[i][ind] != grid[j + 1][ind])
				j = nxtr[j];
			if (grid[i][ind] == grid[j + 1][ind])
				++j;
			nxtr[i] = j;
		}
	}
}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; ++i)
		scanf("%s", grid[i] + 1);
	for (int i = 1; i <= r; ++i) {
		calc(i, true);
		lenc = lcm(lenc, c - nxtc[c]);
		if (lenc >= c) {
			lenc = c;
			break;
		}
	}
	for (int i = 1; i <= c; ++i) {
		calc(i, false);
		lenr = lcm(lenr, r - nxtr[r]);
		if (lenr >= r) {
			lenr = r;
			break;
		}
	}
	// for (int i = 1; i <= r; ++i)
	// 	printf("%d ", nxtr[i]);
	// printf("\n");
	// for (int i = 1; i <= c; ++i)
	// 	printf("%d ", nxtc[i]);	
	// printf("%d\n", lenc * lenr);

	return 0;
}