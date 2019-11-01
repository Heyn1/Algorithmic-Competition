#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 100005;

char str[maxn];
int dp[maxn];

bool judge(int i, int j) {
	if (str[i] == '(' && str[j] == ')')
		return true;
	if (str[i] == '[' && str[j] == ']')
		return true;
	if (str[i] == '{' && str[j] == '}')
		return true;
	return false;
}

int main() {
	scanf("%s", str + 1);
	stack<int> s;
	int ans = 0, len = strlen(str + 1);
	for (int i = 1; i <= len; i++) {
		if (!s.empty() && judge(s.top(), i)) {
			dp[i] = dp[i - 1] + 2;
			if (i - dp[i] >= 1)
				dp[i] += dp[i - dp[i]];
			s.pop();
		}
		else
			s.push(i);
	}
	for (int i = 1; i <= len; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);

	return 0;
}