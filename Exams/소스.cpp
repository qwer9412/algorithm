/*
절반으로 나눈 후 이분탐색
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long arr[36];
vector<long long> v1, v2;
int main() {
	int n;
	long long t;
	int mid;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mid = n / 2;

	v1.push_back(0);
	for (int i = 0; i < mid; i++) {
		int len = v1.size();
		
		for (int j = 0; j < len; j++) {
			v1.push_back(v1[j] + arr[i]);
		}
	}

	sort(v1.begin(), v1.end());

	v2.push_back(0);
	for (int i = mid; i < n; i++) {
		int len = v2.size();
		
		for (int j = 0; j < len; j++) {
			v2.push_back(v2[j] + arr[i]);
		}
	}

	long long ans = 0;
	for (int i = 0; i < v2.size(); i++) {
		long long remain = t - v2[i];

		int pos = lower_bound(v1.begin(), v1.end(), remain) - v1.begin();

		ans += v1.size() - pos;
	}

	cout << ans;
	
	return 0;
}