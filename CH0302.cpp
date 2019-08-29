#include <iostream>
#include <vector>

using namespace std;

unsigned int n, m, sum = 0;
vector<int> nums;

void calc(unsigned int x) {
	if (nums.size() > m || nums.size() + (n - x + 1) < m)
		return;
	if (x == n + 1) {
		cout << "The No." << sum++ <<" Permutation: " << endl;
		for (int n : nums)
			cout << n << " ";
		cout << endl;
		return;
	}

	calc(x + 1);
	nums.push_back(x);
	calc(x + 1);
	nums.pop_back();
}

int main() {
	cin >> n >> m;

	calc(1);

	return 0;
}