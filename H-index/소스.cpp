#include<cstdio>
#include<iostream>
using namespace std;
int seg[400000];
void insertSeg(int s, int e, int value, int index) {
	if (value < s || e < value) {
		return;
	}

	seg[index]++;

	if (s == e) {
		return;
	}

	int mid = (s + e) / 2;
	insertSeg(s, mid, value, index * 2+1);
	insertSeg(mid + 1, e, value, index * 2 + 2);
}
int getSeg(int s, int e, int value, int index) {
	if (e < value) {
		return 0;
	}
	if (value <= s) {
		return seg[index];
	}

	int mid = (s + e) / 2;
	int ret;

	ret = getSeg(s, mid, value, index * 2 + 1);
	ret += getSeg(mid + 1, e, value, index * 2 + 2);

	return ret;
}
int solve(int n) {
	int ans;
	int s = 1;
	int e = n;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (getSeg(1, 100000, mid, 0) >= mid) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	return ans;
}
int main() {
	int tc;
	scanf("%d", &tc);

	for (int t=1; t <= tc; t++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", t);

		for (int i = 1; i <= n; i++) {
			int value;
			scanf("%d", &value);

			insertSeg(1, 100000, value, 0);

			printf("%d ", solve(i));
		}
		printf("\n");

		for (int i = 0; i <= 400000; i++) {
			seg[i] = 0;
		}
	}

	return 0;
}