#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int ans = 0, k;
int ind[13];
char cards[13][4];
unordered_map<int, int> vis;

int cti(char c) {
	int res;
	switch (c) {
		case 'A': res = 0; break;
		case '0': res = 9; break;
		case 'J': res = 10; break;
		case 'Q': res = 11; break;
		case 'K': res = 12; break;
		default: res = c - '0' - 1;
	}
	return res;
}

void solve(int step) {
//	cout << "k: " << k << endl;
	if (step == 0) {
		if (ind[12] == 4)
			return;
		else {
			k = cti(cards[12][ind[12]++]);
			if (k == 12)
				solve(0);
			else
				solve(1);
		}
	}
	else if (step == 1) {
//		if (ind[k] < 0)
//			solve(0);
		int tmp = cti(cards[k][ind[k]--]);
		vis[k]++;
		if (vis[k] == 4)
			++ans;
		if (tmp == 12) {
			solve(0);
		}
		else {
			k = tmp;
			solve(1);
		}
	}
}

int main() {
	for (int i = 0; i < 13; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> cards[i][j];
		}
		ind[i] = 3;
	}
	ind[12] = 0;
	solve(0);
	cout << ans << endl;

	return 0;
}