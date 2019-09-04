#include <iostream>
using namespace std;
int book[10005], n, m, l = 0, r = 0;

bool valid(int s) {
    int group = 1, rest = s;
    for (int i = 0; i < n; ++i) {
        if (book[i] < rest)
            rest -= book[i];
        else {
            ++group;
            rest = s - book[i];
        }
    }

    return group <= m;
}

int main() {
    printf("Please input n and m: ");
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &book[i]);
        r += book[i];
    }
    while (l < r) {
        int mid = (l + r) >> 1;
        if (valid(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("The answer: %d\n", l);

    return 0;
}
