#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, r;
int prefix[5005][5005];

int main() {
    printf("Please input n and r: ");
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        prefix[x + 1][y + 1] = v;
    }
    for (int i = 1; i <= 5004; ++i) {
        for (int j = 1; j <= 5004; ++j) {
            prefix[i][j] = prefix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = min(r, 5003) + 1; i <= 5004; ++i) {
        for (int j = min(r, 5003) + 1; j <= 5004; ++j) {
            int nx = max(0, i - r - 1), ny = max(0, j - r - 1);
            ans = max(ans, prefix[i - 1][j - 1] - prefix[i - 1][ny] - prefix[nx][j - 1] + prefix[nx][ny]);
        }
    }
    printf("The answer: %d\n", ans);

    return 0;
}
