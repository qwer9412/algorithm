#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n;
	int ans[1000];
	queue<int> qu;

	cin >> n;
	for (int i = 0; i < n; i++)
		qu.push(i);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			qu.push(qu.front());
			qu.pop();
		}

		ans[qu.front()] = i;
		qu.pop();
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";

	return 0;
}