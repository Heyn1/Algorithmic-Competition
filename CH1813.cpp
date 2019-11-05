#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1105;
int aa[maxn], ba[maxn], na[maxn], n, cnt = 0;
char ans[maxn << 1];
bool flg = true;

bool check(int x, int bi) {
	if (!bi)
		return true;
	int i;
	for (i = x + 1; i <= n; i++) {
		if (na[i] > na[x] && na[i] > ba[bi])
			break;
	}
	for (int j = i + 1; j <= n; j++) {
		if (na[j] < na[x])
			return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &(na[i]));
	aa[0] = INF;
	ba[0] = INF;
	int ai = 0, bi = 0, ni = 1, num = 1;
	cnt = 0;
	flg = true;
	for (int i = 1; i <= n << 1; i++) {
		if (aa[ai] == num) {
			ai--;
			num++;
			ans[++cnt] = 'b';
		}
		else if (ba[bi] == num) {
			bi--;
			num++;
			ans[++cnt] = 'd';
		}
		else if (ni <= n && na[ni] < aa[ai] && check(ni, bi)) {
			aa[++ai] = na[ni++];
			ans[++cnt] = 'a';
		}
		else if (ni <= n && na[ni] < ba[bi]) {
			ba[++bi] = na[ni++];
			ans[++cnt] = 'c';
		}
		else {
			flg = false;
			break;
		}
	}
	if (!flg)
		printf("0\n");
	else {
		for (int i = 1; i <= cnt; i++)
			printf("%c ", ans[i]);
		printf("\n");
	}

	return 0;
}