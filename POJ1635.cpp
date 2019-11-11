#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 3005;
int t;
string str1, str2;

string calc(string str) {
	vector<string> son;
	int cnt = 0, st = 0, len = (int)str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == '0')
			cnt++;
		else
			cnt--;
		if (cnt == 0) {
			if (i - st > 2)
				son.push_back("0" + calc(str.substr(st + 1, i - st - 1)) + "1");
			else
				son.push_back("01");
			st = i + 1;
		}
	}
	sort(son.begin(), son.end());
	string res;
	for (int i = 0; i < (int)son.size(); i++)
		res += son[i];
	return res;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> str1 >> str2;
		if (calc(str1) == calc(str2))
			printf("same\n");
		else
			printf("different\n");
	}

	return 0;
}