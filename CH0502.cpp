#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int m, n, t;
int row[100005], col[100005], prer[100005], prec[100005];

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < t; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++row[x];
        ++col[y];
    }
    if (t % n == 0 && t % m == 0) {
        for (int i = 1; i <= n; ++i) {
            prer[i] = (prer[i - 1] + row[i] - (t / n));
        }
        for (int i = 1; i <= m; ++i) {
            prec[i] = (prec[i - 1] + col[i] - (t / m));
        }
        sort(prer + 1, prer + n + 1);
        sort(prec + 1, prec + m + 1);
        int midr = (n & 1 ? (n + 1) / 2 : n / 2), midc = (m & 1 ? (m + 1) / 2 : m / 2);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += abs(prer[i] - prer[midr]);
        for (int i = 1; i <= m; ++i)
            ans += abs(prec[i] - prec[midc]);
        printf("both %d\n", ans);
    }
    else if (t % n == 0) {
        for (int i = 1; i <= n; ++i) {
            prer[i] = (prer[i - 1] + row[i] - (t / n));
        }
        sort(prer + 1, prer + n + 1);
        int midr = (n & 1 ? (n + 1) / 2 : n / 2);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += abs(prer[i] - prer[midr]);
        printf("row %d\n", ans);
    }
    else if (t % m == 0){
        for (int i = 1; i <= m; ++i) {
            prec[i] = (prec[i - 1] + col[i] - (t / m));
        }
        sort(prec + 1, prec + m + 1);
        int midc = (m & 1 ? (m + 1) / 2 : m / 2);
        int ans = 0;
        for (int i = 1; i <= m; ++i)
            ans += abs(prec[i] - prec[midc]);
        printf("column %d\n", ans);
    }
    else {
        printf("impossible\n");
    }

    return 0;
}
