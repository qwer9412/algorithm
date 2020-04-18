#include<iostream>
#include<string>
using namespace std;
pair<string, int> timeStamp[100];
int main() {
	int cmdCnt;
	cin >> cmdCnt;

	for(int i=0 ; i<cmdCnt ; i++) {
		string cmd;
		string c;
		int pre;
		int t;

		cin >> cmd;
		if (cmd[0] == 't') {
			cin >> c >> t;

			if (i == 0) {
				timeStamp[0] = { c, t };
			}
			else {
				timeStamp[i] = { timeStamp[i - 1].first + c, t };
			}
		}
		else {
			cin >> pre >> t;
			int j;

			for (j = i - 1; j >= 0; j--) {
				if (timeStamp[j].second < t - pre) {
					break;
				}
			}

			if (j < 0) {
				timeStamp[i] = { "", t };
			}
			else {
				timeStamp[i] = { timeStamp[j].first, t };
			}
		}
	}

	cout << timeStamp[cmdCnt - 1].first;
	return 0;
}