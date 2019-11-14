#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a[100005], b[100005];

int main() {
    int n, f;
    scanf("%d%d", &n, &f);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", &a[i]);
    double eps = 0.000001, l = -1e6, r = 1e6;

    while (r - l > eps) {
        double sum[100005];
        double mid = (r + l) / 2.0;
        for (int i = 1; i <= n; ++i)
            b[i] = a[i] - mid;
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + b[i];
        double ans = -1e10, minval = 71e10;
        for (int i = f; i <= n; ++i) {
            minval = min(minval, sum[i - f]);
            ans = max(ans, sum[i] - minval);
        }
        if (ans >= 0)
            l = mid;
        else
            r = mid;
    }

    printf("%d\n", (int)(r * 1000));

    return 0;
}
