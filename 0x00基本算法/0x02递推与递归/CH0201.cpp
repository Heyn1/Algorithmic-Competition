#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

int matrix[5][5];
int cp[5][5];
int pos[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void turn(int i, int j) {
	cp[i][j] = (cp[i][j] == 0 ? 1 : 0);
	for (int k = 0; k < 4; ++k) {
		int ni = i + pos[k][0], nj = j + pos[k][1];
		if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5) {
			cp[ni][nj] = (cp[ni][nj] == 0 ? 1 : 0);
		}
	}
}

int calc() {
	int ans = INT_MAX;

	for (int i = 0; i < 32; ++i) {
		int tmp = i, index = -1, op = 0;
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k)
				cp[j][k] = matrix[j][k];
		}
		while (tmp) {
			++index;
			if (tmp & 1) {
				++op;
				turn(0, index);
			}
			tmp >>= 1;
		}
		for (int j = 1; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				if (cp[j - 1][k]) {
					turn(j, k);
					++op;
				}
			}
		}
		bool f = true;
		for (int j = 0; j < 5; ++j) {
			if (cp[4][j]) {
				f = false;
				break;
			}
		}
		if (f)
			ans = min(ans, op);
	}

	return ans;
}

int main() {
	printf("Please input the matrix: \n");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			scanf("%d", &matrix[i][j]);
	}

	// printf("hey\n");
	int ans = calc();
	
	printf("The result: %d\n", (ans == INT_MAX ? -1 : ans));

	return 0;
}
