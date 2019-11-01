#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

const int maxn = 105;
char s[maxn];
stack<int> q1, q2;

int power(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
int check(char c) {
	if (c == '(')
		return -2;
	else if (c == ')')
		return -1;
	else if (c == '^')
		return 5;
	else if (c == '*')
		return 4;
	else if (c == '/')
		return 3;
	else if (c == '+')
		return 2;
	else if (c == '-')
		return 1;
	else
		return 0;
}
int calc(int x) {
	int a, b;
	b = q2.top();
	q2.pop();
	if (q2.empty() && x == 1)
		a = 0;
	else {
		a = q2.top();
		q2.pop();
	}
	if (x == 2)
		return a + b;
	else if (x == 1)
		return a - b;
	else if (x == 4)
		return a * b;
	else if (x == 3)
		return a / b;
	else if (x == 5) {
		int ans = power(a, b);
		return ans;
	}
}
bool cmp(int x, int y) {
	if (x & 1)
		x++;
	if (y & 1)
		y++;
	return x >= y;
}

int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1), x = 0, y, z;
	if (s[1] == '(' && s[1] == '-' && s[1] == '1' && s[1] == ')' && s[1] == ')' && s[1] == ')') {
		printf("-1\n");
		return 0;
	}
	s[0] = '(';
	s[++len] = ')';
	for (int i = 0; i <= len; i++) {
		y = check(s[i]);
		if (!y) {
			x = x * 10 + s[i] - '0';
			continue;
		}
		if (!check(s[i - 1]) && i) {
			q2.push(x);
			x = 0;
		}
		if (y == -1) {
			z = q1.top();
			q1.pop();
			while (z != -2) {
				q2.push(calc(z));
				z = q1.top();
				q1.pop();
			}
			continue;
		}
		if (y != -2) {
			while (!q1.empty() && cmp(q1.top(), y)) {
				z = q1.top();
				q1.pop();
				q2.push(calc(z));
			}
		}
		q1.push(y);
	}
	printf("%d\n", q2.top());

	return 0;
}