#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1000005;

int trie[maxn][26], tot = 1;
int strend[maxn];
char str[maxn];

void insert() {
	int len = strlen(str), p = 1;
	for (int i = 0; i < len; ++i) {
		int ch = str[i] - 'a';
		if (trie[p][ch] == 0)
			trie[p][ch] = ++tot;
		p = trie[p][ch];
	}
	strend[p]++;
}
int search() {
	int len = strlen(str), ans = 0, p = 1;
	for (int i = 0; i < len; ++i) {
		p = trie[p][str[i] - 'a'];
		if (p == 0)
			return ans;
		if (strend[p])
			ans += strend[p];
//		cout << str[i] - 'a' << " : " << strend[p] << endl;
	}

	return ans;
}

int main() {
	int n, m;
	memset(strend, 0, sizeof strend);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		insert();
	}
	for (int i = 0; i < m; ++i) {
		scanf("%s", str);
		printf("%d\n", search());
	}

	return 0;
}