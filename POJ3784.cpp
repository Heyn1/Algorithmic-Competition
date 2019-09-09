#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int p, id, m, sum = 0;
int main() {
	scanf("%d", &p);
	while (p--) {
		scanf("%d%d", &id, &m);
		printf("%d %d\n", id, (m + 1) / 2);
		long long mid, tmp;
		priority_queue<int> q1;
		priority_queue<int, vector<int>, greater<int> > q2;
		
		for (int i = 1; i <= m; ++i) {
			scanf("%lld", &tmp);
			if (i == 1) {
				sum = 1;
				mid = tmp;
				printf("%lld ", mid);
				continue;
			}
			if (tmp < mid)
				q1.push(tmp);
			else
				q2.push(tmp);
			if (q1.size() - q2.size() == 2) {
				q2.push(mid);
				mid = q1.top();
				q1.pop();
			}
			else if (q2.size() - q1.size() == 2) {
				q1.push(mid);
				mid = q2.top();
				q2.pop();
			}
			if (i & 1) {
				++sum;
				if (sum % 10 == 0)
					printf("%lld\n", mid);
				else
					printf("%lld ", mid);
			}
		}
		if (sum % 10)
			printf("\n");
	}

	return 0;
}