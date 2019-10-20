#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[2][100000];
int dp[3][100000];
int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];

		for (int i = 1; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[2][i-1]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[2][i-1]) + arr[1][i];
			dp[2][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
		}

		printf("%d\n", max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n-1])));
	}

	return 0;
}