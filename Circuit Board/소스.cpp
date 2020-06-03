#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int board[300][300];
pair<int,int> min_and_max[300][300];
int rightAbleN[300][300];
int minY[300][300];
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		int yn, xn, interval;
		scanf("%d %d %d", &yn, &xn, &interval);
		
		for (int i = 0; i < yn; i++)
			for (int j = 0; j < xn; j++)
				scanf("%d", &board[i][j]);

		for (int y = 0; y < yn; y++) {
			for (int term = 0; term < xn; term++) {
				for (int s = 0; s + term < xn; s++) {
					if (term == 0) {
						min_and_max[s][s] = { board[y][s], board[y][s] };
						rightAbleN[y][s] = 1;
					}
					else {
						min_and_max[s][s + term].first = min(min_and_max[s][s + term - 1].first, board[y][s + term]);
						min_and_max[s][s + term].second = max(min_and_max[s][s + term - 1].second, board[y][s + term]);

						if (min_and_max[s][s + term].second - min_and_max[s][s + term].first <= interval)
							rightAbleN[y][s] = term+1;
					}
				}
			}
		}

		int ans = 0;
		for (int x = 0; x < xn; x++) {
			for (int term = 0; term < yn; term++) {
				for (int s = 0; s+term < yn; s++) {
					if (term == 0) {
						minY[s][s] = rightAbleN[s][x];
					}
					else {
						minY[s][s + term] = min(minY[s][s + term - 1], rightAbleN[s + term][x]);
					}

					ans = max(ans, minY[s][s + term] * (term + 1));
				}
			}
		}

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}