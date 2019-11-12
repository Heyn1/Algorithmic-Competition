#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1000005;
char necklace[2 * maxn], cmp[2 * maxn];

int main() {
	scanf("%s", necklace + 1);
	getchar();
	scanf("%s", cmp + 1);
	getchar();
	int len1 = strlen(necklace + 1), len2 = strlen(cmp + 1);
	if (len1 != len2) {
		printf("No\n");
		return 0;
	}
	for (int i = 1; i <= len1; i++) {
		necklace[len1 + i] = necklace[i];
		cmp[len2 + i] = cmp[i];
	}
	int i = 1, j = 2, k, start1, start2;
	while (i <= len1 && j <= len1) {
		for (k = 0; k < len1 && necklace[i + k] == necklace[j + k]; k++);
		if (k == len1)
			break;
		if (necklace[i + k] > necklace[j + k]) {
			i = i + k + 1;
			if (i == j)
				i++;
		}
		else {
			j = j + k + 1;
			if (i == j)
				j++;
		}
	}
	start1 = min(i, j);
	i = 1;
	j = 2;
	while (i <= len2 && j <= len2) {
		for (k = 0; k < len2 && cmp[i + k] == cmp[j + k]; k++);
		if (cmp[i + k] > cmp[j + k]) {
			i = i + k + 1;
			if (i == j)
				i++;
		}
		else {
			j = j + k + 1;
			if (i == j)
				j++;
		}
	}
	start2 = min(i, j);
	bool flg = true;
	for (int i = 0; i < len1; i++) {
		if (necklace[start1 + i] != cmp[start2 + i]) {
			flg = false;
			break;
		}
	}
	if (flg) {
		printf("Yes\n");
		for (int i = 0; i < len1; i++) {
			printf("%c", necklace[start1 + i]);
		}
		printf("\n");
	}
	else {
		printf("No\n");
	}
	
	return 0;
}