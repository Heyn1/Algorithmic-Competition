#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int arr[105][105];
int sum[105][105];

int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &arr[i][j]);
            tmp += arr[i][j];
            ans = max(ans, tmp);
            if (tmp < 0)
                tmp = 0;
        }
    }
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int tmp = 0;
            for (int k = 1; k <= n; ++k) {
                arr[i][k] += arr[j][k];
                tmp += arr[i][k];
                ans = max(ans, tmp);
                if (tmp < 0)
                    tmp = 0;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
