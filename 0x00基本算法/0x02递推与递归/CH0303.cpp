#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 15;

int n, ans = 0;
int order[MAXN];
int chosen[MAXN];
void calc(int k) {
	if (k == n + 1) {
		printf("The No.%d permutation: \n", ans++);
		for (int i = 1; i <= n; ++i)
			printf("%d ", order[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= n; ++i) {
			if (chosen[i])
				continue;
			order[k] = i;
			chosen[i] = 1;
			calc(k + 1);
			chosen[i] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	printf("Please input n: ");
	scanf("%d", &n);

	calc(1);

	return 0;
}
