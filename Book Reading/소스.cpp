#include<iostream>
#include<cstdio>
using namespace std;
long long xbookCnt[100001];
void divide(int num) {
	for (int j = 1; j * j <= num; j++) {
		if (num % j == 0) {
			xbookCnt[j]++;

			if (j != num / j) {
				xbookCnt[num / j]++;
			}
		}
	}
}
int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		long long ans = 0;
		long long l;
		int xbookn, peoplen;
		scanf("%lld %d %d", &l, &xbookn, &peoplen);

		for (int i = 0; i < xbookn; i++) {
			int tmp;
			scanf("%d", &tmp);
			divide(tmp);
		}

		for (int i = 0; i < peoplen; i++) {
			long long tmp;
			scanf("%lld", &tmp);

			ans += l / tmp - xbookCnt[tmp];
		}

		printf("Case #%d: %lld\n", t, ans);

		for (int i = 1; i <= l; i++) {
			xbookCnt[i] = 0;
		}
	}
	return 0;
}