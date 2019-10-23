#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 300005;
int sa[maxn], height[maxn], n;
char s[maxn];
unsigned long long H[maxn], p[maxn];

unsigned long long getH(int i, int j) {
	return H[j] - H[i - 1] * p[j - i + 1];
}
int lcp(int x, int y)
{
    int l = 0, r = min(n - x + 1, n - y + 1);
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(getH(x, x + mid - 1) == getH(y, y + mid - 1)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    return l;
}
bool cmp(int x, int y) {
	int l = lcp(x, y);
	return s[x + l] < s[y + l];
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	p[0] = 1;
	for (int i = 1; i <= n; ++i) {
		sa[i] = i;
		H[i] = H[i - 1] * 131 + s[i] - 'a' + 1;
		p[i] = p[i - 1] * 131; 
	}
	sort(sa + 1, sa + n + 1, cmp);
	for (int i = 2; i <= n; ++i) {
		height[i] = lcp(sa[i - 1], sa[i]);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", sa[i] - 1);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", height[i]);
	}
	printf("\n");

	return 0;
}