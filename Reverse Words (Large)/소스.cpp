#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	getchar();
	for (int t = 1; t <= tc; t++) {
		string str;
		getline(cin, str);

		int s = 0;
		stack<string> st;
		for (int i = 1; i <= str.length(); i++) {
			if (i == str.length() || str.at(i) == ' ') {
				st.push(str.substr(s, i - s));
				s = i + 1;
			}
		}

		cout << "Case #" << t << ": ";
		while (st.empty() == false) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << "\n";
	}
	return 0;
}