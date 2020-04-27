#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
pair<long long, long long> spend[100001];
pair<long long, long long> sum[100001];
int Time;
bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
	return a.second * b.first < b.second * a.first;
}
bool cmpFirst(pair<long long, long long> a, long long b)
{
	return a.first < b;
}
bool able(long long code, long long eat)
{
	int codeIdx = lower_bound(sum + 1, sum + Time + 1, code, cmpFirst) - sum;
	
	if (codeIdx > Time) {
		return false;
	}

	code -= sum[codeIdx - 1].first;
	eat -= (sum[Time].second - sum[codeIdx].second);

	if (code * spend[codeIdx].second + eat * spend[codeIdx].first <= spend[codeIdx].first * spend[codeIdx].second)
		return true;
	else
		return false;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++)
	{
		int day;
		scanf("%d %d", &day, &Time);

		for (int i = 1; i <= Time; i++)
		{
			scanf("%lld %lld", &spend[i].first, &spend[i].second);
		}

		sort(spend+1, spend + 1 + Time, cmp);
		for(int i=1;i<=Time;i++)
		{
			sum[i].first = sum[i - 1].first + spend[i].first;
			sum[i].second = sum[i - 1].second + spend[i].second;
		}

		printf("Case #%d: ", t);
		
		for (int i = 0; i < day; i++)
		{
			long long code, eat;
			scanf("%lld %lld", &code, &eat);
			
			if (able(code, eat) == true)
				printf("Y");
			else
				printf("N");
		}
		printf("\n");
	}

	return 0;
}