#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 1000005;
char str[maxn * 2];
int p[maxn * 2];

int init() {
    int len = strlen(str);
    for (int i = len; i >= 0; --i) {
        str[i + i + 2] = str[i];
        str[i + i + 1] = '#';
    }
    str[0] = '#';
    return len * 2 + 1;
}

int main() {
    int test = 1;
    while (~scanf("%s", str) && str[0] != 'E') {
        int len = init();
        int r = -1, c = -1, ans = 0;
        for (int i = 0; i < len; ++i) {
            p[i] = (r > i ? min(r - i, p[2 * c - i]) : 1);
            while (str[i - p[i]] == str[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                r = i + p[i];
                c = i;
            }
            ans = max(ans, p[i]);
        }
        printf("Case %d: %d\n", test++, ans - 1);
    }

    return 0;
}