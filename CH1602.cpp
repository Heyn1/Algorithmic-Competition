#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
const long long maxn = 100005 * 32;

int trie[maxn][2], n, num, tot = 1, ans = -1;

void insert() {
	int p = 1;
	for (int i = 31; i >= 0; --i) {
		int k = (num >> i) & 1;
		if (trie[p][k] == 0)
			trie[p][k] = ++tot;
		p = trie[p][k];
	}
}
int search() {
	int p = 1, res = 0;
//	cout << "num: " << num << endl;
	for (int i = 31; i >= 0; --i) {
		int k = (num >> i) & 1;
//		cout << "k: " << k << endl;
		if (trie[p][!k]) {
			p = trie[p][!k];
			res += (1 << i);
		}
		else if (trie[p][k]) {
			p = trie[p][k];
		}
		else
			return -1;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		insert();
		ans = max(ans, search());
	}
	printf("%d\n", ans);

	return 0;
}