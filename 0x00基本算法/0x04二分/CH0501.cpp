#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int store[100005];
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &store[i]);
    sort(store + 1, store + n + 1);
    int mid = (n & 1 ? (n + 1) / 2 : n / 2);
    for (int i = 1; i <= n; ++i)
        ans += abs(store[i] - store[mid]);
    printf("%d\n", ans);

    return 0;
}
