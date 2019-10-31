#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int n, tmp;

int main() {
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		pq.push(tmp);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	printf("%d\n", ans);

	return 0;
}