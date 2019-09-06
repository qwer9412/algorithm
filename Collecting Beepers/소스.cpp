#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int abs(int num) {
	return num > 0 ? num : -num;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int xlen, ylen;
		int sx, sy;
		int n;
		vector<pair<int, int>> v;
		vector<int> idx;
		int ans = INT_MAX;

		scanf("%d %d", &xlen, &ylen);
		scanf("%d %d", &sx, &sy);
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			int tmpx, tmpy;
			scanf("%d %d", &tmpx, &tmpy);
			v.push_back({ tmpx,tmpy });

			idx.push_back(i);
		}

		do {
			int len = abs(v[idx[0]].first - sx) + abs(v[idx[0]].second - sy);

			for (int i = 1; i < n; i++) {
				len += abs(v[idx[i]].first - v[idx[i - 1]].first) + abs(v[idx[i]].second - v[idx[i - 1]].second);
			}

			len += abs(v[idx[n - 1]].first - sx) + abs(v[idx[n - 1]].second - sy);

			ans = min(ans, len);
		} while (next_permutation(idx.begin(), idx.end()));

		printf("The shortest path has length %d\n", ans);
	}
	return 0;
}