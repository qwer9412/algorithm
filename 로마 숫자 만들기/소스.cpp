#include<iostream>
using namespace std;
bool dp[21][1001];
int v[4] = { 1,5,10,50 };
int main() {
	int n;

	cin >> n;

	dp[0][0] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 1000; j >= 0; j--) {
			for (int k = 0; k < 4; k++) {
				if (j + v[k] <= 1000 && dp[i - 1][j] == true) {
					dp[i][j + v[k]] = true;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i <= 1000; i++) {
		if (dp[n][i] == true) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}