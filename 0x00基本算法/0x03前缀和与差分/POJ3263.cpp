#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int n, i, h, r;
map<pair<int, int>, bool> existed;
int c[10005], d[10005];

int main() {
    scanf("%d%d%d%d", &n, &i, &h, &r);
    for (int j = 1; j <= r; ++j) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        if (existed[make_pair(a, b)])
            continue;
        --d[a + 1];
        ++d[b];
        existed[make_pair(a, b)] = true;
    }
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + d[i];
        printf("%d\n", c[i] + h);
    }

    return 0;
}
