#include<iostream>
using namespace std;
int main() {
	int x;
	int a, b;
	cin >> x;

	int sum = 0;
	
	for (int i = 1;; i++) {
		sum += i;

		if (x <= sum) {
			if (i % 2 == 0) {
				a = x - (sum - i);
				b = i + 1 - a;
			}
			else {
				b = x - (sum - i);
				a = i + 1 - b;
			}
			break;
		}
	}

	cout << a << '/' << b;
	return 0;
}