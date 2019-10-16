#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int maxn = 1005;

int t;

inline int stoi(char *s) {
	int res = 0;
	for (int i = 8; s[i] != '\0'; ++i) {
		res *= 10;
		res += (s[i] - '0');
	}
	return res;
}

int main() {
	int k = 1, sum, tmp;
	while (~scanf("%d", &t) && t) {
		queue<int> q[maxn];
		map<int, int> m;
		for (int i = 1; i <= t; ++i) {
			scanf("%d", &sum);
			for (int j = 0; j < sum; ++j) {
				scanf("%d", &tmp);
				m[tmp] = i;
			}
		}
		char op[100];
		printf("Scenario #%d\n", k++);
		while (~scanf("%s", op) && op[0] != 'S') {
			if (op[0] == 'E') {
				scanf("%d", &tmp);
//				cout << "hey: " << tmp << endl;
				if (q[m[tmp]].empty()) {
					q[0].push(m[tmp]);
				}
				q[m[tmp]].push(tmp);
			}
			else {
				tmp = q[q[0].front()].front();
				printf("%d\n", tmp);
				q[q[0].front()].pop();
				if (q[q[0].front()].empty()) {
					q[0].pop();
				}
			}
		}
		printf("\n");
	}
}