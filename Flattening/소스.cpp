#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int arr[101];
int idx[101];
vector<int> tmpArr;
//dp[같지 않은 수][범위][변경할 값]
int dp[101][101][100];
int main() {
	int tc;
	scanf("%d", &tc);
	
	for (int t = 1; t <= tc; t++) {
		int n, limit;
		scanf("%d %d", &n, &limit);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			tmpArr.push_back(arr[i]);
		}

		sort(tmpArr.begin(), tmpArr.end());
		tmpArr.erase(unique(tmpArr.begin(), tmpArr.end()), tmpArr.end());

		int kind = tmpArr.size();

		for (int i = 1; i <= n; i++) {
			idx[i] = lower_bound(tmpArr.begin(), tmpArr.end(), arr[i]) - tmpArr.begin();
		}

		for (int i = 0; i <= limit; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < kind; k++) {
					dp[i][j][k] = 99999;
				}
			}
		}

		//dp[0][][] 체우기
		for (int j = 1; j <= n; j++) {
			for (int k1 = 0; k1 < kind; k1++) {
				dp[0][j][k1] = dp[0][j - 1][k1] + (idx[j] == k1 ? 0 : 1);
 			}
		}

		for (int i = 1; i <= limit; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k1 = 0; k1 < kind; k1++) {
					for (int k2 = 0; k2 < kind; k2++) {
						int plus = (idx[j] == k1 ? 0 : 1);
				
						if (k1 == k2) {
							dp[i][j][k1] = min(dp[i][j][k1], dp[i][j - 1][k2] + plus);
						}
						else {
							dp[i][j][k1] = min(dp[i][j][k1], dp[i - 1][j - 1][k2] + plus);
						}
					}
				}
			}
		}

		int ans = n;
		for (int k = 0; k < kind; k++) {
			ans = min(ans, dp[limit][n][k]);
		}

		printf("Case #%d: %d\n", t, ans);

		tmpArr.clear();
	}

	return 0;
}