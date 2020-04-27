#include<iostream>
#include<cstdio>
using namespace std;
int group[100001];
int getGroup(int a)
{
	if (group[a] == a) {
		return a;
	}

	return group[a] = getGroup(group[a]);
}
int main()
{
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++)
	{
		int n, blackN;
		int cnt = 0;
		scanf("%d %d", &n, &blackN);
		
		for (int i = 1; i <= n; i++) {
			group[i] = i;
		}

		for (int i = 0; i < blackN; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			
			int groupA = getGroup(a);
			int groupB = getGroup(b);

			if (groupA != groupB)
			{
				cnt++;
				group[b] = groupA;
			}
		}

		int ans = cnt + (n - 1 - cnt) * 2;
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}