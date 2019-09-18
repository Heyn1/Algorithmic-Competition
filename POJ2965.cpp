#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int mask[1 << 16], vis[1 << 16], step[1 << 16];
queue<int> q;
void init() {
	int row[4] = {0x0F << 0, 0x0F << 4, 0x0F << 8, 0x0F << 12};
	int col[4] = {
		1 << 0 | 1 << 4 | 1 << 8 | 1 << 12,
		1 << 1 | 1 << 5 | 1 << 9 | 1 << 13,
		1 << 2 | 1 << 6 | 1 << 10 | 1 << 14,
		1 << 3 | 1 << 7 | 1 << 11 | 1 << 15
	};
	for (int i = 0; i < 16; ++i)
		mask[i] = 1 << i ^ row[i / 4] ^ col[i % 4];
}

void print(int num) {
	int cnt = 0;
	for (int i = 0; i < 16; ++i) {
		if (num >> i & 0x01) {
			++cnt;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 16; ++i) {
		if (num >> i & 0x01) {
			printf("%d %d\n", i / 4 + 1, i % 4 + 1);
		}
	}
}

int main() {
	int now = 0, k = 0;
	init();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (getchar() == '+') {
				now |= 1 << k;
			}
			k++;
		}
		getchar();
	}
	vis[now] = 1;
	step[now] = 0;
	q.push(now);
	while (!q.empty()) {
		for (int i = 0; i < q.size(); ++i) {
			int tmp = q.front();
			q.pop();
			for (int j = 0; j < 16; ++j) {
				int alr = step[tmp];
				if (alr >> j & 0x01)
					continue;
				int nex = tmp ^ mask[j];
				if (vis[nex])
					continue;
				step[nex] = alr | (1 << j);
				if (nex == 0) {
					print(step[nex]);
					return 0;
				}
				q.push(nex);
				vis[nex] = 1;
			}
		}
	}

	return 0;
}