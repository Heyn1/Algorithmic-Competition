#include <vector>
#include <iostream>
using namespace std;

vector<int> chosen;
int s[100010], top = 0, address = 0, n, m;
void call(int x, int ret_addr) {
    int old_top = top;
    s[++top] = x;
    s[++top] = ret_addr;
    s[++top] = old_top;
}
int ret() {
    int ret_addr = s[top - 1];
    top = s[top];
    return ret_addr;
}
int main() {
    cin >> n >> m;
    call(1, 0);
    while (top) {
        int x = s[top - 2];
        switch (address) {
        case 0:
            if (chosen.size() > m || chosen.size() + (n - x + 1) < m) {
                address = ret();
                continue;
            }
            if (x == n + 1) {
                for (int i = 0; i < chosen.size(); ++i) {
                    cout << chosen[i] << " ";
                }
                cout << endl;
                address = ret();
                continue;
            }
            call(x + 1, 1);
            address = 0;
            continue;
        case 1:
            chosen.push_back(x);
            call(x + 1, 2);
            address = 0;
            continue;
        case 2:
            chosen.pop_back();
            address = ret();
        }
    }
}
