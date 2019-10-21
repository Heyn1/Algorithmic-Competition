#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1000005;
char s[maxn];
unsigned long long f[maxn], p[maxn];

int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	p[0] = 1;
	for (int i = 1; i <= len; ++i) {
		f[i] = f[i - 1] * 131 + (s[i] - 'a' + 1);
		p[i] = p[i - 1] * 131;
	}
	int m, l1, r1, l2, r2;
	scanf("%d", &m);
	bool ans = false;
	for (int i = 0; i < m; ++i) {
		ans = false;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (f[r1] - f[l1 - 1] * p[r1 - l1 + 1] == f[r2] - f[l2 - 1] * p[r2 - l2 + 1])
			ans = true;
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}