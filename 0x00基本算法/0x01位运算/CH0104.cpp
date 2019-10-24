#include <iostream>

using namespace std;

int n, m;
pair<string, int> a[100005];

int solve(int bit, int now) {
    for (int i = 1; i <= n; ++i) {
        int x = a[i].second >> bit & 1;
        if (a[i].first == "AND")
            now &= x;
        else if(a[i].first == "OR")
            now |= x;
        else
            now ^= x;
    }

    return now;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        string s;
        int x;
        cin >> s >> n;
        a[i] = make_pair(s, x);
    }

    int val = 0, res = 0;
    for (int bit = 29; bit >= 0; --bit) {
        int res0 = solve(bit, 0);
        int res1 = solve(bit, 1);
        if (val + (1 << bit) <= m && res0 < res1) {
            val += 1 << bit;
            res += res1 << bit;
        }
        else {
            res += res0 << bit;
        }
    }
    cout << res << endl;

    return 0;
}
