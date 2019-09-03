#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int nums[100005];
int dif[100005];

int main() {
    printf("Please input n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        scanf("%d", &tmp);
        nums[i] = tmp;
        if (i)
            dif[i] = nums[i] - nums[i - 1];
        else
            dif[i] = nums[i];
    }
    int p = 0, q = 0;
    for (int i = 0; i < n; ++i) {
        if (dif[i] > 0)
            q += dif[i];
        else if (dif[i] < 0)
            p -= dif[i];
    }
    printf("The minimum operation: %d\n", max(p, q));
    printf("The numbers of different array: %d\n", abs(p - q) + 1);

    return 0;
}
