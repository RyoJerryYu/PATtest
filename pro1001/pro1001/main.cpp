#include <iostream>
using namespace std;
int main() {
	int n, count = 0;
	cin >> n;
	if (n == 0) {
		cout << count;
		return 0;
	}
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
			count++;
		}
		else {
			n = (3 * n + 1) / 2;
			count++;
		}
	}
	cout << count;
}