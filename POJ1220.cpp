#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1005;

int t, in, out;
int num[maxn], ans[maxn];
char str[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &in, &out, str);
		int len = strlen(str);
		for (int i = 0, j = len - 1; i < len; ++i, --j) {
			if (str[j] >= '0' && str[j] <= '9')
				num[i] = str[j] - '0';
			else if (str[j] >= 'A' && str[j] <= 'Z')
				num[i] = str[j] - 'A' + 10;
			else
				num[i] = str[j] - 'a' + 36;
		}
		int k;
		for (k = 0; len; ) {
			for (int i = len - 1; i > 0; --i) {
				num[i - 1] += (num[i] % out) * in;
				num[i] = num[i] / out;
			}
			ans[++k] = num[0] % out;
			num[0] /= out;
			while (len > 0 && !num[len - 1])
				--len;
		}
		printf("%d %s\n", in, str);
		printf("%d ", out);
		for (int i = k; i >= 1; --i) {
			if (ans[i] < 10)
				printf("%d", ans[i]);
			else if (ans[i] >= 10 && ans[i] < 36)
				printf("%c", 'A' + ans[i] - 10);
			else
				printf("%c", 'a' + ans[i] - 36);
		}
		printf("\n\n");
	}

	return 0;
}