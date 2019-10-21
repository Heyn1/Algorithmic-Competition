#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 100005;
int n, tot = 0, p = 99991, snow[maxn][6], h[maxn], nextSnow[maxn];

int func(int *a) {
	int sum = 0, mul = 1;
	for (int i = 0; i < 6; ++i) {
		sum = (sum + a[i]) % p;
		mul = ((long long)mul * a[i]) % p;
	}
	return (sum + mul) % p;
}

bool judge(int *a, int *b) {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			bool eq = true;
			for (int k = 0; k < 6; ++k) {
				if (a[(i + k) % 6] != b[(j + k) % 6]) {
					eq = false;
					break;
				}
			}
			if (eq)
				return true;
			eq = true;
			for (int k = 0; k < 6; ++k) {
				if (a[(i + k) % 6] != b[(j - k + 6) % 6]) {
					eq = false;
					break;
				}
			}
			if (eq)
				return true;
		}
	}
	return false;
}

bool insert(int *a) {
	int val = func(a);
	for (int i = h[val]; i; i = nextSnow[i]) {
		if (judge(snow[i], a))
			return true;
	}
	++tot;
	memcpy(snow[tot], a, sizeof(int) * 6);
	nextSnow[tot] = h[val];
	h[val] = tot;
	return false;
}

int main() {
	scanf("%d", &n);
	int a[10];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 6; ++j)
			scanf("%d", &(a[j]));
		if (insert(a)) {
			printf("Twin snowflakes found.\n");
			return 0;
		}
	}
	printf("No two snowflakes are alike.\n");
	return 0;
}