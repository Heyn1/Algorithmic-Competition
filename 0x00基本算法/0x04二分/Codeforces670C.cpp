#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int tmp[600005], lang[600005], per[200005], aud[200005], sub[200005], peo[200005];
int n, m;

int main() {
    int k = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &per[i]);
        tmp[k++] = per[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &aud[i]);
        tmp[k++] = aud[i];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &sub[i]);
        tmp[k++] = sub[i];
    }
    sort(tmp, tmp + k);
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        if (i == 0 || tmp[i] != tmp[i - 1]) {
            lang[sum++] = tmp[i];
        }
    }
//    for (int i = 0; i < sum; ++i) {
//        printf("%d ", lang[i]);
//    }
//    printf("\n");
    for (int i = 0; i < n; ++i) {
        ++peo[lower_bound(lang, lang + sum, per[i]) - lang];
    }
//    for (int i = 0; i < sum; ++i) {
//        printf("%d ", peo[i]);
//    }
    int ans = 0, maxa = 0, maxs = 0;
    for (int i = 0; i < m; ++i) {
        int indexa = lower_bound(lang, lang + sum, aud[i]) - lang;
        int indexs = lower_bound(lang, lang + sum, sub[i]) - lang;
//        printf("i: %d\n", i);
//        printf("indexa: %d\n", indexa);
//        printf("indexs: %d\n", indexs);
        if (peo[indexa] > maxa) {
            ans = i;
            maxa = peo[indexa];
            maxs = peo[indexs];
        }
        else if (peo[indexa] == maxa && peo[indexs] > maxs) {
            ans = i;
            maxs = peo[indexs];
        }
    }
    printf("%d\n", ans + 1);

    return 0;
}
