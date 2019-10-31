#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct node {
	long long v, c;
	bool operator < (struct node a) const {
		if (v == a.v)
			return c < a.c;
		return v < a.v;
	}
	bool operator > (struct node a) const {
		if (v == a.v)
			return c > a.c;
		return v > a.v;
	}	
};
long long n, k, tmp;

int main() {
	scanf("%lld%lld", &n, &k);
	priority_queue<node, vector<node>, greater<node> > pq;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tmp);
		struct node tn;
		tn.v = tmp;
		tn.c = 0;
		pq.push(tn);
	}
	if ((n - 1) % (k - 1)) {
		while (1) {
			struct node tn;
			tn.v = 0;
			tn.c = 0;
			pq.push(tn);
			n++;
			if ((n - 1) % (k - 1) == 0)
				break;
		}
	}
	long long ans = 0;
	for (int i = 0; i < (n - 1) / (k - 1); i++) {
		long long sum = 0, child = 0;
		for (int j = 0; j < k; j++) {
			sum += pq.top().v;
			child = max(child, pq.top().c);
			pq.pop();
		}
		ans += sum;
		struct node tn;
		tn.v = sum;
		tn.c = child + 1;
		pq.push(tn);
	}
	printf("%lld\n%lld\n", ans, pq.top().c);

	return 0;
}