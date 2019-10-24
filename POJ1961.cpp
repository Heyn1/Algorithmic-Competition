#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int maxn = 1000005;

int na[maxn], n;
char str[maxn];

void calc_next() {
	na[1] = 0;
	for (int i = 2, j = 0; i <= n; ++i) {
		while (j > 0 && str[i] != str[j + 1])
			j = na[j];
		if (str[i] == str[j + 1])
			j++;
		na[i] = j;
	}
}

int main() {
	int t = 1;
	while (~scanf("%d", &n) && n) {
		scanf("%s", str + 1);
		calc_next();
		printf("Test case #%d\n", t++);
		for (int i = 2; i <= n; ++i) {
			if (i % (i - na[i]) == 0 && i / (i - na[i]) > 1)
				printf("%d %d\n", i, i / (i - na[i]));
		}
		printf("\n");
	}

	return 0;
}