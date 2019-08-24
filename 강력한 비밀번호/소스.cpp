#include<iostream>
#include<algorithm>
using namespace std;
int chk[4]; //소 대 숫자 특수
char spc[12] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+' };
bool isSpecail(char c) {
	for (int i = 0; i < 12; i++) {
		if (c == spc[i])
			return true;
	}
	return false;
}
int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			chk[0] = 1;
		}
		else if ('A' <= s[i] && s[i] <= 'Z') {
			chk[1] = 1;
		}
		else if (isSpecail(s[i])) {
			chk[2] = 1;
		}
		else if ('0' <= s[i] && s[i] <= '9') {
			chk[3] = 1;
		}
	}
	cout << max(6 - n, 4 - chk[0] - chk[1] - chk[2] - chk[3]);
	return 0;
}