#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int cnt[10];
int main()
{
	string n;
	cin >> n;

	for (int i = 0; i < n.length(); i++) {
		int num = n[i] - '0';
		cnt[num]++;
	}

	int max_value = 0;
	int max_not_69 = 0;
	for (int i = 0; i <= 9; i++) {
		if (max_value < cnt[i]) {
			max_value = cnt[i];
			
			if (i != 6 && i != 9)
				max_not_69 = max_value;
		}
	}

	int max69 = max(cnt[6], cnt[9]);
	int min69 = min(cnt[6], cnt[9]);
	int ans = max(max_not_69, max69 - (max69 - min69) / 2);

	cout << ans;
	return 0;
}