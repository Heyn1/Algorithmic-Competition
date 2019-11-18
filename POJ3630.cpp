#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 10005;
int trie[maxn * 10][15], tot = 1, t, n;
bool triend[maxn * 10];
char str[15];

bool insert() {
	int len = strlen(str), p = 1;
	bool res = true;
	for (int i = 0; i < len; ++i) {
		int ch = str[i] - '0';
		if (i == len - 1 && trie[p][ch])
			res = false;
		if (trie[p][ch] == 0)
			trie[p][ch] = ++tot;
		p = trie[p][ch];
		if (triend[p])
			res = false;
	}
	triend[p] = true;

	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(trie, 0, sizeof trie);
		memset(triend, 0, sizeof triend);
		tot = 1;
		scanf("%d", &n);
		bool flg = true;
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			if (insert())
				continue;
			else
				flg = false;
		}
		if (flg)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}