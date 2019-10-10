#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>
#include <climits>
using namespace std;

bool f;
int n, sum[1000005], maxn[1000005], num, p = 1;
stack<int> a, b;

int main() {
	maxn[0] = INT_MIN;
	cin >> n;
	getchar();
	for (int i = 0; i < n; ++i) {
		char q[10];
		cin.getline(q, 10);
		switch (q[0]) {
			case 'I':
				num = 0;
				f = true;
				for (int j = 2; j < strlen(q); ++j) {
					if (q[j] == '-') {
						f = false;
						continue;
					}
					num *= 10;
					num += (q[j] - '0');
				}
				if(!f)
					num = -num;
				a.push(num);
				sum[p] = sum[p - 1] + num;
				maxn[p] = max(maxn[p - 1], sum[p]);
				p++;
				break;
			case 'D':
				if (!a.empty()) {
					a.pop();
					p--;
				}
				break;
			case 'L':
				if (!a.empty()) {
					b.push(a.top());
					a.pop();
					p--;
				}
				break;
			case 'R':
				if (!b.empty()) {
					a.push(b.top());
					sum[p] = sum[p - 1] + b.top();
					maxn[p] = max(maxn[p - 1], sum[p]);
					b.pop();
					p++;
				}
				break;
			case 'Q':
				num = 0;
				f = true;
				for (int j = 2; j < strlen(q); ++j) {
					if (q[j] == '-') {
						f = false;
						continue;
					}
					num *= 10;
					num += (q[j] - '0');
				}
				if (!f)
					num = -num;
				printf("%d\n", maxn[num]);
				break;
		}
	}

	return 0;
}