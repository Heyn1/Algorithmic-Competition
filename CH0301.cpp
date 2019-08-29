#include <iostream>
#include <vector>

using namespace std;

int n, sum = 0;
vector<int> nums;

void calc(int i) {
    if (i == n + 1) {
        cout << "The No." << sum++ << " Permutation: " << endl;
        for (int n : nums)
            cout << n << " ";
        cout << endl;
        return;
    }

    calc(i + 1);
    nums.push_back(i);
    calc(i + 1);
    nums.pop_back();
}

int main() {
    cin >> n;

    calc(1);

    return 0;
}
