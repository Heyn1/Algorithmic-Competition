#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

struct node {
	int val;
	int idx;
	node (int a, int b): val(a), idx(b) {}
	friend bool operator< (const node &a, const node &b) {
		return a.val < b.val;
	}
};
int n;
set<node> s;

int main() {
	scanf("%d", &n);
	int val, ans = INT_MAX, idx = INT_MAX;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &val);
		node *curNode = new node(val, i);
		s.insert(*curNode);
		if (i > 0) {
			set<node>::iterator it = s.find(*curNode), pre = --it, next;
			it = s.find(*curNode);
			next = ++it;
			if (pre->val == curNode->val && pre->idx == curNode->idx) {
				ans = abs(next->val - val);
				idx = min(next->idx, i) + 1;
			}
			else if (next == s.end()){
				ans = abs(pre->val - val);
				idx = min(pre->idx, i) + 1;
			}
			else {
			    if (abs(next->val - val) < abs(pre->val - val)) {
			        ans = abs(next->val - val);
			        idx = min(next->idx, i) + 1;
			    }
			    else if (abs(pre->val - val) < abs(next->val - val)) {
			        ans = abs(pre->val - val);
			        idx = min(pre->idx, i) + 1;
			    }
			    else {
			        ans = abs(next->val - val);
			        if (pre->val < next->val)
			        	idx = pre->idx + 1;
			        else
			        	idx = next->idx + 1;
			    }
			}
			printf("%d %d\n", ans, idx);
		}
	}

	return 0;
}