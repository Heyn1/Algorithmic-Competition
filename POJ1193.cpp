#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#define PII pair<int, int>
using namespace std;

int n, t, m, p, ans, cnt;
queue<PII> waits;
set<PII> runs;
priority_queue<PII, vector<PII>, greater<PII> > endts;

bool findMem(int x, int y, int z) {
	for (set<PII>::iterator it = runs.begin(); it != runs.end(); it++) {
		set<PII>::iterator nxt = it;
		nxt++;
		if (nxt != runs.end()) {
			int start = it->first + it->second;
			if (y <= nxt->first - start) {
				runs.insert({start, y});
				endts.push({x + z, start});
				return true;
			}
		}
	}
	return false;
}
void update(int x) {
	while (endts.size() && endts.top().first <= x) {
		int f = endts.top().first;
		while (endts.size() && endts.top().first == f) {
			PII top = endts.top();
			endts.pop();
			set<PII>::iterator it = runs.lower_bound({top.second, 0});
			runs.erase(it);
		}
		ans = f;
		while (waits.size()) {
			PII front = waits.front();
			if (findMem(f, front.first, front.second))
				waits.pop();
			else
				break;
		}
	}
}

int main() {
	scanf("%d", &n);
	runs.insert({-1, 1});
	runs.insert({n, 1});
	while (~scanf("%d%d%d", &t, &m, &p) && (t || m || p)) {
		update(t);
		if (!findMem(t, m, p)) {
			waits.push({m, p});
			cnt++;
		}
	}
	update(2e9);
	printf("%d\n%d\n", ans, cnt);

	return 0;
}